// two ways
// 1. by reversing element only, node will be same through creating a temporary array
// 2. by reversing links

#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
} *Head = NULL, *Last2 = NULL;

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

void Reverse_Display(Node * p)
{
    if(p->Next)
        p = p->Next;
    cout << p->Data << " ";
}

void Reverse_element(Node *p)
{
    Node *temp = p;
    int *arr = new int[Count(p)];
    int i = 0;
    while (temp)
    {
        arr[i++] = temp->Data;
        temp = temp->Next;
    }

    temp = p;
    i--;
    while (p)
    {
        p->Data = arr[i--];
        p = p->Next;
    }

    delete[] arr;
}


void Reverse_Linking(Node *&head_ref)
{
    // Initially Sliding Pointers
    Node *p = head_ref; // First pointer
    Node *q = NULL;     // Middle pointer
    Node *r = NULL;     // Last pointer

    while (p)
    {
        // sliding as usual
        r = q;
        q = p;
        p = p->Next;

        // point middle next to last
        q->Next = r; 
    }

    head_ref = q; // at lastly head = middle;
}

void Reverse_Linking_recursion(Node *q, Node *p)
{
    if (p)
    {
        Reverse_Linking_recursion(p, p->Next);
        p->Next = q;
    }
    else
        Head = q;
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
    Reverse_element(Head);
    Reverse_Linking(Head);
    Reverse_Linking_recursion(NULL, Head);
    Display(Head);

    return 0;
}
