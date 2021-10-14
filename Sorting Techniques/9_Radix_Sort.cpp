/*
    one of the best sorting technique
    take time O(n)
    space = O(1)

    modified version of Bucket/Bin sort

    size of Bin = 10 only (for decimal number)
    int passing = no. of digit of maximum element of list

    index of bin where element store = (array element / (passing * 10)) % 10
    ex:-
        In pass 1 :  last digit of element is index where element is store in Bin
        In pass 2 :  2nd last digit of element is index where element is store in Bin
        In pass 3 :  3rd last digit of element is index where element is store in Bin

    in each pass store element of array in Bin and vise-versa

    A = 237,146,259,348,152,163,235,48,36,62

    Pass 1 :  152,62,163,235,146,36,237,348,48,259

    Pass 2 :  235,36,237,146,348,48,152,259,62,163

    Pass 3 :  36,48,62,146,152,163,235,237,259,348  --> sorted array


*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        this->next = NULL;
    }
};

class Bucket
{
public:
    Node **Bins;
    int passes;

    Bucket(int Array[], int size)
    {
        int x = *max_element(Array, Array + size);
        int count = 0;
        while (x != 0)
        {
            x = x / 10;
            count++;
        }

        this->passes = count;
        this->Bins = new Node *[10];
    }

    void Insert(int index, int x)
    {
        Node *temp = new Node;
        temp->data = x;

        if (this->Bins[index] == NULL)
            this->Bins[index] = temp;

        else
        {
            Node *p = this->Bins[index];

            while (p->next != NULL)
                p = p->next;

            p->next = temp;
        }
    }

    int Delete(int index)
    {
        Node *p = this->Bins[index];
        this->Bins[index] = this->Bins[index]->next;
        int r = p->data;
        delete p;
        return r;
    }
};

void Radix_Sort(int Array[], int size)
{
    Bucket *b = new Bucket(Array, size);
    int x;

    for (int i = 0; i <= b->passes; i++)
    {
        for (int j = 0; j < size; j++)
        {
            x = (int)(Array[j] / pow(10, i)) % 10;
            b->Insert(x, Array[j]);
        }

        int k = 0, l = 0;

        while (k < 10)
        {
            while (b->Bins[k] != NULL)
            {
                Array[l++] = b->Delete(k);
            }
            k++;
        }
    }

    delete b;
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
    int arr[] = {5, 4846, 3, 75, 874, 9, 1, 484646162, 10, 4, 2, 6, 48978, 67894, 4873, 489, 64, 11, 8, 12, 7, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting " << endl;
    Print(arr, size);

    Radix_Sort(arr, size);

    cout << "\nAfter sorting " << endl;
    Print(arr, size);

    return 0;
}
