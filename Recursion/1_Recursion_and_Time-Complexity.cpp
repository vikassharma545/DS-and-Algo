// Name - VIKAS SHARMA
// Roll no - 20556

#include <iostream>
using namespace std;

// Recursion : Routine that call itself directly and indirectly
// example :-

void fun(int n)
{
    if (n > 0)
    {
        cout << n;
        fun(n - 1);   //---> call itself 
    }
}

// Finding Time Complexity two ways
// 1. using tree diagram  and,  
// 2. recurence relations

// tree diagram
/*
                       fun(3)
                      /   \
    1 unit ->        3    fun(2)
                         /   \
    1 unit ->           2    fun(1)
                            /   \
    1 unit ->              1    fun(0)

    total = 3 unit times

    for value of n time complexity =  O(n)

*/

//Recurence relation
/*
    let time taken for value n = T(n)

    void fun(int n)
    {
        if (n > 0)      --->  1 unit
        {
            cout << n;  --->  1 unit 
            fun(n - 1);      --->   T(n-1) 
        }
    }

    so,

            T(n) = 2 + T(n-1)
    ==>     T(n) = T(n-1) + 1
    ==>     T(n) = T(n-2) + 2        : T(n-1) = T(n-2) + 1
    .
    .
    .
    ==>     T(n) = T(n-k) + k

    n-k reach to zero
    so,
        n-k = 0
        n = k

        T(n) = T(n-n) + n
        T(n) = T(0) + n
        T(n) = 1 + n      ---->>   required time complexity
        
*/

int main()
{
    int n = 3;
    fun(3);

    return 0;
}
