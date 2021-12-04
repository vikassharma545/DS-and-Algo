// Noted -> index of array start from 1 onward 

#include <bits/stdc++.h>
using namespace std;

// comparing (index = n) element with their parents if it greater move parents at place of child
void MaxHeap_Insert(int arr[], int n) // n --> index of newly inserting element
{
    int temp, i = n;
    temp = arr[n];

    while (i > 1 && temp > arr[i / 2]) // comparing with parents (temp > parents) until (reach root i.e i>1)
    {
        arr[i] = arr[i / 2];
        i = i / 2;
    }

    arr[i] = temp;
}

void MinHeap_Insert(int arr[], int n) // n --> index of inserting element
{
    int temp, i = n;
    temp = arr[n];

    while (i > 1 && temp < arr[i / 2]) // comparing with parents (temp < parents)
    {
        arr[i] = arr[i / 2];
        i = i / 2;
    }

    arr[i] = temp;
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
    return 0;
}