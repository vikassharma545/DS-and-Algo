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

int main()
{
    root = new Tree_Node;
    Create(root);

    Level_traverse(root);
    cout << endl;

    return 0;
}