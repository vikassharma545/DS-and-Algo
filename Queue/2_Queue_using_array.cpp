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
        this->front = this->rear = -1;    // initially front and rear at -1
    }

    bool isEmpty()
    {
        return (this->front == this->rear) ? true : false;
    }

    bool isFull()
    {
        return (this->rear == this->size - 1) ? true : false;
    }

    void enqueue(int data)
    {
        if (this->rear == this->size - 1)
            cout << "Queue Full !!" << endl;
        else
            this->queue[++this->rear] = data;
    }

    int dequeue()
    {
        int x = -1;
        if (this->front == this->rear)
            cout << "Queue Empty !!" << endl;
        else
            x = this->queue[++this->front];

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
    obj.enqueue(10);
    obj.enqueue(10);
    obj.enqueue(10);
    obj.enqueue(10);
    obj.enqueue(10);
    obj.enqueue(10);
    
    while (!obj.isEmpty())
    {
        cout << obj.dequeue() << endl;
    }

    obj.enqueue(55); 

    return 0;
}