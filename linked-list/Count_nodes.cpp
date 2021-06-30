#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
};

int Counting(struct Node * p){
    if (p)
        return Counting(p->Next) + 1;
    else    
        return 0;
}

int main()
{
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

    // Counting Nodes

    int count = 0;
    Temp = Head;

    cout << "vikas";
    while (Temp)
    {
        count++;
        Temp = Temp->Next;
    }


    cout<<count<<endl;

    // Recursive
    cout<<Counting(Head)<<endl;
}
