// Tri-diagonal or Tri-Band matrix :  M[i,j] = 0  if |i-j| >1    else    if M[i,j] != 0 if |i-j| <=1
//
// Number of non-zero elements = 3n-2
//
// Number of zero elements = n^n - 3n-2
//
// size of array required -->  3n-2
//
// access element three case :-
//  Case 1:  i-j = 1     --->   M[i,j] = array[(i-1)]
//  Case 2:  i-j = 0     --->   M[i,j] = array[(n-1) + (i-1)]
//  Case 3:  i-j = -1    --->   M[i,j] = array[(2n-1) + (i-1)]

#include <iostream>
using namespace std;

class Tri_Diagonal_Matrix
{
private:
    int matrix_size;
    int arr_size;
    int *arr;

public:
    Tri_Diagonal_Matrix(int size)
    {
        this->matrix_size = size;
        this->arr_size = size * (size + 1) / 2;
        this->arr = new int[this->arr_size];
    }

    ~Tri_Diagonal_Matrix()
    {
        delete[] arr;
    }

    void set(int i, int j, int data)
    {
        if (i - j == 1)
            this->arr[i - 1] = data;
        else if (i - j == 0)
            this->arr[this->matrix_size + i - 2] = data;
        else if (i - j == -1)
            this->arr[2 * this->matrix_size + i - 2] = data;
    }

    int get(int i, int j)
    {
        if (i - j == 1)
            return this->arr[i - 1];
        else if (i - j == 0)
            return this->arr[this->matrix_size + i - 2];
        else if (i - j == -1)
            return this->arr[2 * this->matrix_size + i - 2];
        else
            return 0;
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
    Tri_Diagonal_Matrix obj(5);

    int data = 1;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i - j == 1 || i - j == 0 || i - j == -1)
            {
                obj.set(i, j, data);
            }
        }
    }

    obj.Display();

    return 0;
}