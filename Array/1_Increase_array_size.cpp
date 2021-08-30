// Only dynamically created array size is increased
// by shifting all element of array to large size array
// we not increased same array because dont know next block of memory after array free or not
#include <iostream>
using namespace std;

int main()
{
    int *p = new int[5]; //--> first array

    for (int i = 0; i < 5; i++)
        p[i] = i * 3;

    for (int i = 0; i < 5; i++)
        cout << p[i] << " ";
    cout << endl;

    int *q = new int[10]; //--> large array

    for (int i = 0; i < 5; i++)
        q[i] = p[i]; //// -----> Shifting

    delete[] p;
    p = q;
    q = NULL;

    for (int i = 0; i < 10; i++)
    cout << p[i] << " ";

    return 0;
}