#include <iostream>
using namespace std;

int main()
{
    // Array created in stack memory

    int A[5];                   // declaration (all element have garbage value)
    int B[5] = {1, 2, 3, 4, 5}; // declaraton + intialised with value
    int C[5] = {0};             // all element have intialised with zero

    A[0] = 27; // assign value
    A[1] = 36;
    //rest all are garbage

    int size;
    cin >> size;
    int D[size]; // variable sized array (show error in c language not in c++)

    //printing using for loop
    for (int i = 0; i < 5; i++)
        cout << A[i] << endl;

    //printing using for-each loop
    for (int x : A)
        cout << x << endl;

    // Create Array in heap memory using pointer

    int *D;         // create pointer inside stack memory to store address
    D = new int[5];  // Create array inside heap memory assign address to 'D'

    A[0] = 10;
    A[1] = 20;
    // rest all assign to zero if created in heap memory

    for (int i = 0; i < 5; i++)
        cout << A[i] << " ";

    return 0;
}