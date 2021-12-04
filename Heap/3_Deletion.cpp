// Noted -> deletion in heap is always deletion of root node (max or min element)
// i.e only the root node will be delete

#include <bits/stdc++.h>
using namespace std;

// comparing (index = n) element with their parents if it greater move parents at place of child
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
    int i, j;
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
}

void print(int arr[], int size)
{
    for (int i = 1; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

    int array[] = {0, 5, 4, 8, 6, 1, 9, 7, 3, 10, 2}; // initial element is zero i.e index start from 1
    int size = sizeof(array) / sizeof(array[0]);

    for (int i = 2; i < size; i++) // start from i = 2 i.e first element is already in heap
        MaxHeap_Insert(array, i);  // you dont need seperate array for heap creation

    print(array, size);

    MaxHeap_Delete(array, size--); // size decrease

    print(array, size);

    return 0;
}