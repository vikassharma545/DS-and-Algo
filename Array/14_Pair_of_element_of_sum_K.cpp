#include <iostream>
using namespace std;

//Without Hashing time = order of n^2
void Find_Pair1(int array[], int size, int k)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] + array[j] == k)
            {
                cout << "Pair : " << array[i] << " + " << array[j] << " = " << k << endl;
            }
        }
    }
}

int Max(int array[], int size)
{
    int max = INT8_MIN;
    for (int i = 0; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void Find_pair_with_hashing(int array[], int size, int k)
{
    int max = Max(array, size);
    int *hash = new int[max];

    for (int i = 0; i < size; i++)
        hash[array[i]]++;

    for (int i = 0; i < size; i++)
        if (hash[k - array[i]] == 1 && hash[array[i]] == 1)
        {

            cout << "Pair : " << array[i] << " + " << k - array[i] << " = " << k << endl;
            hash[array[i]] = 0;
        }

    delete[] hash;
    hash = NULL;
}

int main()
{
    int *p = new int[10];

    p[0] = 2;
    p[1] = 6;
    p[2] = 7;
    p[3] = 4;
    p[4] = 3;
    p[5] = 5;
    p[6] = 8;
    p[7] = 9;
    p[8] = 16;
    p[9] = 12;

    Find_pair_with_hashing(p, 10, 10);

    return 0;
}