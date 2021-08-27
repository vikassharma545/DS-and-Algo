// in this reurtion type one or more funtion calling each other in cyclic way

#include<iostream>
using namespace std;

void FunB(int n);

void FunA(int n)  // Function A
{
    if(n>0)
    {
        cout<<n<<" ";
        FunB(n-1);      // calling function --> B
    }
}   

void FunB(int n)  // Function B
{
    if (n>0)
    {
        cout<<n<<" ";
        FunA(n/2);     // calling function --> A
    } 
    
}
    
int main()
{
    FunA(50);
   
    return 0;
}