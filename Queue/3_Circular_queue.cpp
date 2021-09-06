#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *queue;

public:
    Queue(int size)
    {
        this->size = size;
        this->queue = new int[this->size];
        this->front = this->rear = 0; // intially index was zero (0) i.e no element at index zero intially
    }

    bool isEmpty()
    {
        return (this->front == this->rear) ? true : false;
    }

    bool isFull()
    {
        return (((this->rear + 1) % this->size) == this->front) ? true : false;
    }

    void enqueue(int data)
    {
        if (((this->rear + 1) % this->size) == this->front)
            cout << "Queue Full !!" << endl;
        else
        {
            this->rear = (this->rear + 1) % this->size;
            this->queue[this->rear] = data;
        }
    }

    int dequeue()
    {
        int x = -1;
        if (this->front == this->rear)
            cout << "Queue Empty !!" << endl;
        else
        {
            this->front = (this->front + 1) % this->size;
            x = this->queue[this->front];
        }

        return x;
    }
};

int main()
{
    Queue obj(10);

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