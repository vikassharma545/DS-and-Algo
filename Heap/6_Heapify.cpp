// it is fastest method to make array as heap
// here heap creation is start from array end

#include <bits/stdc++.h>
using namespace std;

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void Heapify(int A[], int n)
{
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        int j = 2 * i + 1; // Left child for current i

        while (j < n - 1)
        {
            // Compare left and right children of current i
            if (A[j] < A[j + 1])
                j = j + 1;

            // Compare parent and largest child
            if (A[i] < A[j])
            {
                swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            }
            else
            {
                break;
            }
        }
    }
}

void MaxHeap_Delete(int arr[], int n)
{
    int x, i, j;
    x = arr[1];
    arr[1] = arr[n];
    i = 1;
    j = 2 * i;

    while (j < n - 1)
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

    arr[n] = x;
}

void Heap_sort(int arr[], int size)
{
    Heapify(arr, size);
    for (int i = size - 1; i > 0; i--)
        MaxHeap_Delete(arr,1);
}

void print(int arr[], int size)
{
    for (int i = 1; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int A[] = {5, 10, 30, 20, 35, 40, 15};
    int size = sizeof(A) / sizeof(A[0]);
    Heap_sort(A, size);
    print(A, size);

    return 0;
}