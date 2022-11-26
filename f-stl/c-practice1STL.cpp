#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include <bitset>
using namespace std;

#define lol long long int
#define endl '\n'
#define loop0(n) for (size_t i = 0; i < n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define BREAK cout << "--------------------------------------------------------------------" << endl
#define LABEL(i, title) cout << " " << i << " - " << title << endl

// * 1 - valid parentheses ()[[]]

bool isValidParentheses(string expression)
{
    stack<char> parentheses;
    map<char, char> openParentheses;

    openParentheses[')'] = '(';
    openParentheses[']'] = '[';
    openParentheses['}'] = '{';

    for (char chr : expression)
    {
        if (openParentheses.count(chr)) // checks if key chr is present or not
        {
            if (parentheses.empty()) // close one must match at least one open one
                return false;

            char validOpen = openParentheses[chr];

            if (parentheses.top() != validOpen)
                return false;

            parentheses.pop();
        }
        else
        {
            parentheses.push(chr);
        }
    }

    return parentheses.empty();
}

int main()
{
    LABEL(1, "valid parentheses ()[[]]");
    string expression = "[][{{(([[]]))}}]";
    cout << "expression " << expression << " is " << boolalpha << isValidParentheses(expression) << endl;

    //----------------------------------
    BREAK;
    LABEL(2, "find full name");
    /* ?the input
     2 - find full name
1
mina
2
mina faried
3
mina faried essa
1
merna
2
merna faried

//query output
1
mina
mina  -  mina faried  -  mina faried essa  -
2
mina faried
mina faried  -  mina faried essa  -
1
merna
merna  -  merna faried  -
    */


    map<string, vector<string>> nameMap;

    int tests = 5;
    while (tests--)
    {

        string strName, fullName = "";
        vector<string> names;

        int size;
        cin >> size;
        loop(i, size)
        {
            cin >> strName;
            if (i)
                fullName += " ";

            fullName += strName;
            names.push_back(fullName);
        }

        //* very important step
        for (string str : names)
            nameMap[str].push_back(fullName);
    }

    int query = 3;
    while (query--)
    {
        string strName, fullName = "";

        int size;
        cin >> size;
        loop(i, size)
        {
            cin >> strName;
            if (i)
                fullName += " ";

            fullName += strName;
        }

        if (nameMap.count(fullName))
        {

            for (string str : nameMap[fullName])
                cout << str << "  -  ";
        }
        else
        {
            cout << "NOT EXIST" << endl;
        }

        cout << endl;
    }
}