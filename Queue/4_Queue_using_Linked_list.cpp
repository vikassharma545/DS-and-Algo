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

    void enqueue(int data)
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

    int dequeue()
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
};

int main()
{
    Queue obj;

    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(30);
    obj.enqueue(40);
    obj.enqueue(60);
    obj.enqueue(70);
    obj.enqueue(80);
    obj.enqueue(90);
    obj.enqueue(100);
    obj.enqueue(110);
    obj.enqueue(120);

    while (!obj.isEmpty())
    {
        cout << obj.dequeue() << endl;
    }

    obj.enqueue(5);
    obj.enqueue(10);
    obj.enqueue(15);
    obj.enqueue(20);
    obj.enqueue(25);
    obj.enqueue(30);

    while (!obj.isEmpty())
    {
        cout << obj.dequeue() << endl;
    }

    return 0;
}