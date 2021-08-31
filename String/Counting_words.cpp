#include <iostream>
using namespace std;

int Counting_words(string s)
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

int main()
{
    string s = "How are you";

    cout<<Counting_words(s);

    return 0;
}