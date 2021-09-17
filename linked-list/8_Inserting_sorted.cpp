#include <iostream>
using namespace std;

class Node
{
public:
    int Data;
    Node *Next;
} *Head = NULL, *Last2 = NULL;

void Display(Node *p)
{
    while (p)
    {
        cout << p->Data << " ";
        p = p->Next;
    }
    cout << endl;
}

void Insert(Node *p, int data)
{
    Node *New_Node = new Node;
    New_Node->Data = data;
    New_Node->Next = NULL;

    Node *tail_ptr = NULL;

    if (p == NULL)
        Head = New_Node;

    else
    {
        while (p && p->Data < data)
        {
            tail_ptr = p;
            p = p->Next;
        }
        if (p == Head)
        {
            New_Node->Next = Head;
            Head = New_Node;
        }
        else
        {
            New_Node->Next = tail_ptr->Next;
            tail_ptr->Next = New_Node;
        }
    }
}

int main()
{
    Insert(Head, 5);
    Insert(Head, 15);
    Insert(Head, 2);
    Insert(Head, 1);
    Display(Head);
}