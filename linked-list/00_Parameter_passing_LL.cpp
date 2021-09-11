// read it after or with programs 6 to 9 for better understanding
#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
} *Head = NULL;

void Display_Transverse(Node *p)
{
    while (p)
    {
        cout << p->Data << " ";
        p = p->Next;
    }
    cout << endl;
}

void Test(Node *Head_value, Node *&Head_reference, Node **Head_address)
{
    //printing head
    cout << "Printing head " << endl; // all output will same mean we can access value
    cout << Head_value << endl;       // of head through any parameter
    cout << Head << endl;
    cout << Head_reference << endl;
    cout << *Head_address << endl;

    //printing head address
    cout << "\n\nPrinting head address" << endl; // address of head_value are difference then other
    cout << &Head_value << endl;                 // mean we cannot change head pointer in function
    cout << &Head << endl;                       // by passing through value
    cout << &Head_reference << endl;
    cout << &*Head_address << endl;

    //prining head data and pointer address
    cout << "Data address" << endl;    // data and pointer address is same for all
    cout << &Head_value->Data << endl; // mean any change in data and pointer inside
    cout << &Head->Data << endl;       // function also reflect in original
    cout << &Head_reference->Data << endl;
    cout << &(*Head_address)->Data << endl;
    cout << "pointer address of head" << endl;
    cout << &Head_value->Next << endl;
    cout << &Head->Next << endl;
    cout << &Head_reference->Next << endl;
    cout << &(*Head_address)->Next << endl;

    // speacial case
    cout << "Speacial case" << endl;
    Node *temp = NULL;

    temp = Head_value;           // the two value are different, mean by changing temp pionter
    cout << &temp->Next << endl; // after temp = temp->next we actually cannot change actual
    temp = temp->Next;           // pointer
    cout << &temp << endl;       // this usefull in changing last pionter

    temp = Head_reference;       // then how change ??
    cout << &temp->Next << endl; // directly change temp->next = new pointer
    temp = temp->Next;           // not need temp = temp->next, temp = new pointer ---> wrong
    cout << &temp << endl;

    temp = *Head_address;
    cout << &temp->Next << endl;
    temp = temp->Next;
    cout << &temp << endl;
}

int main()
{

    Node *Last = NULL;
    Node *Temp;

    // create linked list

    for (int i = 0; i < 5; i++) // size of linked list --> 5
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

    Test(Head, Head, &Head);
}