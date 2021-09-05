/*
intro

    1. Infix : operand operator operand    (commonly used in mathematics)
    e.g -->  a+b,a*b

    2. prefix : operator operand operand
    e.g -->  +ab,*ab

    3. postfix : operand operand operator
    e.g -->  ab+,ab*

some conversion infix to postfix

ex-1..
        a+b+c*d  //--> infix
        a+b+[cd*]
        [ab+]+[cd*]
        ab+cd*+  // postfix



ex-2..
        8+3*(9-6)/2^2+6/2  // infix form
        8+3*[96-]/2^2+6/2
        8+3*[96-]/[22^]+6/2
        8+[396-*]/[22^]+6/2 
        8+[396-*22^]+6/2
        8+[396-*22^]+[62/]
        [8396-*22^+]+[62/]
        8396-*22^+62/+    --> required postfix



// preference and associativity

    symbol      preference      associativity
     +,-            1              L - R
     *,/            2              L - R
     ^              3              R - L
     -              4              R - L 
     ()             5              L - R

    urinary operator --> -
    -a ,  *p  , **p  , ++a ,  n!        etc.

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

bool isOperand(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return false;
    else
        return true;
}

int preference(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

string Change_to_postfix(string infix) // for only +, -, *, / operators
{
    Stack stk;
    stk.size = infix.length();
    stk.top = -1;
    stk.stack = new char[stk.size];
    char *postfix = new char[infix.length() + 1];

    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (preference(infix[i]) > preference(stk.Top()))
                stk.Push(infix[i++]);
            else
            {
                postfix[j++] = stk.Top();
                stk.Pop();
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
    string s = "a+b+c*d";
    s = Change_to_postfix(s);

    cout << s << endl;
    return 0;
}
