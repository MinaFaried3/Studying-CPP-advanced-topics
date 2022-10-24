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
using namespace std;
#define lol long long int
#define endl '\n'
int main()
{
    // * 1- loop from a to z
    cout << "loop from a to z: " << endl;
    for (int i = 'a'; i <= 'z'; i++)
        cout << (char)i;
    cout << endl;
    for (char i = 'a'; i <= 'z'; i++)
        cout << i;
    cout << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    // * 2- compare to strings
    cout << "compare to strings: " << endl;

    string str1 = "za", str2 = "zaaa";

    int size_ = str1.size();

    if (size_ < str2.size())
        size_ = str2.size();
    int smaller = -1;
    for (int i = 0; smaller == -1 && i < size_; i++)
        if (str1[i] != str2[i])
            if (str1[i] < str2[i])
                smaller = 1;
            else
                smaller = 0;

    if (smaller == -1)
        if (str1.size() <= str2.size())
            smaller = 1;
        else
            smaller = 0;

    if (smaller)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    // * 2- compare to strings
    cout << "compare to strings: " << endl;

    
}