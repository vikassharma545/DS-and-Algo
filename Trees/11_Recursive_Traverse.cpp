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

void Preorder(Tree_Node *p)
{
    if (p == NULL)
        return;

    cout << p->data << " ";
    Preorder(p->Lchild);
    Preorder(p->Rchild);
}

void Inorder(Tree_Node *p)
{
    if (p == NULL)
        return;

    Inorder(p->Lchild);
    cout << p->data << " ";
    Inorder(p->Rchild);
}

void Postorder(Tree_Node *p)
{
    if (p == NULL)
        return;

    Postorder(p->Lchild);
    Postorder(p->Rchild);
    cout << p->data << " ";
}

int main()
{
    root = new Tree_Node;
    Create(root);

    cout << "Preorder" << endl;
    Preorder(root);
    cout << endl;

    cout << "Inorder" << endl;
    Inorder(root);
    cout << endl;

    cout << "Postorder" << endl;
    Postorder(root);
    cout << endl;

    return 0;
}