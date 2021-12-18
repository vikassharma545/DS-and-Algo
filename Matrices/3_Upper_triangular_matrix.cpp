// Upper triangular matix : M[i,j] = 0 if i>j, else M[i,j] != 0 if i<=j
//
// Number of non-zero elements = n(n+1)/2
//
// Number of zero elements = n^2 - Number of non-zero elements = n(n-1)/2
//
// size of array required -->  n(n+1)/2
//
// access element --->   M[i,j] = array[( (n*(i-1)) - (i-2)(i-1)/2 )  +  (j-i)]  --> row major
//
// access element --->   M[i,j] = array[ j*(j-1)/2 + (i-1) ]  --> column major

#include <iostream>
using namespace std;

class Upper_Triangular_Matrix
{
private:
    int matrix_size;
    int arr_size;
    int *arr;

public:
    Upper_Triangular_Matrix(int size)
    {
        this->matrix_size = size;
        this->arr_size = size * (size + 1) / 2;
        this->arr = new int[this->arr_size];
    }

    ~Upper_Triangular_Matrix()
    {
        delete[] arr;
    }

    void set(int i, int j, int data)
    {
        if (i <= j)
            this->arr[(j * (j - 1) / 2) + (i - 1)] = data;
    }

    int get(int i, int j)
    {
        if (i <= j)
            return this->arr[(j * (j - 1) / 2) + (i - 1)];
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
    Upper_Triangular_Matrix obj(5);

    int data = 1;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i <= j)
            {
                obj.set(i, j, data);
            }
        }
    }

    obj.Display();

    return 0;
}