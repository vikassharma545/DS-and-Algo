// two way
// delete by given node index
// delete by given Node data

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

int Count(Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->Next;
    }
    return count;
}

void Delete(Node **head_reference, int index)
{
    Node *temp = new Node;
    temp = *head_reference;

    if (index < 0 || index > Count(*head_reference) - 1)
    {
        cout << "Invalid Index !!!" << endl;
    }
    else
    {
        cout << "Deleting... node of index " << index << endl;
        if (index == 0)
        {
            *head_reference = (*head_reference)->Next;
            delete temp;
        }
        else
        {
            Node *tail_ptr = NULL;
            for (int i = 0; i < index; i++)
            {
                tail_ptr = temp;
                temp = temp->Next;
            }

            tail_ptr->Next = temp->Next;
            delete temp;
        }
    }
}

void Delete_By_Data(Node **head_reference, int key)
{
    Node *temp = new Node;
    temp = *head_reference;

    if ((*head_reference)->Data == key)
    {
        cout << "Deleting... " << key << endl;
        *head_reference = (*head_reference)->Next;
        delete temp;
    }
    else
    {
        Node *tail_ptr = NULL;
        while (temp != NULL && temp->Data != key)
        {
            tail_ptr = temp;
            temp = temp->Next;
        }

        if (temp)
        {
            cout << "Deleting... " << key << endl;
            tail_ptr->Next = temp->Next;
            delete temp;
            return;
        }
        else
            cout << "No data found to delete !!! " << endl;
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

    Display(Head);
    Delete(&Head, 5);
    Delete_By_Data(&Head, 5);
    Delete_By_Data(&Head, 6);
    Display(Head);

    return 0;
}