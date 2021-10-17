/*
    it also a method of resolving collison

    Double hashing have two hashing function

    h1(x) = x % 10

    h2(x) = 7-(x % 7)  --> largest prime number number smaller then size of hash (10) = 7

    h'(x) = ( h1(x) + i * h2(x) ) % 10     where i = 0,1,2,3,4

*/

#include <iostream>
using namespace std;

bool isPrime(int x)
{
    int m = x / 2;

    for (int i = 2; i <= m; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

class Double_hashing
{
    int *array;
    int hashsize;
    int r;

public:
    Double_hashing(int size)
    {
        this->hashsize = size * 1.3;

        for (int i = this->hashsize - 2; i > 0; i--)
        {
            if (isPrime(i))
            {
                this->r = i;
                break;
            }
        }

        this->array = new int[this->hashsize];

        for (int i = 0; i < this->hashsize; i++)
            this->array[i] = -1;
    }

    int hash1(int x)
    {
        return x % this->hashsize;
    }

    int hash2(int x)
    {
        return this->r - (x % this->r);
    }

    int probe(int x)
    {
        int h1 = this->hash1(x);
        int h2 = this->hash2(x);
        int i = 0;

        while (this->array[(h1 + (i * h2)) % this->hashsize] != -1)
            i++;

        return (h1 + (i * h2)) % this->hashsize;
    }

    void Insert(int arr[], int size)
    {
        int x;
        for (int i = 0; i < size; i++)
        {
            x = arr[i];

            int index = this->hash1(x);

            if (this->array[index] != -1)
                index = this->probe(x);

            this->array[index] = x;
        }

        cout << "Hash tabel" << endl;
        for (int i = 0; i < this->hashsize; i++)
        {
            cout << i << "-->" << this->array[i] << endl;
        }
    }

    bool search(int x)
    {
        int h1 = this->hash1(x);
        int h2 = this->hash2(x);

        int i = 0;

        int count = 0;
        while (this->array[(h1 + (i * h2)) % this->hashsize] != x && this->array[(h1 + (i * h2)) % this->hashsize] != -1)
        {
            count++;
            i++;
        }

        cout << "No of Comparison : " << count << endl;

        if (this->array[(h1 + (i * h2)) % this->hashsize] == -1)
            return false;
        else
        {
            cout << "Index            : " << (h1 + (i * h2)) % this->hashsize << endl;
            return true;
        }
    }
};

int main()
{
    int arr[] = {1, 2, 3, 29, 0, 14, 4, 74, 5, 6, 7, 8, 10, 11, 12, 22, 45, 25, 35, 40, 62, 84, 76};

    int size = sizeof(arr) / sizeof(arr[0]);

    Double_hashing h(size);

    h.Insert(arr, size);

    int serch;
    cout << "Entre element to search :" << endl;
    cin >> serch;

    if (h.search(serch))
        cout << "Found " << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}