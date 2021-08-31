#include <iostream>
using namespace std;

// find length of string
int Find_length(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
    }
    return i;
}
int main()
{
    char char_array[10] = {'v', 'i', 'k', 'a', 's'}; //---> array of character

    char char_str[10] = {'v', 'i', 'k', 'a', 's', '\0'}; //---> string
    char char_str1[10] = "vikas";                        //---> String
    char *str = "Vikas";                                 //--->Dynamically created string

    string str1 = "vikas";   // string in c++ using keyword
                                            
    cout << Find_length(char_array) << endl;
    cout << Find_length(char_str) << endl;
    cout << Find_length(char_str1) << endl;
    cout << Find_length(str) << endl;
    cout << str1.length() << endl;
    cout << str1.size() << endl;

    cout<<char_array;

    return 0;
}