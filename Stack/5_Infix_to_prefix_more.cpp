/*
  //for infix to postfix with preference and associativity convert funtions

    symbol      outstack preference       instack preference
     +,-                1                       2
     *,/                3                       4
     ^                  6                       5
     (                  7                       0
     )                  0                       ?

*/

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

bool isOperand(char s)
{
    if (s == '(' || s == ')' || s == '+' || s == '-' || s == '*' || s == '/' || s == '^')
        return false;
    else
        return true;
}

int outStackPref(char s)
{
    if (s == '+' || s == '-')
        return 1;
    else if (s == '*' || s == '/')
        return 3;
    else if (s == '^')
        return 6;
    else if (s == '(')
        return 7;
    else if (s == ')')
        return 0;

    return -1;
}

int inStackPref(char s)
{
    if (s == '+' || s == '-')
        return 2;
    else if (s == '*' || s == '/')
        return 4;
    else if (s == '^')
        return 5;
    else if (s == '(')
        return 0;

    return -1;
}

string Convert_to_postfix(string infix)
{
    Stack stk;
    stk.top = -1;
    stk.size = infix.length();
    stk.stack = new char[stk.size];

    char *postfix = new char[stk.size + 1];
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (outStackPref(infix[i]) > inStackPref(stk.Top()))
                stk.Push(infix[i++]);
            else if (outStackPref(infix[i]) < inStackPref(stk.Top()))
            {
                postfix[j++] = stk.Top();
                stk.Pop();
            }
            else
            {
                stk.Pop();
                i++;
            }
        }
    }

    while (!stk.isEmpty())
    {
        postfix[j++] = stk.Top();
        stk.Pop();
    }

    postfix[j] = '\0';

    return postfix;
}

int main()
{
    string s1 = "8+3*(9-6)/2^2+6/2";
    string s2 = "a+b+c*d";

    s1 = Convert_to_postfix(s1);
    s2 = Convert_to_postfix(s2);

    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}
