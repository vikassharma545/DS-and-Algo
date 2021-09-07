// Toeplitz matrix : element of diagonals are same i.e M[i,j]  =  M[i-1, j-1] for all i,j
//
// Number of non-zero elements = 2n-1
//
// Number of zero elements = n^n -2n-1
//
// size of array required -->  2n-1
//
// access element three case :-
//  Case 1:  i<=j     --->   M[i,j] = array[j-i]
//  Case 2:  i>j     --->   M[i,j] = array[n+i-j-1]

#include <iostream>
using namespace std;

class Toeplitz_Matrix
{
private:
    int matrix_size;
    int arr_size;
    int *arr;

public:
    Toeplitz_Matrix(int size)
    {
        this->matrix_size = size;
        this->arr_size = 2 * this->matrix_size - 1;
        this->arr = new int[this->arr_size];
    }

    ~Toeplitz_Matrix()
    {
        delete[] arr;
    }

    void set(int i, int j, int data)
    {
        if (i <= j)
            this->arr[j - i] = data;
        else if (i > j)
            this->arr[this->matrix_size + i - j - 1] = data;
    }

    int get(int i, int j)
    {
        if (i <= j)
            return this->arr[j - i];
        else if (i > j)
            return this->arr[this->matrix_size + i - j - 1];
    }

    void Display()
    {
        for (int i = 1; i <= this->matrix_size; i++)
        {
            for (int j = 1; j <= this->matrix_size; j++)
            {
                cout << this->get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Toeplitz_Matrix obj(5);

    int data = 1;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            obj.set(i, j, data++);
        }
    }

    obj.Display();

    return 0;
}