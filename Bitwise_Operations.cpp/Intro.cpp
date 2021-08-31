#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 6;

    cout << (a & b) << endl;    //--> AND operation

    cout << (a | b) << endl;    //--> OR operation

    a = a << 5;                 //--> Left shift
    cout << a << endl;

    b = b >> 5;                //--> Right shit
    cout << b << endl;
    
    return 0;
}