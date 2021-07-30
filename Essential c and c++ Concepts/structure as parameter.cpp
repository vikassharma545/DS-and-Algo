//  Structure can pass by :-
//  * call by value
//  * call by address
//  * call by reference

struct Rectangle
{
    int Length;
    int Breath;
};


// for pass by value
int Area1(Rectangle r)
{
    r.Length++;
    r.Breath++;
    return r.Length * r.Breath;
}


// for pass by reference
int Area2(Rectangle &r)
{
    r.Length++;
    r.Breath++;
    return r.Length * r.Breath;
}


// for pass by address
int Area3(Rectangle *R)
{   
    R->Length++;
    R->Breath++;
    return R->Length * R->Breath;
}


#include<iostream>
using namespace std;

int main()
{
    Rectangle R1 = {5,7};

    // pass by value
    cout<<Area1(R1)<<endl;      // no change in actual value


    //pass by reference
    cout<<Area2(R1)<<endl;      // actual value change as function do


    //pass by address
    cout<<Area3(&R1)<<endl;     // actual value change as function do


    return 0;
}