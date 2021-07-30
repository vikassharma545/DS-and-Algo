#include<iostream>
using namespace std;

struct Rectangle
{
    int Length;
    int Breath;
};

struct Student
{
    char name[10];
    int rollNo;
    char standard[10];
    char address[50];
};


int main()
{
    Rectangle R1;  // create object of Rectangle take memory
    R1.Length = 10;
    R1.Breath = 20;

    Rectangle R2 = {5,8}; // Create with given value in sequence
    cout<<R2.Length<<" "<<R2.Breath<<endl;

    Student S1 = {"vikas",21,"B.Sc CS","New Delhi"};
    cout<<S1.name<<endl;
    cout<<S1.rollNo<<endl;
    cout<<S1.standard<<endl;
    cout<<S1.address<<endl;



    Rectangle R3[2]= {{1,2},{3,4}};   // Array of structure  

    cout<<R3[0].Length<<endl;
    cout<<R3[0].Breath<<endl;
    
    cout<<R3[1].Length<<endl;
    cout<<R3[1].Breath<<endl;


    return 0;
}