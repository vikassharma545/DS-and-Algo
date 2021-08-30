#include <iostream>
using namespace std;

int Check_Sorted(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
            return -1;
    }

    return 1;
}

int main()
{
    int *p = new int[11];

    for (int i = 0; i < 11; i++)
        p[i] = i * 4;

    cout << Check_Sorted(p, 11);

    return 0;
}