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

    if (!temp)
    {
        cout << "Linked List Empty !!" << endl;
        return;
    }

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
        count++;
        temp = temp->Next;
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

    Node *new_node = new Node;
    new_node->Data = data;
    new_node->Next = NULL;
    Node *traverse = p;

    if (index == 0)
    {
        if (p == NULL) // if linked list is empty
        {
            p = new_node;
            p->Next = p; // because it circular it point itself initially
        }
        else
        {
            while (traverse->Next != p) // traverse to last node
            {
                traverse = traverse->Next;
            }

            traverse->Next = new_node; // last node next = new node
            new_node->Next = p;        // new node next = first node

            // apply if you want make new node first other wise it become last ( no effect)
            p = new_node; // now head node change to = new node
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            traverse = traverse->Next; // traverse to that node, after given index came
        }

        new_node->Next = traverse->Next;
        traverse->Next = new_node;
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
        retrn = p->Data;

        if (temp->Next == p)
        {
            delete p;
            p = NULL; // need to be Null otherwise garabge value stored
        }
        else
        {
            while (temp->Next != p) // traverse upto last node
            {
                temp = temp->Next;
            }

            temp->Next = p->Next; // last node next = first node next
            delete p;             // delete first node
            p = temp->Next;       // move first node forward (i.e after last node)
        }

        return retrn;
    }
    else
    {
        for (int i = 0; i < index - 2; i++)
        {
            temp = temp->Next; // traverse upto one node before deleting node
        }

        front_tail = temp->Next;
        temp->Next = front_tail->Next;
        retrn = front_tail->Data;
        delete front_tail;

        // you can also use this method
        // Node *tail_ptr = NULL;
        // for (int i = 0; i < index - 1; i++)
        // {
        //     tail_ptr = temp;
        //     temp = temp->Next;
        // }
        // tail_ptr->Next = temp->Next;
        // retrn = temp->Data;
        // delete temp;

        return retrn;
    }
}

int main()
{
    Insert(Head, 0, 10);
    Insert(Head, 1, 20);
    Insert(Head, 2, 30);
    Insert(Head, 3, 40);
    Insert(Head, 4, 50);

    Delete(Head, 2);

    Display_Transverse(Head);

    // Display_Recursion(Head);
}
