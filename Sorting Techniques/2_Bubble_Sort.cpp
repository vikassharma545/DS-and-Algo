/*
    why called Bubble sort -> just like bubble lighter bubble move up slowly 
                              small elemnt move up slowly 

    A = |8|5|7|3|2|

    1st pass ------------------>   1 largest element is sorted (8)
                8-|  5    5    5    5
                5-|  8-|  7    7    7           4 comparison
                7    7-|  8-|  3    3           4 swap
                3    3    3-|  8-|  2
                2    2    2    2-|  8

    2nd pass ------------------>   2 largest element is sorted (7,8)
                5-|  5    5    5    
                7-|  7-|  3    3                3 comparison
                3    3-|  7-|  2                3 swap
                2    2    2-|  7  
                8    8    8    8  
    
    3rd pass ------------------>   3 largest element is sorted (5,7,8)
                5-|  3    3    
                3-|  5-|  2                     2 comparison
                2    2-|  5                     2 swap
                7    7    7  
                8    8    8  
    
    4th pass ------------------>   4 largest element is sorted (3,5,7,8)
                3-|  2    
                2-|  3                          1 comparison
                5    5                          1 swap
                7    7  
                8    8

    analysis : -

    no of max passes            --->   (n-1)

    no of max Comparison    --->   (n-1)+(n-2)+(n-3)+..+1  = n(n-1)/2 -> O(n^2)

    no of max swap          --->   (n-1)+(n-2)+(n-3)+..+1  = n(n-1)/2 -> O(n^2) 
    

    Adaptive ??
    yes no swaping if it already sorted

    stable ??
    yes


*/

#include <iostream>
#include <algorithm>
using namespace std;

void Bubble_Sort(int array[], int size)
{
    int flag;

    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                flag = 1; // flag 1 if swaping done mean array not sorted
            }
        }

        // using adaptive
        if (flag == 0) // if array is sorted
            break;
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

    Bubble_Sort(arr, size);

    cout << "\nAfter sorting " << endl;
    Print(arr, size);

    return 0;
}