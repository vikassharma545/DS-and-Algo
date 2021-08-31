#include <iostream>
#include <algorithm>
using namespace std;

//Using recurtion backtracking
void permutation(string s, int k)
{
    static int flag[10] = {0};
    static char result[10];
    int i;
    static int count = 1;
    if (s[k] == '\0')
    {
        result[k] = '\0';
        cout << count++ << " :";
        for (int i = 0; result[i] != '\0'; i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (flag[i] == 0)
            {
                result[k] = s[i];
                flag[i] = 1;
                permutation(s, k + 1);
                flag[i] = 0;
            }
        }
    }
}

//Using recurtion swaping
void Permutation2(string s, int low, int high)
{
    int i;
    if (low == high)
    {
        cout << s << endl;
    }
    else
    {
        for (i = low; i <= high; i++)
        {
            swap(s[low], s[i]);
            Permutation2(s, low + 1, high);
            swap(s[low], s[i]);
        }
    }
}


int main()
{
    string s1 = "vikas";

    // permutation(s1, 0);
    Permutation2(s1, 0, 4);

    return 0;
}