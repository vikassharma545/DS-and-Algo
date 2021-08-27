// Nesed recursion in which function calling itself whose parameter itself a function calling

#include <iostream>
using namespace std;

int fun(int n)
{
    if (n > 100)
        return n - 10;
    else
        return fun(fun(n + 11)); //----->   parameter itself a function
}

int main()
{
    cout << fun(95);

    return 0;
}