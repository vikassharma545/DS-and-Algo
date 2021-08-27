/*
    e^x = 1 + x/1 + x^2/2! + x^3/3! + ... n terms


    using horner's rule

    e^x = 1 + x/1 [1 + x/2 [1 + x/3 [1 + x/4 *...*[1 + x/n]...]]]
*/

#include <iostream>
using namespace std;

double Taylor(double x, double n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1;
    else
    {
        r = Taylor(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}



double Taylor2(double x, double n) 
{
    static double s = 1;
    if (n == 0)
        return s;
    s = (double)1 + x / n * s;
    return Taylor2(x, n - 1);
}

int main()
{
    cout << Taylor(4, 15);
    cout << endl;
    cout << Taylor2(4, 15);

    return 0;
}