/*
    why called merge sort -> it sort list by merging a parts of list (intially one element one list)

    A = |8|3|7|4|9|2|6|5|

    procedure :-
    extra array is recuired for merge sort

    A = | 8 |  | 3 |    | 7 |  | 4 |    | 9 |  | 2 |    | 6 |  | 5 | --> one element one list
          \     /         \      /         \     /        \     /
    A =  | 3 | 8 |        | 4 | 7 |       | 2 | 9 |      | 5 | 6 | --> two element one list
             \               /                \              /
    A =      | 3 | 4 | 7 | 8 |               | 2 | 5 | 6 | 9 | --> four element one list
                    \                               /
                     \                             /
    A =             | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |     --> sorted list

    analysis:-

    Time = O(nlogn)
*/

#include <iostream>
using namespace std;

void Merge(int Array[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int *B = new int[high + 1];

    while (i <= mid && j <= high)
    {
        if (Array[i] < Array[j])
            B[k++] = Array[i++];

        else
            B[k++] = Array[j++];
    }

    for (; i <= mid; i++)
        B[k++] = Array[i];

    for (; j <= high; j++)
        B[k++] = Array[j];

    for (int m = low; m <= high; m++)
        Array[m] = B[m];

    delete[] B;
}

void Iterative_Merge_Sort(int Array[], int n)
{
    int p, l, h, mid, i;

    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(Array, l, mid, h);
        }
        if (n - i > p / 2)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(Array, l, mid, n - 1);
        }
    }
    if (p / 2 < n)
        Merge(Array, 0, p / 2 - 1, n - 1);
}

void Recursive_Merge_Sort(int Array[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;

        Recursive_Merge_Sort(Array, low, mid);
        Recursive_Merge_Sort(Array, mid + 1, high);
        Merge(Array, low, mid, high);
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
    int arr[] = {5, 3, 70, 9, 1, 10, 4, 2, 6, 11, 8, 12, 7, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting " << endl;
    Print(arr, size);

    // Iterative_Merge_Sort(arr, size);
    Recursive_Merge_Sort(arr, 0, size - 1);

    cout << "\nAfter sorting " << endl;
    Print(arr, size);

    return 0;
}