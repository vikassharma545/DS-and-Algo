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
    q->Next = temp->Next;
    temp->Next = q;
}

int Count(Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->Next;
    }
    return count;
}

void Insert_At_Last(Node *head_reference, int data)
{
    cout << "Inserting... " << data << ", At Last" << endl;

    // create a node for tranverse
    Node *temp = new Node;

    //tranverse to last index
    temp = head_reference;
    for (int i = 0; i < Count(head_reference) - 1; i++) // you can use Last pointer instead of tranverse for save time
        temp = temp->Next;

    // create a Node
    Node *q = new Node;
    q->Data = data;

    //procedure
    q->Next = temp->Next;
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
            Head = Last = Temp; // -> initial last node is Head Node
        else
        {
            Last->Next = Temp;
            Last = Temp;
        }
    }

    Insert_At_first(Head, 10);  // insert at index zero

    Insert_after_index(Head, 0, 66);  // insert after index zero

    Insert_At_Last(Head, 66);   // insert at last

    Display(Head);

    return 0;
}