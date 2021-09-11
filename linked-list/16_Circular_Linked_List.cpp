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
    do // traverse, upto temp not equal to head
    {  // use do while so it start from true
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

int length(Node *p)
{
    Node *temp = p;
    int count = 0;

    if (temp == NULL)
    {
        return 0;
    }

    do
    {
        temp = temp->Next;
        count++;
    } while (temp != p);

    return count;
}

void Insert(Node *&p, int index, int data)
{
    if (index < 0 || index > length(p)) // if index is less then zero or greater then  number of nodes (elements)
    {
        cout << "Invalid index" << endl;
        return;
    }

    Node *temp = new Node;
    temp->Data = data;
    temp->Next = NULL;
    Node *traverse = p;

    if (index == 0)
    {
        if (p == NULL)
        {
            p = temp;
            p->Next = p; // because it circular it point itself
        }
        else
        {
            while (traverse->Next != p) // traverse to last node
            {
                traverse = traverse->Next;
            }
            traverse->Next = temp; // last node next = new node
            temp->Next = p;        // new node next = first node

            // apply if you want make new node first other wise it become last ( no effect)
            p = temp; // first node pointer = new node
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            traverse = traverse->Next;
        }

        temp->Next = traverse->Next;
        traverse->Next = temp;
    }
}

int Delete(Node *&p, int index)
{
    int retrn = -1;
    
    if (index <= 0 || index > length(p)) // if index is less then zero or greater then  number of nodes (elements)
    {
        cout << "Invalid index" << endl;
        return retrn;
    }


    Node *temp = p;
    Node *front_tail;

    if (index == 1) // index 1 --> first node
    {

        while (temp->Next != p)
        {
            temp = temp->Next;
        }

        if (temp == p)
        {
            retrn = p->Data;
            delete p;
            p = NULL;
            return retrn;
        }
        else
        {
            temp->Next = p->Next;
            retrn = p->Data;
            delete p;
            p = temp->Next;
            return retrn;
        }
    }
    else
    {
        for (int i = 0; i < index - 2; i++)
        {
            temp = temp->Next;
        }

        front_tail = temp->Next;
        temp->Next = front_tail->Next;
        retrn = front_tail->Data;
        delete front_tail;
        front_tail = NULL;
        return retrn;
    }
}

int main()
{
    // create linked list

    // Node *Temp = NULL;

    // for (int i = 0; i < 10; i++) // size of linked list --> 10
    // {
    //     Temp = new Node;
    //     cin >> Temp->Data;
    //     Temp->Next = NULL;
    //     if (Head == NULL)
    //         Head = Last = Temp; // -> initial last node is Head Node
    //     else
    //     {
    //         Last->Next = Temp;
    //         Last = Temp;
    //     }
    // }

    // Last->Next = Head; /// it make linear list into circular linked list

    Insert(Head, 0, 10);
    Insert(Head, 1, 20);
    Insert(Head, 2, 30);
    Insert(Head, 3, 40);
    Insert(Head, 4, 50);

    Delete(Head,1);
    Delete(Head,4);
    // Insert(Head, 7, 30);
    // Insert(Temp,0,10);
    // Insert(Temp,0,10);
    // Insert(Temp,0,10);
    // Insert(Temp,0,10);
    // Insert(Temp,0,10);
    Display_Transverse(Head);
    // Display_Recursion(Head);
}
