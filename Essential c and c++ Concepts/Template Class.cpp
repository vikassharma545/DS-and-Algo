// generic function and classes or template function and classes only supported by c++ 

#include<iostream>
using namespace std;
    

template <class T>   // here 'T' is generic data type
class Calculator
{
    private:
    T a;
    T b;

    public:
    Calculator(T x, T y)    // constructor
    {
        this->a = x;
        this->b = y;
    }

    T Adding();
    T Multiplies();

};

template<class T>
T Calculator<T> ::Adding()
{
    T c;
    c = this->a + this->b;
    return c;
} 

template<class T>
T Calculator<T>::Multiplies()
{
    T c;
    c = this->a * this->b;
    return c;
}

    
int main()
{
    Calculator<int> c1(4,5);
    cout<<c1.Adding()<<endl;
    cout<<c1.Multiplies()<<endl;

    Calculator<float> c2(2.4,6.7);
    cout<<c2.Adding()<<endl;
    cout<<c2.Multiplies()<<endl;

    Calculator<char> c3('a','b');
    cout<<c3.Adding()<<endl;
    cout<<c3.Multiplies()<<endl;
    
    
    return 0;
}