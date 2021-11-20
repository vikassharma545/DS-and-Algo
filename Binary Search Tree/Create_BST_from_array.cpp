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

Tree_Node *insert_recursive(Tree_Node *p, int key)
{
    Tree_Node *t;
    if (p == NULL)
    {
        t = new Tree_Node;
        t->data = key;
        return t;
    }

    if (key < p->data)
        p->Lchild = insert_recursive(p->Lchild, key);
    else if (key > p->data)
        p->Rchild = insert_recursive(p->Rchild, key);

    return p;
}

void create(Tree_Node *&t, int arr[], int size)
{
    t = insert_recursive(t, arr[0]);
    for (int i = 1; i < size; i++)
        insert_recursive(t, arr[i]);
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
    int arr[] = {20, 15, 14, 18, 17, 7, 3, 5, 27, 25, 24, 30, 35, 29};
    int size = sizeof(arr) / sizeof(arr[0]);

    // create BST
    create(root, arr, size);

    print2D(root);
    return 0;
}