// recursion of type calling itself at last statement
// at returning time it nothing has to perform
// easily converted into loop (for,while)

#include <iostream>
using namespace std;

void Funtion(int n) // recursive funtion
{
    if (n > 0)
    {
        cout << n;
        n--;
        Funtion(n); //--> calling itself
    }
}



void Funtion2(int n)   // loop funtion
{
    while (n > 0)
    {
        cout << n;
        n--;
    }
}

//in case of Tail recursion loop funtion is more efficient in term of space not use more stack 

int main()
{
    Funtion(5);

    return 0;
}