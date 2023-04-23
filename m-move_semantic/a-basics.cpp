#include <set>
#include <map>
#include <array>
#include <list>
#include <iomanip>
#include <cmath>
#include <climits>
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
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define loop0(n) for (int i = 0; i < n; i++)
#define loop1(n) for (int i = 1; i <= n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define loopSz(i, v) for (int i = 0; i < sz(v); ++i)
#define BREAK cout << "--------------------------------------------------------------------" << endl
int numIDX = 0;
#define LABEL(title) cout << endl                                        \
                          << ++numIDX << " - " << title << " :-" << endl \
                          << endl;
#define PI 3.14159265358979323846
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)
#define sizeOf(arr) sizeof(arr) / sizeof(arr[0])
#define mino                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
lol gcd(lol a, lol b)
{
    return b == 0 ? a : gcd(b, a % b);
}
lol lcm(lol a, lol b) { return a / gcd(a, b) * b; }

int main()
{
    // Array names are non-modifiable lvalues
    int arr[]{1, 2, 3, 4};
    // arr = &x;		CE non-modifiable
    int *p = arr; // points to lvalue
    // p + 1 = arr;	// CE: p + 1 is an prvalue
    *(p + 1) = 10; // *(p + 1) is an lvalue

    // * operator converts prvalue to lvalue
    // & operator converts lvalue to prvalue

    int a = 10;
    p = &a; // a is lvalue and &a is prvalue
            // p = &(a+1);       // CE: a+1 is prvalue
    //&a = 40;          // &a is not lvalue

    // int *p2 = 10;	CE 10 is prvalue
    //  the only literal exception is c string literals, as they are arrays
    const char *char_ptr = "mostafa";

    // string &ref2 = "mostafa";
    //  CE: cannot bind non-const lvalue reference to an prvalue
    //  ref2 is non-const lvalue reference
    //  "mostafa" is prvalue

    // We can assign lvalue/prvalue to a const lvalue reference
    const string &ref2 = "mostafa";
    const char &chr = 'd';
}