#include <iostream>
using namespace std;

void Reverse(string &s)
{
    int i = 0, j = s.length() - 1;
    for (; i < j; i++, j--)
    {
        int t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

int main()
{
    string s = "vikas";
    cout << s << endl;
    Reverse(s);
    cout << s << endl;
    return 0;
}