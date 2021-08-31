// two main way we discuss
// 1. by hashing table
// 2. by using Bits

#include <iostream>
using namespace std;

// Using Hashing
//condition : either all letter are small or big otherwise we apply condition for both

void Find_Dublicate_Hashing(string s)
{
    int *hash = new int[26];

    for (int i = 0; s[i] != '\0'; i++)
    {
        hash[s[i] - 97]++; //----> for small letters
        // hash[s[i] - 65]++;   //----> for Capitals letters
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (hash[s[i] - 97] > 1)
        {
            cout << "Dublicate : " << s[i] << " --> Present : " << hash[s[i] - 97] << " times" << endl;
            hash[s[i] - 97] = 0;
        }
    }

    delete[] hash;
    hash = NULL;
}

// Using bit

void Find_Dublicate_Bit(string s)
{
    int hash = 0, x = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        x = 1;
        x = x << (s[i] - 97);

        if ((hash & x) > 0)
            cout << "Dublicate : " << s[i] << endl;
        else
            hash = hash | x;
    }
}

int main()
{
    string s = "Vikas sharma";

    Find_Dublicate_Hashing(s);
    Find_Dublicate_Bit(s);


    return 0;
}