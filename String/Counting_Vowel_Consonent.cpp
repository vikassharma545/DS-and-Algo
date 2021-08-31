#include <iostream>
using namespace std;

int Count_Vowel(string s)
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            count++;

    return count;
}

int Count_Consonent(string s)
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
        }
        else if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
            count++;
    return count;
}

int main()
{
    string s = "Vikas Sharma";

    cout << " Vowels = " << Count_Vowel(s) << endl;
    cout << " Consonent = " << Count_Consonent(s) << endl;

    return 0;
}