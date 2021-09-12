// circular double linked list consider best linked list
// java use it as a default linked list 
// c++ use singlular linked list 
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

class Circular_Doubly_Linked_List
{
private:
    Node *head;

public:
    Circular_Doubly_Linked_List()
    {
        this->head = NULL;
    }

    int length()
    {
        Node *temp = this->head;
        int count = 0;

        if (temp == NULL)
        {
            return 0;
        }

        do
        {
            count++;
            temp = temp->next;
        } while (temp != this->head);

        return count;
    }

    void Display()
    {
        if (this->head == NULL)
        {
            cout << "Linked List Empty !!!" << endl;
            return;
        }

        Node *temp = this->head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != this->head);
        cout << endl;
    }

    void Insert(int index, int data)
    {
        if (index < 0 || index > this->length())
        {
            cout << "Invalid Index !!!" << endl;
            return;
        }

        Node *new_node = new Node;
        new_node->data = data;

        if (index == 0)
        {
            if (this->head == NULL) // if linked list empty
            {
                this->head = new_node;             // head node = new node
                this->head->previous = this->head; // head - previous = NULL initially
                this->head->next = this->head;     // head - next = NULL initially
            }
            else
            {
                // Note :- no need to traverse upto last node i.e  Last node = head->previous

                (this->head->previous)->next = new_node; // last node next = new node
                new_node->next = this->head;             // new node next = first node

                new_node->previous = (this->head->previous); // new node previous = last node
                (this->head->previous) = new_node;           // head previous = new node

                this->head = new_node; // now head node change to = new node
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

            //change next pointers
            new_node->next = traverse->next;
            traverse->next = new_node;

            //change previous pointers
            new_node->previous = traverse;
            (new_node->next)->previous = new_node;
        }
    }

    int Delete(int index) // here index is number of given node to be delete
    {
        int retrn = -1;

        if (index <= 0 || index > this->length())
        {
            cout << "Invalid Index !!!" << endl;
            return retrn;
        }

        Node *temp = this->head;

        if (index == 1) // index 1 --> first node
        {
            retrn = this->head->data;

            if (this->head->next == this->head) // if only one node in linked list
            {
                delete this->head;
                this->head = NULL;
            }
            else
            {
                head->previous->next = head->next;
                head->next->previous = head->previous;
                this->head = head->next;
                delete temp;
            }
        }
        else
        {
            for (int i = 0; i < index - 1; i++) // traverse to node to be deleted
            {
                temp = temp->next;
            }

            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;

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

            if (p->next == this->head) // when it reach last node i.e last-next = head
            {
                p->next = p->previous;
                p->previous = this->head;
                this->head = p;
                break;
            }
        }
    }
};

int main()
{
    Circular_Doubly_Linked_List obj;

    obj.Insert(0, 10);
    obj.Insert(1, 20);
    obj.Insert(2, 30);
    obj.Insert(3, 40);
    obj.Insert(4, 50);
    obj.Insert(5, 60);
    obj.Insert(6, 70);

    obj.Delete(1);
    obj.Delete(2);
    obj.Delete(3);

    obj.Display();
    obj.reverse();
    obj.Display();

    return 0;
}