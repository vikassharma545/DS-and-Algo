// you can you this function for binary search
// but we not consider binary search in linked list
// because it take order of n*log(1/n)
// or linear search take order of n

#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
} *Head = NULL, *Last = NULL;

int Counting(Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->Next;
    }
    return count;
}

Node *Middle(Node *head_ref)
{
    Node *p, *q;
    p = q = head_ref;
    while (q)
    {
        q = q->Next;

        if (q)
            q = q->Next;
        if (q)
            p = p->Next;
    }
    return p;
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

    Node *p, *q;
    p = q = Head;

    cout << "Middle : " << Middle(Head)->Data << endl;
}
