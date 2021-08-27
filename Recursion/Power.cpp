#include <iostream>
using namespace std;

int Power(int m, int n)
{
    if (n == 0)
        return 1;
    return m * Power(m, n - 1);
}

int Power2(int m, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0) //   if n is even
        return Power2(m * m, n / 2);
    else //   if n is odd
        return m * Power2(m * m, (n - 1) / 2);
}

int main()
{
    cout << Power(2, 5);
    cout << endl;
    cout << Power2(2, 5);
    return 0;
}