#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
} *Head = NULL;

int Max(struct Node *p)
{
    int max = INT8_MIN;
    while (p)
    {
        if (p->Data > max)
            max = p->Data;
        p = p->Next;
    }
    return max;
}

int Min(struct Node *p)
{
    int min = INT8_MAX;
    while (p)
    {
        if (p->Data < min)
            min = p->Data;
        p = p->Next;
    }
    return min;
}

int main()
{

    Node *Last = NULL;
    Node *Temp;

    // create linked list

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

    cout << "Max : " << Max(Head) << endl;
    cout << "Min : " << Min(Head) << endl;
}