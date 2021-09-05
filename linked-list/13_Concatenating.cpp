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

void Concat(Node *p, Node *q)
{
    while (p->Next)
    {
        p = p->Next;
    }
    p->Next = q;

    q = NULL;
}

int main()
{
    // create linked list

    Node *Temp1;

    cout << "First" << endl;
    for (int i = 0; i < 5; i++) // size of linked list --> 10
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
    for (int i = 0; i < 5; i++) // size of linked list --> 10
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

    Concat(Head1, Head2);
    Display(Head1);     // why head 1 change only ??
    Display(Head2);

    return 0;
}