/*

    time = nlogn
    or
    time = n^(3/2)
    

*/


#include <iostream>
using namespace std;

void Shell_Sort(int Array[], int size)
{
    int gap, i, j, temp;

    for (gap = size / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < size; i++)
        {
            temp = Array[i];
            j = i - gap;
            while (j >= 0 && Array[j] > temp)
            {
                Array[j + gap] = Array[j];
                j = j - gap;
            }
            Array[j + gap] = temp;
        }
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

    Shell_Sort(arr, size);

    cout << "\nAfter sorting " << endl;
    Print(arr, size);

    return 0;
}