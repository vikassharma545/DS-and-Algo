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

bool Check_Sorted(Node *p)
{
    int temp = INT8_MIN;

    while (p)
    {
        if (p->Data < temp)
            return false;
        temp = p->Data;
        p = p->Next;
    }
    return true;
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

    if (Check_Sorted(Head))
        cout << "Linked list is sorted " << endl;
    else
        cout << "Not Sorted !!!" << endl;

    return 0;
}