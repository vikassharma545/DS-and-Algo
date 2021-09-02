#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
};

int count(Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->Next;
    }
    return count;
}

void Display(Node *p)
{
    while (p)
    {
        cout << p->Data << " ";
        p = p->Next;
    }
    cout << endl;
}

void Insert(Node **head_reference, int index, int data)
{
    Node *p = new Node;
    p->Data = data;
    if (index == 0)
    {
        p->Next = *head_reference;
        *head_reference = p;
    }
    else if (index > 0 && index <= count(*head_reference))
    {
        Node *temp = new Node;
        temp = *head_reference;
        for (int i = 0; i < index - 1; i++)
            temp = temp->Next;
        p->Next = temp->Next;
        temp->Next = p;
        temp = NULL;
        free(temp);
    }
    else
        cout << "Invalid Index!!!" << endl;
}

int main()
{
    int temp, size;
    cout << "Entre the size of linked list : ";
    cin >> size;
    cout << "Entre element of first linked list ..." << endl;

    Node *Head1 = NULL, *Head2 = NULL;

    for (int i = 0; i < size; i++)
    {
        cin >> temp;
        Insert(&Head1, i, temp);
    }

    cout << "Entre element of 2nd linked list ..." << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> temp;
        Insert(&Head2, i, temp);
    }

    cout << "printing first list..." << endl;
    Display(Head1);

    cout << "printing second list..." << endl;
    Display(Head2);

    return 0;
}
