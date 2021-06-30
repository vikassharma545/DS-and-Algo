#include<iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
};

// Iteration type
int Add(struct Node *p){
    int sum = 0;
    while (p)
    {
        sum = sum + p->Data;
        p = p->Next;
    }
    return sum;
}

// Recurtion type
int AddR(struct Node * p){
    if (p)
        return AddR(p->Next) + p->Data;
    else    
        return 0;
}

int main(){

    Node *Head = new Node;

    Node *Last = new Node;

    Node *Temp;

    Head->Data = 1;
    Last = Head;

    // create linked list

    int i = 1;
    while (Last->Data)
    {
        if (i==1)
        {
            cin>>Head->Data;
            i--;
        }
        
        Temp = new Node;
        cin >> Temp->Data;
        Last->Next = Temp;
        Last = Temp;
    }

    cout<<Add(Head)<<endl;
    cout<<AddR(Head)<<endl;
}