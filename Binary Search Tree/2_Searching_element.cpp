// maximum comparison = height of tree
// order of time = log(n)

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

void Inorder(Tree_Node *p)
{
    if (p == NULL)
        return;

    Inorder(p->Lchild);
    cout << p->data << " ";
    Inorder(p->Rchild);
}

Tree_Node *Binary_Search_Recursive(Tree_Node *t, int key)
{
    if (t == NULL)
        return NULL;

    if (key == t->data)
        return t;
    else if (key < t->data)
        return Binary_Search_Recursive(t->Lchild, key);
    else
        return Binary_Search_Recursive(t->Rchild, key);
}

Tree_Node *Binary_Search_Iterative(Tree_Node *t, int key)
{
    while (t)
    {
        if (key == t->data)
            return t;

        else if (key < t->data)
            t = t->Lchild;
        else
            t = t->Rchild;
    }

    return NULL;
}

int main()
{
    root = new Tree_Node;
    Create(root);

    cout << "Inorder" << endl;
    Inorder(root);
    cout << endl;

    int key;
    char c = 'y';
    do
    {
        cout << "Entre element to search : ";
        cin >> key;

        if (Binary_Search_Recursive(root, key))
            cout << "Element Found (Binary Search) : " << Binary_Search_Recursive(root, key)->data << endl;
        else
            cout << "Element Not Found" << endl;


        if (Binary_Search_Iterative(root, key))
            cout << "Element Found (Iterative Serach) : " << Binary_Search_Iterative(root, key)->data << endl;
        else
            cout << "Element Not Found" << endl;

        cout << "Search again(y/n) : ";
        cin >> c;
    } while (c == 'y');

    return 0;
}