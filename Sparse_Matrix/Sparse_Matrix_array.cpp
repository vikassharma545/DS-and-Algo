#include <iostream>
using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse_matrix
{
private:
    int row_num;
    int column_num;
    int element_num;
    Element *arr;

public:
    Sparse_matrix(int n, int m, int num)
    {
        this->row_num = n;
        this->column_num = m;
        this->element_num = num;
        this->arr = new Element[this->element_num];
    }

    void insert_elements()
    {
        cout << "Number of Rows     : " << this->row_num << endl;
        cout << "Number of Columns  : " << this->column_num << endl;
        cout << "Number of Elements : " << this->element_num << endl;

        cout << "\n\nEntre row, column, and element itself repectively..." << endl;

        for (int i = 0; i < this->element_num; i++)
        {
            cout << "For element " << i + 1 << endl;
            cin >> this->arr[i].i;
            cin >> this->arr[i].j;
            cin >> this->arr[i].x;
        }
    }

    void Display()
    {
        int k = 0;
        for (int i = 1; i <= this->row_num; i++)
        {
            for (int j = 1; j <= this->column_num; j++)
            {
                if (i == this->arr[k].i && j == this->arr[k].j)
                    cout << this->arr[k++].x << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
    }

    Sparse_matrix *Add(Sparse_matrix s1, Sparse_matrix s2)
    {

        //condition if row and column are not equal
        cout << "vikas" << endl;
        cout << s1.row_num << endl;
        cout << s1.column_num << endl;
        cout << s2.row_num << endl;
        cout << s2.column_num << endl;

        if ((s1.row_num != s2.row_num) || (s1.column_num != s2.column_num))
        {
            cout << "Matrix have different dimention cannot be add" << endl;
            return NULL;
        }
        else
        {
            // // Creating sparse matrix for return
            Sparse_matrix *s3 = new Sparse_matrix(s1.row_num, s1.column_num, s1.element_num + s2.element_num);

            // index for traverse
            int i = 0, j = 0, k = 0;

            while (i < s1.element_num && j < s2.element_num)
            {
                if (s1.arr[i].i < s2.arr[j].i)
                    s3->arr[k++] = s1.arr[i++];
                else if (s1.arr[i].i > s2.arr[j].i)
                    s3->arr[k++] = s2.arr[j++];
                else
                {
                    if (s1.arr[i].j < s2.arr[j].j)
                        s3->arr[k++] = s1.arr[i++];
                    else if (s1.arr[i].j > s2.arr[j].j)
                        s3->arr[k++] = s2.arr[j++];
                    else
                    {
                        s3->arr[k] = s1.arr[i];
                        s3->arr[k++].x = s1.arr[i++].x + s2.arr[j++].x;
                    }
                }
            }

            for (; i < s1.element_num; i++)
                s3->arr[k++] = s1.arr[i++];

            for (; j < s2.element_num; j++)
                s3->arr[k++] = s2.arr[j++];

            s3->element_num = k;

            return s3;
        }
    }
};

int main()
{
    Sparse_matrix matrix1(2, 2, 2), matrix2(2, 2, 3), *matrix3 = NULL;
    matrix1.insert_elements();
    matrix1.Display();
    matrix2.insert_elements();
    matrix2.Display();

    matrix3 = matrix1.Add(matrix1, matrix2);

    if (!matrix3 == NULL)
    {
        matrix3->Display();
    }

    return 0;
}