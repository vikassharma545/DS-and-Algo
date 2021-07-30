#include<iostream>
using namespace std;
    
    
int main()
{
    // Array created in stack memory

    int A[5];       // declaration (all element have garbage value)
    int B[5] = {1,2,3,4,5};     // declaraton + intialised with value
    int C[5] = {0};      // all element have intialised with zero

    A[0] = 27;  // assign value
    A[1] = 36;


    int size;
    cin>>size;
    // int C[size];  // variable sized array (show error in c language not in c++) 

    //printing using for loop
    for (int i = 0; i < 5; i++)
    {
        cout<<A[i]<<" ";
    }

    //printing using for-each loop
    for(int x:A)
    {
        cout<<x<<" ";
    }
    
    
    return 0;
}