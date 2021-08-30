#include <iostream>
using namespace std;

int Binary_Search_Iterative(int array[], int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (array[mid] == key)
            return mid;
        else if (array[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int Binary_Search_Recursive(int array[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;

        if (array[mid] == key)
            return mid;
        else if (array[mid] < key)
            return Binary_Search_Recursive(array, mid + 1, high, key);
        return Binary_Search_Recursive(array, low, mid - 1, key);
    }
    return -1;
}

int main()
{
    int *p = new int[10];

    for (int i = 0; i < 10; i++)
        p[i] = i * 4;

    cout << Binary_Search_Iterative(p, 0, 9, 20) << endl;
    cout << Binary_Search_Recursive(p, 0, 9, 20) << endl;

    return 0;
}