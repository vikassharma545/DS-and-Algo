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
        this->top = nullptr;
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
    bool isFull();  //-->  linked list stack only full when heap memory is full i.e unable to create any pointer
    void Push(int data);
    int Pop();
    int Peek(int position);
    int Top();
};

bool Stack ::isEmpty()
{
    return this->top ? true : false;
}

bool Stack ::isFull()
{
    Node *temp = new Node;
    bool b = temp ? true : false;
    delete temp;
    return b;
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

int Stack ::Peek(int position)
{
    Node *temp = this->top;

    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp)
        return temp->data;
    return -1;
}

int Stack ::Top()
{
}

int main()
{
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Push(40);
    s.Push(50);
    s.Push(60);
    s.isEmpty();
    s.isFull();

    for (int i = 1; i <= 5; i++)
    {
        cout << s.Peek(i) << " ";
    }

    return 0;
}