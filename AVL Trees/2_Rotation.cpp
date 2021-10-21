#include <iostream>
#include <cmath>
using namespace std;

class Tree_Node
{
public:
    Tree_Node *Lchild;
    int data;
    int hight;
    Tree_Node *Rchild;

    Tree_Node()
    {
        this->Lchild = NULL;
        this->Rchild = NULL;
        this->data = 0;
        this->hight = 1;
    }
} *root = NULL;

int NodeHeight(Tree_Node *p)
{
    int hl, hr;
    hl = (p && p->Lchild) ? p->Lchild->hight : 0;
    hr = (p && p->Rchild) ? p->Rchild->hight : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int Balanced_Factor(Tree_Node *p)
{
    int hl, hr;
    hl = (p && p->Lchild) ? p->Lchild->hight : 0;
    hr = (p && p->Rchild) ? p->Rchild->hight : 0;

    return hl - hr;
}

Tree_Node *LL_Rotation(Tree_Node *p)
{
    Tree_Node *pl = p->Lchild;
    Tree_Node *plr = pl->Rchild;

    pl->Rchild = p;
    p->Lchild = plr;
    p->hight = NodeHeight(p);
    pl->hight = NodeHeight(pl);

    if (root == p)
        root = pl;

    return pl;
}

Tree_Node *LR_Rotation(Tree_Node *p)
{
    Tree_Node *pl = p->Lchild;
    Tree_Node *plr = pl->Rchild;

    pl->Rchild = plr->Lchild;
    p->Lchild = plr->Rchild;

    plr->Lchild = pl;
    plr->Rchild = p;

    pl->hight = NodeHeight(pl);
    p->hight = NodeHeight(p);
    plr->hight = NodeHeight(plr);

    if (root == p)
        root = plr;

    return plr;
}

Tree_Node *RR_Rotation(Tree_Node *p)
{
    Tree_Node *pr = p->Rchild;
    Tree_Node *prl = pr->Lchild;

    pr->Lchild = p;
    p->Rchild = prl;
    p->hight = NodeHeight(p);
    pr->hight = NodeHeight(pr);

    if (root == p)
        root = pr;

    return pr;
}

Tree_Node *RL_Rotation(Tree_Node *p)
{
    Tree_Node *pr = p->Rchild;
    Tree_Node *prl = pr->Lchild;

    pr->Lchild = prl->Rchild;
    p->Rchild = prl->Lchild;

    prl->Lchild = p;
    prl->Rchild = pr;

    prl->hight = NodeHeight(prl);
    p->hight = NodeHeight(p);
    pr->hight = NodeHeight(pr);

    if (root == p)
        root = prl;

    return prl;
}

Tree_Node *insert(Tree_Node *p, int key)
{
    Tree_Node *t;
    if (p == NULL)
    {
        t = new Tree_Node;
        t->data = key;
        return t;
    }

    if (key < p->data)
        p->Lchild = insert(p->Lchild, key);
    else if (key > p->data)
        p->Rchild = insert(p->Rchild, key);

    p->hight = NodeHeight(p);

    if (Balanced_Factor(p) == 2 && Balanced_Factor(p->Lchild) == 1)
        return LL_Rotation(p);
    else if (Balanced_Factor(p) == 2 && Balanced_Factor(p->Lchild) == -1)
        return LR_Rotation(p);
    else if (Balanced_Factor(p) == -2 && Balanced_Factor(p->Rchild) == -1)
        return RR_Rotation(p);
    else if (Balanced_Factor(p) == -2 && Balanced_Factor(p->Rchild) == 1)
        return RL_Rotation(p);
    else
        return p;
}

void Inorder(Tree_Node *p)
{
    if (p == NULL)
        return;

    Inorder(p->Lchild);
    cout << p->data << " ";
    Inorder(p->Rchild);
}

void print2D(Tree_Node *root, int space)
{
    if (root == NULL)
        return;

    static int COUNT = 7;

    space += COUNT;

    print2D(root->Rchild, space);
    cout << endl;

    for (int i = COUNT; i < space; i++)
        cout << " ";

    cout << root->data << endl;

    print2D(root->Lchild, space);
}

int main()
{
    root = insert(root, 10);
    insert(root, 30);
    insert(root, 20);
    insert(root, 60);
    insert(root, 35);
    insert(root, 50);
    insert(root, 40);
    insert(root, 25);
    insert(root, 10);

    Inorder(root);
    cout << endl;

    print2D(root, 0);

    cout << "minimum height = " << (int(log2(9))) << endl;
    cout << "node height = " << NodeHeight(root) - 1 << endl;
    return 0;
}