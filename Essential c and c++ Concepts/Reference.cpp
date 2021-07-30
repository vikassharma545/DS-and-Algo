// only availabel in c++ not in c language
// usefull in parameter passing

#include<iostream>
using namespace std;
    
int main()
{
    int a = 5;
    int b = 20;

    int &r = a;       // now 'r' and 'a' refer same address 
    
    cout<<a<<endl;
    cout<<r<<endl;
    a++;
    r++;              // value of 'a' also increase
    cout<<a<<endl;
    r = b;
    cout<<a<<endl;

    // int &p;        //-->>Error  you must have to intialise with some variable 

    
    return 0;
}