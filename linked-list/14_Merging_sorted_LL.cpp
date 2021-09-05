// Both linked list should be sorted
#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
} *Head1 = NULL, *Last1 = NULL, *Head2 = NULL, *Last2 = NULL;

void Display(Node *p)
{
    Node *temp = p;
    while (temp)
    {
        cout << temp->Data << " ";
        temp = temp->Next;
    }
    cout << endl;
}

Node *Merging(Node *p, Node *&q)
{
    // crete pointer for return for new head pointer
    Node *retrn = NULL;
    Node *last = NULL;

    // initially
    if (p->Data < q->Data)
    {
        retrn = last = p;
        p = p->Next;
        last->Next = NULL;
    }
    else
    {
        retrn = last = q;
        q = q->Next;
        last->Next = NULL;
    }

    while (p && q)
    {
        if (p->Data < q->Data)
        {
            last->Next = p;
            last = p;
            p = p->Next;
            last->Next = NULL;
        }
        else
        {
            last->Next = q;
            last = q;
            q = q->Next;
            last->Next = NULL;
        }
    }

    // remaning nodes
    if (p)
    {
        last->Next = p;
    }
    else if (q)
    {
        last->Next = q;
    }

    return retrn;
}

int main()
{
    // create linked list

    Node *Temp1;

    cout << "First" << endl;
    for (int i = 0; i < 5; i++) // size of linked list --> 5
    {
        Temp1 = new Node;
        cin >> Temp1->Data;
        Temp1->Next = NULL;
        if (Head1 == NULL)
            Head1 = Last1 = Temp1; // -> initial last node is Head1 Node
        else
        {
            Last1->Next = Temp1;
            Last1 = Temp1;
        }
    }

    Node *Temp2;

    cout << "Second" << endl;
    for (int i = 0; i < 5; i++) // size of linked list --> 5
    {
        Temp2 = new Node;
        cin >> Temp2->Data;
        Temp2->Next = NULL;
        if (Head2 == NULL)
            Head2 = Last2 = Temp2; // -> initial last node is Head1 Node
        else
        {
            Last2->Next = Temp2;
            Last2 = Temp2;
        }
    }

    Display(Head1);
    Display(Head2);

    Node *Head3 = Merging(Head1, Head2);
    Display(Head3);
    Display(Head1);   // why head1 linkedlist change ?? --> see parameter_passing.cpp
    Display(Head2);

    return 0;
}