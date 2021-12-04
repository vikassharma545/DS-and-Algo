// sorting of array using heap is done by making array max heap and delete one by one every root and
// place it at last so largest element sorted one by one

 
#include <bits/stdc++.h>
using namespace std;

void MaxHeap_Insert(int arr[], int n) // n --> index of inserting element
{
    int temp, i = n;
    temp = arr[n];

    while (i > 1 && temp > arr[i / 2])
    {
        arr[i] = arr[i / 2];
        i = i / 2;
    }

    arr[i] = temp;
}

void MaxHeap_Delete(int arr[], int size) // here n is size of array not index od deleting element
{
    int x, i, j;
    x = arr[1];
    arr[1] = arr[size - 1];
    i = 1;
    j = 2 * i;

    while (j < size - 1)
    {
        if (arr[j + 1] > arr[j])
            j = j + 1;

        if (arr[i] < arr[j])
        {
            swap(arr[i], arr[j]);
            i = j;
            j = 2 * j;
        }
        else
            break;
    }

    arr[size - 1] = x; // assign last value as root value or largest value
}

void Heap_Sort(int arr[], int size)
{
    for (int i = 2; i < size; i++)
        MaxHeap_Insert(arr, i);

    for (int i = size; i > 1; i--)
        MaxHeap_Delete(arr, i); // i = size of heap after deleting (which is decreasing)
}

void print(int arr[], int size)
{
    for (int i = 1; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

    int array[] = {0, 5, 4, 8, 6, 1, 9, 48, 64, 97, 18, 34, 65, 15, 87, 91, 7, 3, 10, 2}; // initial element is zero i.e index start from 1
    int size = sizeof(array) / sizeof(array[0]);

    print(array, size);
    Heap_Sort(array, size);
    print(array, size);

    return 0;
}