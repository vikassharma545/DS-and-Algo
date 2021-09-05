#include <iostream>
using namespace std;

class Stack
{
public:
    int top;
    int size;
    char *stack;

    bool isEmpty()
    {
        return (this->top == -1) ? true : false;
    }

    void Push(char data)
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
    char Top()
    {
        if (this->top == -1)
            return -1;
        return this->stack[this->top];
    }
};

bool isBalanced1(string s)  //for only brackes --> ()
{
    Stack stk;
    stk.size = s.length();
    stk.top = -1;
    stk.stack = new char[stk.size];

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
            stk.Push(s[i]);
        else if (s[i] == ')')
        {
            if (!stk.isEmpty())
                stk.Pop();
            else
                return false;
        }
    }

    return (stk.isEmpty()) ? true : false;
}

bool isBalanced2(string s) // for all braces ---> (), {} , []
{
    Stack stk;
    stk.size = s.length();
    stk.top = -1;
    stk.stack = new char[stk.size];

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            stk.Push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if ((!stk.isEmpty()))
                switch (s[i])
                {
                case ')':
                    if (stk.Top() == '(')
                        stk.Pop();
                    else
                        return false;
                    break;
                case '}':
                    if (stk.Top() == '{')
                        stk.Pop();
                    else
                        return false;
                    break;
                case ']':
                    if (stk.Top() == '[')
                        stk.Pop();
                    else
                        return false;
                    break;
                default:
                    break;
                }
            else
                return false;
        }
    }
    return (stk.isEmpty()) ? true : false;
}

int main()
{
    string s = "[{(a+b) + (b+c)} + {(d+e) + (e+f)}]";

    if (isBalanced1(s))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced !!!" << endl;

    return 0;
}