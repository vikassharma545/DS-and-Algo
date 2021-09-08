#include <iostream>
#include <cmath>
using namespace std;

class Term
{
public:
    int Cofficient;
    int Exponential;
};

class Polynomial
{
private:
    int Number_of_terms;
    Term *term;

public:
    Polynomial()
    {
        cout << "Entre the number of non-zero terms : ";
        cin >> this->Number_of_terms;

        this->term = new Term[this->Number_of_terms];

        cout << "Enter term exponent and value respectively " << endl;
        for (int i = 0; i < this->Number_of_terms; i++)
        {
            cout << "Term " << i + 1 << " : ";
            cin >> this->term[i].Exponential >> this->term[i].Cofficient;
        }
    }

    Polynomial(int size)
    {
        this->Number_of_terms = size;
        this->term = new Term[this->Number_of_terms];
    }

    void Display()
    {
        for (int i = 0; i < this->Number_of_terms; i++)
        {
            if ((this->term[i].Cofficient != 0) && (this->term[i].Exponential != 0))
            {
                if (i == 0)
                    cout << this->term[i].Cofficient << "x^" << this->term[i].Exponential;
                else
                {
                    if (this->term[i].Exponential == 0)
                        cout << " + " << this->term[i].Cofficient;
                    else if (this->term[i].Exponential == 1)
                        cout << " + " << this->term[i].Cofficient << "x";
                    else
                        cout << " + " << this->term[i].Cofficient << "x^" << this->term[i].Exponential;
                }
            }
        }
        cout << endl;
    }

    double Evaluation(double value_of_x)
    {
        double sum = 0;
        for (int i = 0; i < this->Number_of_terms; i++)
        {
            sum += (double)this->term[i].Cofficient * pow((double)value_of_x, this->term[i].Exponential);
        }
        return sum;
    }

    Polynomial *Add(Polynomial p1, Polynomial p2)
    {
        int max_size = (p1.term[0].Exponential > p2.term[0].Exponential) ? p1.term[0].Exponential + 1 : p2.term[0].Exponential + 1;
        Polynomial *p3 = new Polynomial(max_size);

        int i = 0, j = 0, k = 0;

        while (i < p1.Number_of_terms && j < p2.Number_of_terms)
        {
            if (p1.term[i].Exponential > p2.term[j].Exponential)
                p3->term[k++] = p1.term[i++];
            else if (p1.term[i].Exponential < p2.term[j].Exponential)
                p3->term[k++] = p2.term[j++];
            else
            {
                p3->term[k] = p1.term[i];
                p3->term[k++].Cofficient = p1.term[i++].Cofficient + p2.term[j++].Cofficient;
            }
        }

        for (; i < p1.Number_of_terms; i++)
            p3->term[k++] = p1.term[i];

        for (; j < p2.Number_of_terms; j++)
            p3->term[k++] = p2.term[j];

        return p3;
    }
};

int main()
{
    Polynomial p, *p2;

    p.Display();
    cout << "At x = 2 polynomial : " << p.Evaluation(2) << endl;
    p2 = p.Add(p, p);
    p2->Display();
    cout << "At x = 2 polynomial : " << p2->Evaluation(2) << endl;

    return 0;
}