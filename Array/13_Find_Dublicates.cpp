#include <iostream>
using namespace std;

// For sorted array

void Find_Dublicates(int array[], int size)
{
    int last_dublicate = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == array[i + 1] && array[i] != last_dublicate)
        {
            cout << array[i] << " ";
            last_dublicate = array[i];
        }
    }
}

void Find_Dublicate_with_Count(int array[], int size)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == array[i + 1])
        {
            j = i + 1;
            while (array[j] == array[i])
            {
                j++;
            }
            cout << "Dublicate " << array[i] << " --> " << j - i << " times" << endl;
            i = j - 1;
        }
    }
}

// For unsorted array we using hashing

int Max(int array[], int size)
{
    int max = INT8_MIN;
    for (int i = 0; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void Find_Dublicate_Hashing(int array[], int size)  // order of n time only
{
    int max = Max(array, size);
    int *hash = new int[max];

    for (int i = 0; i < size; i++)
        hash[array[i]]++;

    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (hash[array[i]] > 1)
        {
            cout << "Dublicate " << array[i] << " --> " << hash[array[i]] << " times" << endl;
            hash[array[i]] = 0;
        }
    }

    delete[] hash;
    hash = NULL;
}

int main()
{
    int *p = new int[10];

    p[0] = 2;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;
    p[5] = 5;
    p[6] = 5;
    p[7] = 6;
    p[8] = 7;
    p[9] = 7;

    // Find_Dublicate_with_Count(p, 10);
    Find_Dublicate_Hashing(p, 10);

    return 0;
}