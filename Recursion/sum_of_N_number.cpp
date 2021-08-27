#include <iostream>
using namespace std;

int SUM(int n)
{
    if (n == 0)
        return 0;
    return n + SUM(n - 1);
}

int main()
{
    cout << SUM(10);

    return 0;
}