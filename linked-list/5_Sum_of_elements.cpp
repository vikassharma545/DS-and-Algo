#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
} *Head = NULL, *Last = NULL;

int Add(struct Node *p) // Iteration type
{
    int sum = 0;
    while (p)
    {
        sum = sum + p->Data;
        p = p->Next;
    }
    return sum;
}

int AddR(struct Node *p) // Recurtion type
{
    if (p)
        return AddR(p->Next) + p->Data;
    else
        return 0;
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

    cout << "Sum : " << Add(Head) << endl;
    cout << "Sum : " << AddR(Head) << endl;
}