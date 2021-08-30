#include <iostream>
using namespace std;

void Insert(int array[], int &length, int size, int index, int element)
{
    for (int i = length; i > index; i--)
        array[i] = array[i - 1];

    array[index] = element;
    length++;
}

int main()
{
    int *p = new int[10];

    p[0] = 8;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 7;
    p[5] = 6;
    p[6] = 9;

    int length = 7;

    for (int i = 0; i < 10; i++)
        cout << p[i] << " ";
    cout << endl;


    Insert(p, length, 10, 4, 55);


    for (int i = 0; i < 10; i++)
        cout << p[i] << " ";
    cout << endl;


    return 0;
}