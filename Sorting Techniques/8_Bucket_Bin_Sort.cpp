/*
    using array of linked list

    and adding element of node at given index 

    after assign value reverse to array

    ex:-

    A = |6|8|3|10|15|6|9|12|6|3|

    index ->  1   2   3   4   5   6   7   8   9   10   11   12   13   14   15
    Bins   = |/| |/| |/| |/| |/| |/| |/| |/| |/|  |/|  |/|  |/|  |/|  |/|  |/|


    Bins   = |/|  |/|  |p|  |/|  |/|  |p|  |/|  |p|  |p|   |p |  |/|  |p |  |/|  |/|  |p |
                        |              |         |    |     |          |               | 
                       |3|            |6|       |8|  |9|   |10|       |12|            |15|
                        |              |         |    |      |         |               |
                       |3|            |6|       |8|  |9|   |10|       |12|            |15|
                                       |
                                      |6|


    Time = O(n)
    space = O(n)
*/

#include <iostream>
#include <algorithm>
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
    int max;
    Bucket(int Array[], int size)
    {
        this->max = *max_element(Array, Array + size);
        this->Bins = new Node *[this->max + 1];
    }

    void Insert(int x)
    {
        Node *temp = new Node;
        temp->data = x;

        if (this->Bins[x] == NULL)
            this->Bins[x] = temp;

        else
        {
            Node *p = this->Bins[x];

            while (p->next != NULL)
                p = p->next;

            p->next = temp;
        }
    }

    int Delete(int x)
    {
        Node *p = this->Bins[x];
        this->Bins[x] = this->Bins[x]->next;
        int r = p->data;
        delete p;
        return r;
    }
};

void Bin_Sort(int Array[], int size)
{
    Bucket *b = new Bucket(Array, size);

    for (int i = 0; i < size; i++)
        b->Insert(Array[i]);

    int i = 0, j = 0;

    while (i < b->max + 1)
    {
        while (b->Bins[i] != NULL)
        {
            Array[j++] = b->Delete(i);
        }
        i++;
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
    int arr[] = {5, 3, 70, 9, 1, 10, 4, 2, 6, 11, 8, 12, 7, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting " << endl;
    Print(arr, size);

    Bin_Sort(arr, size);

    cout << "\nAfter sorting " << endl;
    Print(arr, size);

    return 0;
}