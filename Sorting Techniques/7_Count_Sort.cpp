/*
    one of the simple and fast technique 

    using Hashing

    need lot of space
    require extra array of size = max element in given list

    Time = O(n) only

*/

#include <iostream>
#include <algorithm>
using namespace std;

void Count_Sort(int Array[], int size)
{
    int max = *max_element(Array, Array + size);
    int *arr = new int[max + 1];

    for (int i = 0; i < size; i++)
        arr[Array[i]]++;

    int i = 0, j = 0;

    while (i < max + 1)
    {
        while (arr[i] > 0)
        {
            Array[j++] = i;
            arr[i]--;
        }
        i++;
    }

    delete[] arr;
}

void Print(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {5, 7, 3, 17, 9, 1, 10, 4, 2, 6, 11, 2, 8, 12, 2, 7, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting " << endl;
    Print(arr, size);

    Count_Sort(arr, size);

    cout << "\nAfter sorting " << endl;
    Print(arr, size);

    return 0;
}