#include <iostream>
using namespace std;

void Reverse(int array[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

int main()
{
    int *p = new int[11];

    for (int i = 0; i < 11; i++)
        p[i] = i * 4;

    for (int i = 0; i < 11; i++)
        cout << p[i] << " ";
    cout << endl;

    Reverse(p, 11);

    for (int i = 0; i < 11; i++)
        cout << p[i] << " ";

    return 0;
}