/*

    why called insertion sort -> inserting an element in sorted list in sorted order
                                using this we insert list element on itself list and make it 
                                sorted.

    basically it design for linked list :- 
    in array after inserting element we need to shifting element which take O(n) time
    but in linked list we insert it in constant time


    A = |8|5|7|3|2|

    start shifting from second element from list i.e (first element is always sorted)
    
    1st pass - inserting 5
            
        |8| |7|3|2|
                            no of comparison = 1
        |5|8|7|3|2|         no of swap = 1

    2nd pass - inserting 5
   
        |5|8| |3|2|
                            no of comparison = 2
        |5|7|8|3|2|         no of swap = 2

    3rd pass - inserting 3
   
        |5|7|8| |2|
                            no of comparison = 3
        |3|5|7|8|2|         no of swap = 3

    4th pass - inserting 5
   
        |3|5|7|8| |
                            no of comparison = 4
        |2|3|5|7|8|         no of swap = 4


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
using namespace std;

void Insertion_Sort(int array[], int size)
{
    int i, j, x;
    for (i = 1; i < size; i++)
    {
        j = i - 1;
        x = array[i];
        while (j > -1 && array[j] > x)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = x;
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

    Insertion_Sort(arr,size);

    cout << "\nAfter sorting " << endl;
    Print(arr, size);

    return 0;
}