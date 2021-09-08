#include<iostream>
using namespace std;

struct Rectangle
{
    int Length;
    int Breath;
};

int main()
{
    Rectangle R1;

    Rectangle *R2;  // pointer of structure type only it not create a dynamically location of variables inside struct  

    R2 = &R1;       // assign address of R1 to pointer R2

    R1.Length = 10;
    cout<<R1.Length<<endl;

    // Method to access data from pointer
    (*R2).Length = 20;
    cout<<(*R2).Length<<endl;

    R2->Length = 30;
    cout<<R2->Length<<endl;


    // Create Structure in heap memory using pointer

    Rectangle * R3 = new Rectangle;  // this method also applicable for c++ class 
                                    // without 'new' keyword you can only crete a pointer but not a dynamic lacotion (space) 
    R3->Length = 5;                 // of variable inside memory
    R3->Breath = 15;                // when we use 'new' it also execute constructor of class and assign memory of class variables

    cout<<R3->Length<<endl;
    cout<<R3->Breath<<endl;

    // Create array of structure in heap memory

    Rectangle * R4 = new Rectangle[2];   // array of pointer R4 inside stack 

    R4[0].Length = 2;
    cout<<R4[0].Length<<endl;

    R4[1].Length = 6;
    cout<<R4[1].Length<<endl;


    // Create array of structure in heap include array of pointer inside heap

    Rectangle **R5 = new Rectangle*[2];  // create array of pointer (structure type)

    R5[0] = new Rectangle;
    R5[1] = new Rectangle;

    R5[0]->Length = 30;
    cout<<R5[0]->Length<<endl;

    R5[1]->Length = 50;
    cout<<R5[1]->Length<<endl;

    return 0;
}