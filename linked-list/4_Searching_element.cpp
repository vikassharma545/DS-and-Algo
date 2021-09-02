// Only Linear search
// binary search not applicable

#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
} *Head = NULL, *Last = NULL;

void Display(Node *p)
{
    while (p)
    {
        cout << p->Data << " ";
        p = p->Next;
    }
    cout << endl;
}

void Search1(Node *p, int key) // transverse
{
    while (p)
    {
        if (p->Data == key)
        {
            cout << "--Found--" << endl;
            return;
        }
        p = p->Next;
    }
    cout << "Not Found !!!" << endl;
}

void Search2(Node *p, int key) // recursion
{
    if (p == NULL)
        cout << "Not Found !!!" << endl;

    if (p->Data == key)
    {
        cout << "--Found--" << endl;
        return;
    }
    return Search2(p->Next, key);
}

//improve searching by move to head

void Search3(Node *p, int key) // move to head search
{
    Node *q = NULL;
    while (p)
    {
        if (p->Data == key)
        {
            q->Next = p->Next;
            p->Next = Head;
            Head = p;
            cout << "--Found--" << endl;
            return;
        }
        q = p;
        p = p->Next;
    }
    cout << "Not Found !!!" << endl;
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

    Search1(Head, 6);
    Search2(Head, 1);
    Search3(Head, 66);
    Search3(Head, 55);
    Search3(Head, 6);

    Display(Head);

    return 0;
}