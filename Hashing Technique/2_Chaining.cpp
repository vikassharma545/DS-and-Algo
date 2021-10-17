/*
    In Chaining hash table size is only 10 for decimal number

    all element of same last digit store in one liked list

    hash function --> h(x) = x % 10


    analysis:-

    let total number of element = 100

    size of hash table = 10

    we assume all element distribute equally

    Loading Factor (lambda) = n/size = 100/10 = 10 --> 10 element in each location of hash table

    average successfull Search time =  1 + lambda/2

    average unsuccessfull Search time =  1 + lambda


*/


#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
};

class Hash_Table
{
public:
    Node **h;

    Hash_Table()
    {
        h = new Node *[10];
    }

    void print()
    {
        for (int i = 0; i < 10; i++)
        {
            Node *temp = h[i];
            cout << "[" << i << "] --> ";
            while (temp)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    int Index(int x)
    {
        return x % 10;
    }

    void Insert(int Array[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            int x = Array[i];
            int y = this->Index(x);
            Node *temp = new Node;
            temp->data = x;

            if (this->h[y] == NULL)
            {
                this->h[y] = temp;
            }
            else
            {
                Node *p = this->h[y];
                Node *tail;

                while (p && (x > p->data))
                {
                    tail = p;
                    p = p->next;
                }

                if (p == this->h[y])
                {
                    temp->next = this->h[y];
                    this->h[y] = temp;
                }
                else
                {
                    temp->next = p;
                    tail->next = temp;
                }
            }
        }
        this->print();
    }

    bool Search(int x)
    {
        int y = this->Index(x);
        Node *p = this->h[y];

        if (p == NULL)
            return false;

        while (p != NULL)
        {
            if (p->data == x)
                return true;

            if (p->data > x)
                return false;
            else
                p = p->next;
        }
        return false;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 14, 4, 74, 5, 6, 7, 8, 10, 11, 12, 22, 45, 25, 35, 40, 62, 84, 76};

    int size = sizeof(arr) / sizeof(arr[0]);

    Hash_Table h;

    h.Insert(arr, size);

    int serch;
    cout << "Entre element to search :" << endl;
    cin >> serch;

    if (h.Search(serch))
        cout << "Found " << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}