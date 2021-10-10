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
            if ((pre[i] > p->data) && (pre[i] < s.empty() ? 32767 : s.top()->data))
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
    int preorder[10] = {30, 20, 10, 15, 25, 40, 50, 45};

    CreatePre(preorder, 8);
    Inorder(root);
    cout << endl;
    cout << "Height = " << height(root) << endl;
    return 0;
}