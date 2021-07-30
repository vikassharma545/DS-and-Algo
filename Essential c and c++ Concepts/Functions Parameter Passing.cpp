/*
    Three ways of parameter passing 
    1. pass by value
    2. pass by reference
    3. pass by address

*/

// for pass by value
void Swap1(int x,int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}


// for pass by reference
void Swap2(int &x,int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}


// for pass by address
void Swap3(int *x,int *y)   
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

#include<iostream>
using namespace std;

int main()
{
    int a,b;
    a = 10;
    b = 20;

    // Pass by value  (No change in actual value)
    Swap1(a,b);         
    cout<<a<<endl;
    cout<<b<<endl;


    // Pass by reference (Swaping done)
    Swap2(a,b);
    cout<<a<<endl;
    cout<<b<<endl;


    // Pass by address  (Swaping done)
    Swap3(&a,&b);
    cout<<a<<endl;
    cout<<b<<endl;
    

    return 0;

}