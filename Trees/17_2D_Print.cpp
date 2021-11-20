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

    queue<Tree_Node *> q; // queue of Tree Node type for storing pointer

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

void print2D(Tree_Node *root, int space = 0)
{
    if (root == NULL)
        return;
    static int COUNT = 7;
    space += COUNT;
    print2D(root->Rchild, space);

    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    print2D(root->Lchild, space);
}

int main()
{
    root = new Tree_Node;
    Create(root);

    cout << "Inorder" << endl;
    Inorder(root);
    cout << endl;

    print2D(root);
    return 0;
}