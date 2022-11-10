#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <tuple>
#include <cmath>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cctype>
using namespace std;
#define lol long long int
#define endl '\n'
// * 1- notice that global and static int variables has initialized with 0;
int global;
string str1; // empty string
char chr;    // empty char
// 2 * using const to make sure not changing the passed arguments by reference
void toLower(const string &str)
{
    // for (char &x : str) //syntax error
    static int x;
    cout << "static x = " << x << endl;
    x++;
    for (int i = 0; i < str.size(); i++)
    {
        // str[i] = tolower(str[i]); //syntax error,can't override
    }
}
// 3 * checking if string starts with substring at pos
bool isStartWith(string str, string sub, int pos)
{
    if (pos + sub.size() > str.size())
        return false;

    for (size_t i = 0; i < sub.size(); i++)
    {
        if (sub[i] != str[pos + i])
            return false;
    }

    return true;
}

string changeWith(string str, string sub, string change)
{
    string result = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (isStartWith(str, sub, i))
        {
            result += change;
            i += sub.size() - 1;
        }
        else
        {
            result += str[i];
        }
    }

    return result;
}
int main()
{
    cout << "global int variables has initialized with  : " << global << endl;
    cout << "global string variables has initialized with empty : " << str1 << endl;
    cout << "global char variables has initialized with empty : " << chr << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // 2 * using const to make sure not changing the passed arguments by reference
    string name = "MINO";
    toLower(name);
    toLower(name);
    toLower(name); // notice the result of x static member
    cout << name << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // 3- isupper doesn't return bool. It returns value != 0 if true
    cout << isupper('C') << endl;

    string word = "aabbabaaabababaaaaabababab";

    cout << changeWith(word, "aab", "x");
}