// function we used in this program for Doubly Linked List
//  Length of LL
//  Display LL
//  Insert LL
//  Delete LL
//  Reverse LL

#include <iostream>
using namespace std;

class Node
{
public:
    Node *previous;
    int data;
    Node *next;

    Node()
    {
        this->previous = NULL;
        this->data = 0;
        this->next = NULL;
    }
};

class Double_Linked_List
{
private:
    Node *head;

public:
    Double_Linked_List()
    {
        this->head = NULL;
    }

    int length()
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void Display()
    {
        if (this->head == NULL)
        {
            cout << "Linked list Empty !!!" << endl;
            return;
        }

        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert(int index, int data)
    {
        if (index < 0 || index > this->length())
        {
            cout << "Invalid Index !!!" << endl;
            return;
        }

        Node *New_node = new Node;
        New_node->data = data;
        // new node previous and new node next = NULL auto using constructor

        if (index == 0)
        {
            if (this->head == NULL) // if linked list is empty
            {
                this->head = New_node;
                // head previous and head next initially NULL
            }
            else
            {
                New_node->next = this->head;     // new node next = first node
                this->head->previous = New_node; // head-previous = new node

                this->head = New_node; // now head change to = new node
            }
        }
        else
        {
            Node *traverse = this->head;

            for (int i = 0; i < index - 1; i++)
            {
                traverse = traverse->next; // traverse to that node, after given index came
            }

            // insert after traverse node

            // change next pointers
            New_node->next = traverse->next;
            traverse->next = New_node;

            // changes previous pointers
            New_node->previous = traverse;
            if (New_node->next != NULL) // if new node inserted is not last node ie (last-node-next = NULL)
                (New_node->next)->previous = New_node;
        }
    }

    int Delete(int index) // here index is number of given node to be delete
    {
        int retrn = -1;
        if (index <= 0 || index > this->length())
        {
            cout << "Invalid Index !!" << endl;
            return retrn;
        }

        Node *temp = this->head;

        if (index == 1) // index 1 --> first node
        {
            this->head = this->head->next; // also work if only one node in linkedlist i.e head->next = NULL that time
            this->head->previous = NULL;    
            delete temp;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next; // traverse to given index 
            }

            temp->previous->next = temp->next;

            if (temp->next) // if deleted node is not last node
            {
                temp->next->previous = temp->previous;
            }

            retrn = temp->data;
            delete temp;    
        }
        return retrn;
    }

    void reverse() //reverse done by swapping privious pointer with next pointer of same node
    {
        Node *p = head;
        Node *temp;
        while (p)
        {
            temp = p->next;
            p->next = p->previous;
            p->previous = temp;
            p = p->previous;

            if (p->next == NULL) // when it reach last node i.e last-next = NULL
            {
                p->next = p->previous;
                p->previous = nullptr;
                this->head = p;
                break;
            }
        }
    }
};

int main()
{
    Double_Linked_List p;

    p.insert(0, 10);
    p.insert(1, 20);
    p.insert(2, 30);
    p.insert(3, 40);
    p.insert(4, 50);
    p.Display();

    p.Delete(5);
    p.Display();
    // p.Delete(4);
    // p.Display();
    p.Delete(3);
    p.Display();
    // p.Delete(2);
    // p.Display();
    p.Delete(1);
    p.Display();

    p.reverse();
    p.Display();
    return 0;
}