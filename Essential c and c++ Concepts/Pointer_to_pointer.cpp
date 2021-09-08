// use to store address of pointer 
// use to create (array of pointer) inside heap ---> very important
// use to create array of (arrays of different size) inside heap
#include <iostream>
using namespace std;

int main()
{
    int p1 = 20;    // variable inside stack

    int *p2 = &p1;  // pointer inside stack of (int data type)

    int **p3 = &p2;   // p3 simply a pointer inside stack which can store int type pointer address only 

    // run program and analysis youself
    cout << p1 << " = " << *p2 << " = " << **p3 << endl;
    cout << endl;
    cout << &p1 << " = " << p2 << " = " << *p3 << endl;
    cout << endl;


    //generally     // very very important

    // datatype *p1;
    // data type may be int,float,double,or even class, structure (programmer made datatype)
    // p1 store address of variable of given data type only
    // char *c;        //pointer of charracter data type store character variable address
    
    // similar

    // data type **p;
    // data type may be int,float,double,or even class, structure (programmer made datatype)
    // p only store address of pointer of given data type
    // char **c;        //(pointer of pointer) of charracter data type store address of (pointer of char type)



    // array of pointer

    int *q1[10]; // array of pointer inside stack
    int **q2 = new int *[10]; // array of pointer inside heap




    // create whole 2d array inside heap memory

    int **p = new int *[4]; // array of pointers of int type
    p[0] = new int[10];
    p[1] = new int[20]; // array of arrays of different size
    p[0][0] = 5;
    p[1][0] = 10;

    // cout << p[0][0] << endl;
    // cout << p[1][0] << endl;

    return 0;
}