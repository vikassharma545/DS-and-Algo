#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
} *Head = NULL, *Last = NULL;

void Display_Transverse(Node *p)
{
    Node *temp = p;
    do
    {
        cout << temp->Data << " ";
        temp = temp->Next;
    } while (temp != p);
    cout << endl;
}

void Display_Recursion(Node *p)
{
    static int flag = 0;
    if (p != Head || flag == 0)
    {
        flag = 1;
        cout << p->Data << " ";
        Display_Recursion(p->Next);
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
            Head = Last = Temp; // -> initial last node is Head Node
        else
        {
            Last->Next = Temp;
            Last = Temp;
        }
    }

    Last->Next = Head;

    Display_Transverse(Head);
    Display_Recursion(Head);
}
