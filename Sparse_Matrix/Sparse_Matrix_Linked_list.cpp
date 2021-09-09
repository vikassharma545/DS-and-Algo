#include <iostream>
using namespace std;

class Node
{
public:
    int column;
    int value;
    Node *next;
};

class Sparse_Matrix
{
private:
    int row_num;
    int column_num;
    Node **A; // using double pointer we create pointer inside heap

public:
    Sparse_Matrix(int row, int column)
    {
        this->row_num = row;
        this->column_num = column;
        A = new Node *[row]; // array of pointer of Node type
    }

    void set(int row, int column, int value)
    {
        Node *temp = new Node;
        temp->column = column;
        temp->value = value;
        temp->next = NULL;

        if (A[row - 1] == NULL)
        {
            A[row - 1] = temp;
        }
        else
        {
            Node *traverse = A[row - 1];

            while (traverse->next != NULL)
            {
                traverse = traverse->next;
            }

            traverse->next = temp;
        }
    }

    int get(int row, int column)
    {
        Node *traverse = A[row - 1];

        if (traverse == NULL)
        {
            return 0;
        }
        else
        {

            while (column != traverse->column && traverse->next != NULL)
            {
                traverse = traverse->next;
            }

            return (column == traverse->column) ? traverse->value : 0;
        }
    }

    void Display()
    {
        for (int i = 1; i <= this->row_num; i++)
        {
            for (int j = 1; j <= this->column_num; j++)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Sparse_Matrix s1(10, 9);

    int k = 10;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            s1.set(i, j, k++);
        }
    }

    s1.Display();

    return 0;
}