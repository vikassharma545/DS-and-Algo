#include <iostream>
using namespace std;

int *Merging(int array1[], int array2[], int size1, int size2)
{
    int *temp = new int[size1 + size2];

    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (array1[i] < array2[j])
            temp[k++] = array1[i++];
        else
            temp[k++] = array2[j++];
    }

    for (; i < size1; i++)
        temp[k++] = array1[i];

    for (; j < size2; j++)
        temp[k++] = array2[j];

    return temp;
}

int main()
{
    int *p = new int[7];
    int *q = new int[5];

    for (int i = 0; i < 7; i++)
        p[i] = i * 4 + 3;

    for (int i = 0; i < 7; i++)
        cout << p[i] << " ";

    cout << endl;

    for (int i = 0; i < 5; i++)
        q[i] = i * 3 + 2;

    for (int i = 0; i < 5; i++)
        cout << q[i] << " ";
    cout << endl;

    int *z = Merging(p, q, 7, 5);

    for (int i = 0; i < 12; i++)
    {
        cout << z[i] << " ";
    }

    return 0;
}