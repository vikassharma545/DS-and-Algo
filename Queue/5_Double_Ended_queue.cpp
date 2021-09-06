// Double ended queue :  insertion and deletion from both end as you want
// input restricted double ended queue : insert allow only throw rear (default)
// output restricted double ended queue : delete allow only throw front (default)

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        this->front = this->rear = NULL;
    }

    bool isEmpty()
    {
        return (this->front == NULL) ? true : false;
    }

    bool isFull() // if heap memory is full
    {
        Node *t = new Node;
        return (t == NULL) ? true : false;
    }

    void enqueue_rear(int data) // default
    {
        Node *t = new Node;
        if (t == NULL)
            cout << "Queue Full !!" << endl;
        else
        {
            t->data = data;
            t->next = NULL;

            if (this->front == NULL)
                this->front = this->rear = t;
            else
            {
                this->rear->next = t;
                this->rear = t;
            }
        }
    }

    void enqueue_front(int data)
    {
        Node *t = new Node;
        if (t == NULL)
            cout << "Queue Full !!" << endl;
        else
        {
            t->data = data;
            t->next = NULL;

            if (this->front == NULL)
                this->front = this->rear = t;
            else
            {
                t->next = this->front;
                this->front = t;
            }
        }
    }

    int dequeue_front() // default
    {
        int x = -1;
        Node *t;

        if (this->front == NULL)
            cout << "Queue Empty !!" << endl;
        else
        {
            t = this->front;
            x = this->front->data;
            this->front = this->front->next;
            delete t;
        }

        return x;
    }

    int dequeue_rear()
    {
        int x = -1;

        if (this->front == NULL)
            cout << "Queue Empty !!" << endl;
        else
        {
            Node *t = this->front;
            Node *q = NULL;
            while (t->next)
            {
                q = t;
                t = t->next;
            }

            x = this->rear->data;
            
            if (q)
            {
                q->next = NULL;
                this->rear = q;
            }
            else
                this->front = this->rear = NULL;

            delete t;
        }

        return x;
    }
};

int main()
{
    Queue obj;

    obj.enqueue_front(10);
    obj.enqueue_front(20);
    obj.enqueue_front(30);
    obj.enqueue_front(40);
    obj.enqueue_front(50);
    obj.enqueue_front(60);
    obj.enqueue_front(70);
    obj.enqueue_front(80);

    while (!obj.isEmpty())
    {
        cout << obj.dequeue_rear() << endl;
    }

    return 0;
}