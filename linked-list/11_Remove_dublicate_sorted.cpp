#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
} *Head = NULL, *Last2 = NULL;

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

void Remove_Dublicate(Node *p)
{
    Node *q = p->Next;

    while (q)
    {
        if (p->Data != q->Data)
        {
            p = q;
            q = q->Next;
        }
        else
        {
            p->Next = q->Next;
            // free(q);  --> also use instead of delete
            delete q;
            q = p->Next;
        }
    }
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
            Head = Last2 = Temp; // -> initial last node is Head Node
        else
        {
            Last2->Next = Temp;
            Last2 = Temp;
        }
    }

    Display(Head);
    Remove_Dublicate(Head);
    Display(Head);

    return 0;
}