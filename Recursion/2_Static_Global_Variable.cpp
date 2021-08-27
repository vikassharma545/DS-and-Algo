// Name - VIKAS SHARMA
// Roll no - 20556

#include <iostream>
using namespace std;


int fun1(int n)
{
    if (n > 0)
    {
      return fun1(n-1) + n;
    } 
    return 0;
}

int fun2(int n)
{
    static int x = 0;   //--->> static variable 
    if (n > 0)
    {
        x++;
        return fun2(n-1) + x;
    }
    return 0;
}

int main()
{
    cout<<fun1(5)<<endl;
    cout<<fun2(5)<<endl;


    return 0;
}