// Iterative Traverse is done by using stack (for Backtracking)

#include <iostream>
#include <stack>
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

void Iterative_Preorder1(Tree_Node *t)
{
    stack<Tree_Node *> s;

    while (t || (!s.empty()))
    {
        if (t)
        {
            cout << t->data << " ";
            s.push(t);
            t = t->Lchild;
        }
        else
        {
            t = s.top();
            s.pop();
            t = t->Rchild;
        }
    }
}

void Iterative_Preorder2(Tree_Node *t)
{

    if (t == NULL)
        return;

    stack<Tree_Node *> s;
    s.push(t);

    while (!s.empty())
    {
        t = s.top();
        cout << t->data << " ";
        s.pop();

        if (t->Rchild)
            s.push(t->Rchild);

        if (t->Lchild)
            s.push(t->Lchild);
    }
}

void Iterative_Inorder(Tree_Node *t)
{
    stack<Tree_Node *> s;

    while (t || (!s.empty()))
    {
        if (t)
        {
            s.push(t);
            t = t->Lchild;
        }
        else
        {
            t = s.top();
            s.pop();
            cout << t->data << " ";
            t = t->Rchild;
        }
    }
}

void Iterative_Postorder1(Tree_Node *t)
{
    stack<Tree_Node *> s;

    do
    {
        while (t)
        {
            if (t->Rchild)
                s.push(t->Rchild);
            s.push(t);
            t = t->Lchild;
        }

        t = s.top();
        s.pop();

        if (!s.empty() && t->Rchild && (s.top() == t->Rchild))
        {
            s.pop();
            s.push(t);
            t = t->Rchild;
        }
        else
        {
            cout << t->data << " ";
            t = NULL;
        }

    } while (!s.empty());
}

void Iterative_Postorder2(Tree_Node *t)
{
    stack<Tree_Node *> s;

    do
    {
        while (t)
        {
            s.push(t);
            s.push(t);
            t = t->Lchild;
        }

        t = s.top();
        s.pop();

        if (!s.empty() && (s.top() == t))
            t = t->Rchild;

        else
        {
            cout << t->data << " ";
            t = NULL;
        }
    }while (!s.empty());
}

int main()
{
    root = new Tree_Node;
    Create(root);

    Iterative_Preorder1(root);
    cout << endl;

    Iterative_Preorder2(root);
    cout << endl;

    Iterative_Inorder(root);
    cout << endl;

    Iterative_Postorder1(root);
    cout << endl;

    Iterative_Postorder2(root);
    cout << endl;

    return 0;
}