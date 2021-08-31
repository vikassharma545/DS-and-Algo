// process to check bit in particuler location
#include <iostream>
using namespace std;

int main()
{
    int a = 10;     //--> 1010 in binary

    int b = 1;      //--> 0001 in binary

    // checking bits of a at 10th place and then 100th place of binary
    // first left shift then AND operation

    b = b << 1;
    a = a & b;      //--> 0010 in binary
    if (a > 1)
        cout << "bit at 10th place : true";
    else
        cout << "bit at 10th place : false";

    cout << endl;

    b = 1;
    b = b << 2;
    a = a & b;      //--> 0100 in binary
    if (a > 1)
        cout << "bit at 100th place : true";
    else
        cout << "bit at 100th place : false";

    return 0;
}