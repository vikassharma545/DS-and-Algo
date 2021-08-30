#include <iostream>
using namespace std;

int Linear_Search(int array[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
            return i;
    }
    return -1;
}

// Tranposition
int Linear_Search_improve(int array[], int size, int key) // improve linear search by swaping previous key to one index forward
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            if (i > 1)
            {
                int temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
            }
            return i;
        }
    }
    return -1;
}

int main()
{
    int *p = new int[10];

    for (int i = 0; i < 10; i++)
        p[i] = i * 4;

    cout << Linear_Search(p, 10, 2) << endl;

    cout << Linear_Search_improve(p, 10, 20) << endl;
    cout << Linear_Search_improve(p, 10, 20) << endl;
    cout << Linear_Search_improve(p, 10, 20) << endl;
    cout << Linear_Search_improve(p, 10, 20) << endl;
    cout << Linear_Search_improve(p, 10, 20) << endl;
    cout << Linear_Search_improve(p, 10, 20) << endl;
    cout << Linear_Search_improve(p, 10, 20) << endl;

    return 0;
}