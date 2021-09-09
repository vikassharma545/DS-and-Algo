#include <iostream>
#include <cmath>
using namespace std;

class Node
{
public:
    int coefficient;
    int exponent;
    Node *next;
};

class Ploynomial
{
private:
    Node *head;

public:
    Ploynomial()
    {
        this->head = NULL;
    }

    void Insert(int exp, int coeff)
    {
        Node *temp = new Node;
        temp->exponent = exp;
        temp->coefficient = coeff;
        temp->next = NULL;

        if (this->head == NULL)
        {
            this->head = temp;
        }
        else
        {
            Node *traverse = head;

            while (traverse->next != NULL)
            {
                traverse = traverse->next;
            }

            traverse->next = temp;
        }
    }

    void Display()
    {
        Node *temp = head;
        int i = 1;
        while (temp != NULL)
        {
            if (i++ == 1)
            {
                cout << temp->coefficient << "x^" << temp->exponent;
            }
            else
            {
                if (temp->exponent == 0)
                    cout << " + " << temp->coefficient;
                else if (temp->exponent == 1)
                    cout << " + " << temp->coefficient << "x";
                else
                    cout << " + " << temp->coefficient << "x^" << temp->exponent;
            }

            temp = temp->next;
        }
        cout << endl;
    }

    double Evaluate(double x_value)
    {
        double sum = 0;

        Node *temp = this->head;
        while (temp != NULL)
        {
            sum += temp->coefficient * pow(x_value, temp->exponent);
            temp = temp->next;
        }
        cout << "At x = " << x_value << " Polynomial value is : " << sum << endl;
        return sum;
    }
};

int main()
{
    Ploynomial p;

    p.Insert(3, 4);
    p.Insert(2, 9);
    p.Insert(1, 6);
    p.Insert(0, 7);
    p.Display();
    p.Evaluate(4.536);
    return 0;
}