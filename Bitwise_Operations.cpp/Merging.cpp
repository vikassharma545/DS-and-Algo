// process to adding bit in particuler location
#include <iostream>
using namespace std;

int main()
{
    int a = 8; //--> 1000 in binary

    int b = 1; //--> 0001 in binary

    // suppose we add bit in variable a in hundrenth place to make it 1100 in binary , 12 in decimal

    //first left shift 1 , two times
    b = b << 2; //--> 0100 in binary

    //OR operation a with b
    a = a | b; //--> 1100 in binary, 12 in decimal

    cout << a << endl;  

    return 0;
}