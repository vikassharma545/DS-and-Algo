// recursion of type calling itself at first statement
// at calling time nothing has to perform, all funtion done at returning time
// cannot converted into loop 

#include<iostream>
using namespace std;

void Fun1(int n)   // recursive funtion
{
    if (n>0)
    {
        Fun1(n-1);  // calling itself
        cout<<n;
    }
    
}
    
int main()
{
    
    Fun1(5);

    
    return 0;
}