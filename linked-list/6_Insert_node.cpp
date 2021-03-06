// Insert three ways
// 1. Before First Node
// 2. after given index
// 3. after last Node  // --> it include in after given index funtion both have same procedure

#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
} *Head = NULL, *Last2 = NULL;

void Display(Node *p)
{
    while (p)
    {
        cout << p->Data << " ";
        p = p->Next;
    }
    cout << endl;
}

// void Insert_At_first(Node **head_reference, int data) // pointer pass as a address, change (head_reference) --> (*head_reference) inside function
void Insert_At_first(Node *&head_reference, int data) // pointer pass as a reference
{
    cout << "Inserting... " << data << ", At first" << endl;

    //create a node
    Node *p = new Node;
    p->Data = data;

    //procedure
    p->Next = head_reference;
    head_reference = p;
}

void Insert_after_index(Node *head_reference, int index, int data) // pointer pass as a value but its data and,
{                                                                  //  next pointer have same location so it change according to parameter
    cout << "Inserting... " << data << ", After index " << index << endl;

    //create a node for tranverse
    Node *temp = new Node;

    //tranverse to given index
    temp = head_reference;
    for (int i = 0; i < index; i++)
        temp = temp->Next;

    // create a node
    Node *q = new Node;
    q->Data = data;

    //procedure
    q->Next = temp->Next;   // it also work on last index because that time temp-> point to last node i.e temp->next = NULL
    temp->Next = q;         // so it work like a q->next = NULL 
}

void Insert_At_Last(Node *head_reference, int data)
{
    cout << "Inserting... " << data << ", At Last" << endl;

    // create a node for tranverse
    Node *temp = head_reference;

    //tranverse to last index
    while (temp->Next) // you can use Last pointer instead of tranverse for save time
    {
        temp = temp->Next;
    }

    // create a Node
    Node *q = new Node;
    q->Data = data;
    q->Next = NULL;

    //procedure
    temp->Next = q;
}

// You can combine all function as you want using adding condition
// you can also add condition in 2nd funtion so it give no runtime error, of index that is not present

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

    Insert_At_first(Head, 10); // insert at index zero

    Insert_after_index(Head, 0, 66); // insert after index zero

    Insert_At_Last(Head, 66); // insert at last

    Display(Head);

    return 0;
}