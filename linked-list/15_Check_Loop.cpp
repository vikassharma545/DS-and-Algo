#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
} *Head = NULL, *Last = NULL;

int isLoop(Node *head_ref)
{
    Node *p;
    Node *q;

    p = q = head_ref;

    do
    {
        p = p->Next;
        q = q->Next;
        q = q ? q->Next : q;
    } while (p && q && p != q);

    if (p == q)
        return 1;
    else
        return -1;
}

int main()
{
    // create linked list

    Node *Temp;

    for (int i = 0; i < 10; i++) // size of linked list --> 10
    {
        Temp = new Node;
        cin >> Temp->Data;
        Temp->Next = NULL;
        if (Head == NULL)
            Head = Last = Temp; // -> initial last node is Head Node
        else
        {
            Last->Next = Temp;
            Last = Temp;
        }
    }

    Last->Next = Head;    // make linked list loop

    cout<<isLoop(Head)<<endl;
}
