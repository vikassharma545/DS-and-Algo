// Difference Betwwen uppercase and lowercase is 32
// A = 65   a = 65 + 32 = 97
// B = 66   b = 66 + 32 = 98
// .
// .
// Z = 90   z = 90 + 32 = 122

#include <iostream>
using namespace std;

void Toggle_Case(string &s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 65 && s[i] <= 91)
            s[i] += 32;
        else if (s[i] >= 97 && s[i] <= 122)
            s[i] -= 32;
    }
}

int main()
{
    string str = "Vikas Sharma";

    cout << str << endl;
    Toggle_Case(str);
    cout << str << endl;

    return 0;
}