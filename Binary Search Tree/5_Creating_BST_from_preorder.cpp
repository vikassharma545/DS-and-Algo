// error
#include <iostream>
#include <stack>
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

void Inorder(Tree_Node *p)
{
    if (p == NULL)
        return;

    Inorder(p->Lchild);
    cout << p->data << " ";
    Inorder(p->Rchild);
}

void Preorder(Tree_Node *p)
{
    if (p == NULL)
        return;

    cout << p->data << " ";
    Inorder(p->Lchild);
    Inorder(p->Rchild);
}

void CreatePre(int pre[], int n)
{
    stack<Tree_Node *> s;

    Tree_Node *t, *p;

    int i = 0;

    t = new Tree_Node;
    t->data = pre[i++];
    root = t;
    p = t;

    while (i < n)
    {
        if (pre[i] < p->data)
        {
            t = new Tree_Node;
            t->data = pre[i++];
            p->Lchild = t;
            s.push(p);
            p = t;
        }
        else
        {
            if ((pre[i] > p->data) && (pre[i] < s.top()->data))
            {
                t = new Tree_Node;
                t->data = pre[i++];
                p->Rchild = t;
                p = t;
            }
            else
            {
                p = s.top();
                s.pop();
            }
        }
    }
}

int main()
{
    // int preorder[10] = {30, 20, 10, 15, 25, 40, 50, 45};
    int preorder[8] = {30, 10, 20, 15, 5,1};

    CreatePre(preorder, 6);
    // Preorder(root);
    // cout<<endl;
    Inorder(root);
    return 0;
}