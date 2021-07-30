// why we need pointer ?
// for indirectly access of data which is outside of program
// like keyboard ,monitor, harddisk, heap memory, parameter passing 

struct Rectangle
{
    int Length;
    int Breath;
};


#include<iostream>
using namespace std;
    
int main()
{
    int a = 10;         //Data variable
    int *p;             // Pointer is created (store address of data ) 
    p = &a;             // address of 'a' given to pointer 'p'
    cout<<p<<endl;      // give address of a
    cout<<*p<<endl;     // give value of a


    int *p1;        // pointer size is type independent 
    char *p2;
    float *p3;
    double *p4;
    string *p5;

    cout<<sizeof(p1)<<endl;    // all give size of 8 bytes
    cout<<sizeof(p2)<<endl;             //
    cout<<sizeof(p3)<<endl;             //          
    cout<<sizeof(p4)<<endl;             //
    cout<<sizeof(p5)<<endl;             //
    
    
    // p2 = new int[2];  //--> wrong (p2 is char type not assingn int type )
    p2 = new char[2];



    return 0;
}