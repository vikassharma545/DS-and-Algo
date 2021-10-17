/*

Hash function h'(x) = ( h(x) + f(i) ) % 10  where f(i) = i^2 , i = 0,1,2,3,4,...

Loading Factor (lambda) = n/size

lambda <= 0.5 always in probing ------> size of hash table > n

avg. successfull search time = -loge(1-lambda)

avg. unsuccessfull search time = 1/(1-lamnda)

Noted:-
The hash table should be an array with length about 1.3 times the maximum number of keys
that will actually be in the table, and. Size of hash table array should be a prime number.

*/

#include <iostream>
#include <cmath>
using namespace std;

class Quadratic_Probing
{
    int *array;
    int hashsize;

public:
    Quadratic_Probing(int size)
    {
        this->hashsize = size * 1.3;
        this->array = new int[this->hashsize];

        for (int i = 0; i < this->hashsize; i++)
            this->array[i] = -1;
    }

    int hash(int x)
    {
        return x % this->hashsize;
    }

    int probe(int x)
    {
        int index = this->hash(x);
        int i = 0;
        while (this->array[(index + int(pow(i, 2))) % this->hashsize] != -1)
            i++;
        return (index + int(pow(i, 2))) % this->hashsize;
    }

    void Insert(int arr[], int size)
    {
        int x;
        for (int i = 0; i < size; i++)
        {
            x = arr[i];

            int index = this->hash(x);

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
        int index = this->hash(x);

        int i = 0;

        int count = 0;
        while (this->array[(index + int(pow(i, 2))) % this->hashsize] != x && this->array[(index + int(pow(i, 2))) % this->hashsize] != -1)
        {
            count++;
            i++;
        }

        cout << "No of Comparison : " << count << endl;

        if (this->array[(index + int(pow(i, 2))) % this->hashsize] == -1)
            return false;
        else
        {
            cout << "Index            : " << (index + int(pow(i, 2))) % this->hashsize << endl;
            return true;
        }
    }
};

int main()
{
    int arr[] = {1, 2, 3, 29, 0, 14, 4, 74, 5, 6, 7, 8, 10, 11, 12, 22, 45, 25, 35, 40, 62, 84, 76};

    int size = sizeof(arr) / sizeof(arr[0]);

    Quadratic_Probing h(size);

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