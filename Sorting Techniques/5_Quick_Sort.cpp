/*
    the average time complexity of quick shot = O(nlogn) that one of the reason 
    it consider best sorting algorith and fastest algorithm

    why called quick sort -> thats not mean its name is quick so it sort faster
                            the element arrange them themselve in their sorted 
                            position (left side all element are small and right 
                            side all element is greater)

    In Selection sort we select position(first position of list) and finding smallest element
    for those position.
    But in quick sort :-
    we select element (first element of list) and finding position for those element

    quick sort also called :-
    1. Selection Exchange Sort
    2. Partition Exchange Sort


    Let find sorted position of element 50  (first element of list)

    pivot element -> 50
    
        50, 70, 60, 90, 40, 80, 10, 20, 30, infinity
            i----------------------------j
        
        50, 30, 60, 90, 40, 80, 10, 20, 70, infinity
                i--------------------j

        50, 30, 20, 90, 40, 80, 10, 60, 70, infinity
                    i------------j

        50, 30, 20, 10, 40, 80, 90, 60, 70, infinity
                        j   i                         --> i > j

        swap pivot with index j

        40, 30, 20, 10, (50), 80, 90, 60, 70, infinity
                         |
                         |
                partitioning the list      
    (left side all smaller right side all greater)
    again sort first element of two list (left of pivot) and right of pivot

    quick sort done using recursive (again and again apply quick sort on partitioning list)


    analysis

    best case  -> if partitioning element is at middle (Time = O(nlogn) )

    worst case -> if partitioning is at end (Time = O(n^2) ) 

    Avg. case ->    O(nlogn)

    for sorted list:-

    best case -> O(nlogn) if middle element move to first and make it pivot(for partitioning at middle)

    wrost case -> partiting at any end, time = O(n^2)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int Partitioning(int array[], int low, int high)
{
    int pivot = array[low];
    int i = low;
    int j = high;

    do
    {
        do
        {
            i++;
        } while (array[i] <= pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i < j)
            swap(array[i], array[j]);

    } while (i < j);

    swap(array[low], array[j]);

    return j;
}

void Quick_sort(int array[], int low, int high)
{
    int j;

    if (low < high)
    {
        j = Partitioning(array, low, high);
        Quick_sort(array, low, j);
        Quick_sort(array, j + 1, high);
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
    int arr[] = {5, 3, 7, 9, 1, 10, 4, 2, 6, 8, INT32_MAX};
    int size = sizeof(arr) / sizeof(arr[0]) - 1; // size is 1 less then actual size

    cout << "Before sorting " << endl;
    Print(arr, size);

    Quick_sort(arr, 0, size);

    cout << "\nAfter sorting " << endl;
    Print(arr, size);

    return 0;
}