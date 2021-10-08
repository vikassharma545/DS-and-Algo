#include <iostream>
#include <queue>
using namespace std;

class Tree_Node
{
public:
    Tree_Node *Lchild;
    int data;
    Tree_Node *Rchild;

    Tree_Node()
    {
        this->Lchild = NULL;
        this->data = -1;
        this->Rchild = NULL;
    }
} *root = NULL;

void Create(Tree_Node *p)
{
    Tree_Node *Ptr, *new_node;

    int x;

    queue<Tree_Node *> q;

    cout << "Entre root value : ";
    cin >> x;

    p->data = x;
    q.push(p);
    while (!q.empty())
    {
        Ptr = q.front();
        q.pop();
        cout << "Entre left child of " << Ptr->data << " : ";
        cin >> x;
        if (x != -1)
        {
            new_node = new Tree_Node;
            new_node->data = x;
            Ptr->Lchild = new_node;
            q.push(new_node);
        }

        cout << "Entre right child of " << Ptr->data << " : ";
        cin >> x;
        if (x != -1)
        {
            new_node = new Tree_Node;
            new_node->data = x;
            Ptr->Rchild = new_node;
            q.push(new_node);
        }
    }
}

void Level_traverse(Tree_Node *t)
{
    queue<Tree_Node *> q;

    cout << t->data << " ";
    q.push(t);

    while (!q.empty())
    {
        t = q.front();
        q.pop();

        if (t->Lchild)
        {
            cout << t->Lchild->data << " ";
            q.push(t->Lchild);
        }
        if (t->Rchild)
        {
            cout << t->Rchild->data << " ";
            q.push(t->Rchild);
        }
    }
}

/*

    1. if degree 0 (leaf node)          :  if(!p->Lchild && !p->Rchild)

    2. if degree 2                      :  if(p->Lchild && p->Rchild)

    3. if degree 1 or 2 (internal node) :  if(p->Lchild || p->Rchild)

    4. if degree 1      :  if((p->Lchild && !p->Rchild) || (!p->Lchild && p->Rchild)) 
                                                    or
                                if((p->Lchild != NULL) ^ (p->Rchild != NULL))
*/

int Count_Node(Tree_Node *p)
{
    int x, y;
    if (p)
    {
        x = Count_Node(p->Lchild);
        y = Count_Node(p->Rchild);
        return x + y + 1;
    }
    return 0;
}

int Count_recursive(Tree_Node *p)
{
    return p ? (Count_recursive(p->Lchild) + Count_recursive(p->Rchild) + 1) : 0;
}

int Sum_of_Node_data(Tree_Node *p)
{
    int x, y;
    if (p)
    {
        x = Sum_of_Node_data(p->Lchild);
        y = Sum_of_Node_data(p->Rchild);
        return x + y + p->data;
    }
    return 0;
}

int Recursive_Sum_of_node_data(Tree_Node *p)
{
    return p ? Recursive_Sum_of_node_data(p->Lchild) + Recursive_Sum_of_node_data(p->Rchild) + p->data : 0;
}

int height(Tree_Node *p)
{
    int x, y;
    if (p)
    {
        x = height(p->Lchild);
        y = height(p->Rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}

int Height_Recursive(Tree_Node *p)
{
    // if (p == NULL)
    //     return 0;

    // if (Height_Recursive(p->Lchild) > Height_Recursive(p->Rchild))
    //     return Height_Recursive(p->Lchild) + 1;
    // else
    //     return Height_Recursive(p->Rchild) + 1;

    return p ? (Height_Recursive(p->Lchild) > Height_Recursive(p->Rchild)) ? Height_Recursive(p->Lchild) + 1 : Height_Recursive(p->Rchild) + 1 : 0;
}

int Count_Leaf_Node(Tree_Node *p)
{
    int x, y;
    if (p)
    {
        x = Count_Leaf_Node(p->Lchild);
        y = Count_Leaf_Node(p->Rchild);

        if (!p->Lchild && !p->Rchild) // for leaf node
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int Count_leaf_recursive(Tree_Node *p)
{
    return p ? (!p->Lchild && !p->Rchild) ? Count_leaf_recursive(p->Lchild) + Count_leaf_recursive(p->Rchild) + 1 : Count_leaf_recursive(p->Lchild) + Count_leaf_recursive(p->Rchild) : 0;
}

int main()
{
    root = new Tree_Node;
    Create(root);

    Level_traverse(root);
    cout << endl;

    cout << "Count Node  = " << Count_Node(root) << endl;
    cout << "Count Node  = " << Count_recursive(root) << endl;

    cout << "Height = " << height(root) << endl;
    cout << "Height = " << Height_Recursive(root) << endl;

    cout << "Sum of all data = " << Sum_of_Node_data(root) << endl;
    cout << "Sum of all data = " << Recursive_Sum_of_node_data(root) << endl;
    
    cout << "Leaf Node = " << Count_Leaf_Node(root) << endl;
    cout << "Leaf Node = " << Count_leaf_recursive(root) << endl;

    return 0;
}