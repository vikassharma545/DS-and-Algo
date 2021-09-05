#include <iostream>
using namespace std;

class Stack_int
{
public:
    int top;
    int size;
    int *stack;

    bool isEmpty()
    {
        return (this->top == -1) ? true : false;
    }

    void Push(int data)
    {
        if (this->top == this->size - 1)
            cout << "Stack Overflow" << endl;
        else
            this->stack[++this->top] = data;
    }

    void Pop()
    {
        if (this->top == -1)
            cout << "Stack Underflow" << endl;
        else
            this->top--;
    }
    int Top()
    {
        if (this->top == -1)
            return -1;
        return this->stack[this->top];
    }
};

bool isOperand(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return false;
    else
        return true;
}


int Evaluation_postfix(string postfix)
{
    Stack_int st;
    st.size = postfix.length();
    st.top = -1;
    st.stack = new int[st.size];

    int i, x1, x2, r;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
            st.Push(postfix[i] - 48);
        else
        {
            x2 = st.Top();
            st.Pop();
            x1 = st.Top();
            st.Pop();

            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            default:
                break;
            }

            st.Push(r);
        }
    }
    return st.Top();
}

int main()
{
    string s = "35*62/+4-";

    cout << Evaluation_postfix(s) << endl;

    return 0;
}
