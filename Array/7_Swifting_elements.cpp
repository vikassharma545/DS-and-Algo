#include <iostream>
using namespace std;

void Left_Swift(int array[], int size, int key)
{
    for (int i = 0; i < size - key; i++)
        array[i] = array[i + key];

    for (int i = size - key; i < size; i++)
        array[i] = 0;
}

void Left_Cyclic_Swift(int array[], int size, int key)
{
    int *tempL = new int[key];
    for (int i = 0; i < key; i++)
        tempL[i] = array[i];

    for (int i = 0; i < size - key; i++)
        array[i] = array[i + key];

    for (int i = size - key, j = 0; i < size; i++, j++)
        array[i] = tempL[j];

    delete[] tempL;
    tempL = NULL;
}

void Right_Swift(int array[], int size, int key)
{
    for (int i = size - 1; i >= key; i--)
        array[i] = array[i - key];

    for (int i = 0; i < key; i++)
        array[i] = 0;
}

void Right_Cyclic_Swift(int array[], int size, int key)
{
    int *tempR = new int[key];
    for (int i = size - 1, j = 0; i >= key; j++, i--)
        tempR[j] = array[i];

    for (int i = size - 1; i >= key; i--)
        array[i] = array[i - key];

    for (int i = key - 1, j = 0; i >= 0; i--, j++)
        array[i] = tempR[j];

    delete[] tempR;
    tempR = NULL;
}

int main()
{
    int *p = new int[11];

    for (int i = 0; i < 11; i++)
        p[i] = i * 4 + 2;

    for (int i = 0; i < 10; i++)
    {
        cout << p[i] << " ";
    }

    Right_Cyclic_Swift(p, 10, 5);
    Left_Cyclic_Swift(p, 10, 5);
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << p[i] << " ";
    }
    return 0;
}