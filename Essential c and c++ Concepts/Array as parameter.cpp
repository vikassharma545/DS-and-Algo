// Array always passed by address any change in function also reflect in actual array

#include<iostream>
using namespace std;

void fun1(int A[],int size)  // here we can also use (int *A, int size)  
{
    for (int i = 0; i < size; i++)
    {
        A[i] = (i+1);
    }
}

int* fun2(int size)
{
    int *p = new int[size];  // we can also create dynamically array

    // int p[size];            //--> not work only use pointer type array 

    for (int i = 0; i < size; i++)
    {
        p[i] = (i+1)*5;
    }
    
    return p;
}

int fun3(int *A)
{
    return sizeof(A)/sizeof(A[0]);      // return 8 divided by size of integer = 2
}

void display(int A[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<A[i]<<" ";
    }

    cout<<endl;
    
}

int main()
{
    // Pass Array as a parameter in funtion

    int Array[5] = {0};
    display(Array,5);
    cout<<endl;

    fun1(Array,5);          // here 'Array' is pointer pointing first element of array
    cout<<Array<<endl;      // give address of first element
    cout<<*Array<<endl;     // give value of first element
    cout<<*Array+1<<endl;   // give value of second element
    display(Array,5);




    // Return Array as a parameter from function

    int size = 5;
    // int A[size] = fun2(size); //  not work function return address of array

    // int A[size];
    // A = fun2(size);             // also not work

    int *p = fun2(size);        
    display(p,size);




    // Size of Array
    // sizeof(Array) = total size of array inside main function
    // sizeof(Array) = 8  always inside a function (give size of pointer)

    int A[3] = {12,2,36};

    int size1 = sizeof(A)/sizeof(A[0]);     // give Number of element in array
    cout<<size1<<endl;                             

    size1 = fun3(A);                        
    cout<<size1<<endl;                      

    return 0;
}