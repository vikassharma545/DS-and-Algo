// Tower of Hanoi

// TOH(1,A,B,C);
// Moving 1 disk need 1 step
// Move from tower A to C

// TOH(2,A,B,C);
// Moving 2 disk need 3 step
// TOH(1,A,C,B);
// Move from tower A to C
// TOH(1,B,A,C);

// TOH(3,A,B,C);
// Moving 3 disk need 7 step
// TOH(2,A,C,B); --> need 3 step
// TOH(2,A,B,C);
// TOH(2,B,A,C); --> need 3 step

// TOH(n,A,B,C);
// similar for n number of disk
// TOH(n-1,A,C,B);
// Move from tower A to C
// TOH(n-1,B,A,C);


#include <iostream>
using namespace std;

void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        cout << "Move from tower " << A << " to " << C << endl;
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    TOH(5,1,2,3);

    return 0;
}