// stack use LIFO principal -->  Last-In  First-Out
// insert and remove from same side
// we can not insert and get element from random position
// we use stack to change recurtion into iterative and vise-versa

#include <iostream>
using namespace std;

class Stack
{
private:
    int *stack;
    int size;
    int top;

public:
    Stack()
    {
        this->top = -1;

        cout << "Entre the size of Stack : ";
        cin >> this->size;

        this->stack = new int[size];
    }

    ~Stack()
    {
        delete[] this->stack;
    }

    bool isEmpty();
    bool isFull();
    void Push(int data);
    void Pop();
    int Peek(int position); // here position not mean index of array
    int Top();
    int Size();
};

bool Stack ::isEmpty()
{
    return (this->top == -1) ? true : false;
}

bool Stack::isFull()
{
    return (this->top == this->size - 1) ? true : false;
}

void Stack ::Push(int data)
{
    if (this->top == this->size - 1)
        cout << "Stack Overflow" << endl;
    else
        this->stack[++this->top] = data;
}

void Stack ::Pop()
{
    if (this->top == -1)
        cout << "Stack Underflow" << endl;
    else
        this->top--;
}

int Stack ::Peek(int position) // index of array = ( top - psition + 1 )
{
    if (this->top - position + 1 < 0)
    {
        cout << " Invalid Position" << endl;
        return -1;
    }
    else
        return this->stack[this->top - position + 1];
}

int Stack ::Top()
{
    if (this->top == -1)
        return -1;
    return this->stack[this->top];
}

int Stack ::Size()
{
    return this->size;
}

int main()
{
    Stack s1;
    cout << s1.isEmpty() << endl;
    s1.Push(10);
    s1.Push(20);
    s1.Push(30);
    s1.Push(40);
    s1.Push(50);
    cout << s1.isEmpty() << endl;

    for (int i = 1; i <= s1.Size(); i++)
    {
        cout << s1.Peek(i) << " ";
    }

    return 0;
}