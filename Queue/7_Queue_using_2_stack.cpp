#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        this->top = NULL;
    }

    ~Stack()
    {
        Node *p = top;
        while (this->top)
        {
            this->top = this->top->next;
            delete p;
            p = top;
        }
    }

    bool isEmpty(); //--> if top is null
    void Push(int data);
    int Pop();
};

bool Stack ::isEmpty()
{
    return (this->top == NULL) ? true : false;
}

void Stack ::Push(int data) // work even with stack is empty
{
    Node *temp = new Node;

    if (temp == NULL)
        cout << "Stack Overflow" << endl;
    else
    {
        temp->data = data;
        temp->next = this->top;
        this->top = temp;
    }
}

int Stack ::Pop()
{
    Node *p;
    int retrn;
    if (this->top == NULL)
        cout << "Stack Underflow" << endl;
    else
    {
        p = this->top;
        this->top = this->top->next;
        retrn = p->data;
        delete p;
    }
    return retrn;
}

class Queue
{
private:
    Stack s1;
    Stack s2;

public:
    bool isEmpty()
    {
        if (this->s1.isEmpty() && this->s2.isEmpty())
            return true;
        else
            return false;
    }

    void enqueue(int data)
    {
        s1.Push(data);
    }

    int dequeue()
    {
        int x = -1;

        if (s2.isEmpty())
        {
            if (s1.isEmpty())
            {
                cout << "Queue Empty !!" << endl;
                return x;
            }
            else
            {
                while (!s1.isEmpty())
                {
                    s2.Push(s1.Pop());
                }
            }
        }
        return s2.Pop();
    }
};

int main()
{
    Queue obj;

    obj.enqueue(10);
    obj.dequeue();
    obj.enqueue(20);
    obj.enqueue(30);
    obj.dequeue();
    obj.enqueue(40);
    obj.enqueue(50);
    obj.dequeue();
    obj.enqueue(60);
    obj.enqueue(70);
    obj.dequeue();
    obj.enqueue(80);
    obj.enqueue(90);
    obj.dequeue();
    obj.enqueue(100);

    while (!obj.isEmpty())
    {
        cout << obj.dequeue() << endl;
    }

    return 0;
}