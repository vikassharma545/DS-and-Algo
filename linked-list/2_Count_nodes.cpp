#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
} *Head = NULL, *Last = NULL;

int Counting_Recursion(Node *p)
{
    if (p)
        return Counting_Recursion(p->Next) + 1;
    else
        return 0;
}

int Counting_Tranverse(Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->Next;
    }
    return count;
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

    // Counting Nodes
    cout << "size : " << Counting_Tranverse(Head) << endl;

    // Recursive
    cout << "size : " << Counting_Recursion(Head) << endl;
}
