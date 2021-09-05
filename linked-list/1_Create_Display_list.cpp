// #Create linked list

// -> first create node using struct

//     struct node
//     {
//         int data;      // variable for data
//         Node * next;   // pointer for next node (pointer type = node itself)
//     };

// -> create first node and Last node
//     Node *Head ;        // Head always pointing to First Node
//     Node *Last ;         // Last always pointing to last done

// -> create temp node
//     Node *Temp = new Node;           // Temp is Temporary Node (for transverse)

// -> initial last node is Head Node equal to temp node
//     Last = Head = Temp;

// after that

// -> pointing last node pointer to temp node
//     Last->next = Temp;

// -> make temp node as last now
//     Last = Temp;

#include <iostream>
using namespace std;

// create Node sturct

struct Node
{
    int Data;   // Data
    Node *Next; // pointer
} *Head = NULL, *Last2 = NULL;

void Display_Transverse(Node *p)
{
    while (p)
    {
        cout << p->Data << " ";
        p = p->Next;
    }
    cout << endl;
}

void Display_Recursion(Node *p)
{
    if (p)
    {
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
            Head = Last2 = Temp; // -> initial last node is Head Node
        else
        {
            Last2->Next = Temp;
            Last2 = Temp;
        }
    }

    // dislplay linked list
    Display_Transverse(Head);

    // Display using recursion
    Display_Recursion(Head);

    return 0;
}