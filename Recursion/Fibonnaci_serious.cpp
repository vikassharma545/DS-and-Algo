// fibonnaci serious next term is sum of previous two term --> 0,1,1,2,3,5,8,13,21,34,55,89,...
#include <iostream>
using namespace std;

int Fib(int n)
{
    if (n <= 1)
        return n;
    else
        return Fib(n - 1) + Fib(n - 2);
}

int main()
{
    cout<<Fib(8);

    return 0;
}