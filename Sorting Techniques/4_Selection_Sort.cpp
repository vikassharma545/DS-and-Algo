/*

    why called selection sort -> we select smallest element from list and swap it 
                                from 1st element 

    A = |8|6|3|2|5|4|

    1st pass  | 2nd pass  | 3rd Pass |  4th pass  |  5th pass  |   sorted order

     8--1st       2            2            2           2               2        
     6            6--1st       3            3           3               3
     3            3--small     6--1st       4           4               4
     2--small     8            8            8--1st      5               5
     5            5            5            5--small    8--1st          6
     4            4            4--small     6           6--small        8

    Adaptive ?? -- >NO
    swaping even if it already sorted

    stable ??
    No

*/

#include <iostream>
#include <algorithm>
using namespace std;

void Selection_Sort(int array[], int size)
{
    int i, j, k;
    for (i = 0; i < size - 1; i++)
    {
        for (j = k = i; j < size; j++)
        {
            if (array[j] < array[k])
                k = j;
        }

        swap(array[i], array[k]);
    }
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
    int arr[] = {5, 3, 7, 9, 1, 10, 4, 2, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting " << endl;
    Print(arr, size);

    Selection_Sort(arr, size);

    cout << "\nAfter sorting " << endl;
    Print(arr, size);

    return 0;
}