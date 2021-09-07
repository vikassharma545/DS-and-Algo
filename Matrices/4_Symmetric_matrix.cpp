// Symmetric matrix :    if M[i,j] = M[j,i]
//
// Number of non-zero elements = n*n
//
// Number of zero elements = 0
//
// size of array required -->  n(n+1)/2 --> not need to store all element
//
// you can store either lower tiangular or upper triangular
//
// storing lower triangular matrix access element
//  if i>=j --->   M[i,j] = array[(i*(i-1)/2) + (j-1)]
//  else    --->   M[i,j] = array[(j*(j-1)/2) + (i-1)]

#include <iostream>
using namespace std;

class Symmetric_Matrix
{
private:
    int matrix_size;
    int arr_size;
    int *arr;

public:
    Symmetric_Matrix(int size)
    {
        this->matrix_size = size;
        this->arr_size = size * (size + 1) / 2;
        this->arr = new int[this->arr_size];
    }

    ~Symmetric_Matrix()
    {
        delete[] arr;
    }

    void set(int i, int j, int data) // set only in upper triangular matrix
    {
        if (i >= j)
            this->arr[(i * (i - 1) / 2) + (j - 1)] = data;
    }

    int get(int i, int j)
    {
        if (i >= j)
            return this->arr[(i * (i - 1) / 2) + (j - 1)];
        else
            return this->arr[(j * (j - 1) / 2) + (i - 1)];
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
    Symmetric_Matrix obj(4);

    int data = 1;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (i >= j)
            {
                obj.set(i, j, data++);
            }
        }
    }

    obj.Display();

    return 0;
}