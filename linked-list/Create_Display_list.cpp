// #Create linked list

// -> first create node using struct

//     struct node
//     {
//         int data;      // variable for data       
//         Node * next;   // pointer for next node (pointer type = node itself)
//     }

// -> create first node and Last node
//     Node *Head = new Node;           // Head always pointing to First Node
//     Node *Last = new Node;       

// -> initial last node is Head Node
//     Last = Head;                      // Last always pointing to last done

// -> create temp node 
//     Node *Temp = new Node;           // Temp is Temporary Node (for transverse)


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
};

void Display(struct Node * p){
    if (p)
    {
        cout<<p->Data<<" "<<endl;
        Display(p->Next);
    }
    

}

int main()
{
    Node *Head = new Node; 

    Node *Last = new Node; 

    Node *Temp;

    Head->Data = 1;
    Last = Head;   


// create linked list

    while (Last->Data)
    {
        Temp = new Node;
        cin >> Temp->Data;
        Last->Next = Temp;
        Last = Temp;
    }


// dislplay linked list

    Temp = Head;

    while (Temp)
    {
        cout << Temp->Data << endl;
        Temp = Temp->Next;
    }

// Display using recursion

    cout<<"Recurtion \n";
    Display(Head);

    return 0;
}