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

void fo1(int a) { cout << "fo1\n"; }
void fo2(int &a) { cout << "fo2\n"; }
void fo3(const int &a) { cout << "fo3\n"; }
void fo4(int &&a) { cout << "fo4\n"; }

int global = 20;

int prvalue()
{
    return 10;
}
int &lvalue1()
{
    return global;
}
int &lvalue2()
{
    int local = 20;
    return local; // WRONG. temp value will be destroyed
}
int &&xvalue()
{
    int t = 10;
    // return t;		// CE: bind rvaule to lvalue: int &&r = t;
    // return &t;	// CE invalid conversion from int* to int
    return 10; // WRONG. temp value will be destroyed
               // rvalue reference is JUST a reference.
               // It points to something that might be destroyed
}
int main()
{
    // ? Lvalue reference bind to lvalue
    // ? Rvalue reference bind to Rvalue

    {
        int x = 1;       // lvalue
        const int y = 2; // const lvalue
        int &z = x;      // lvalue reference
        int &&w = 10;    // rvalue reference

        fo1(x), fo1(y), fo1(z), fo1(w), fo1(10);

        fo2(x), fo2(z), fo2(w);
        // fo2(y);	CE: y is const but int &a not
        // fo2(10);	CE: cannot bind non-const lvalue reference to prvalue

        fo3(x), fo3(y), fo3(z), fo3(w), fo3(10);

        // fo4(x);	can't bind
        // fo4(y);	can't bind
        // fo4(z);	can't bind rvalue reference to lvalue ***
        // fo4(w);	can't bind rvalue reference to lvalue ***
        fo4(10);
    }

    {
        int x1 = prvalue();
        // int &x2 = prvalue();		//CE  bind lvalue to rvalue
        int &&x3 = prvalue();

        int y1 = lvalue1();
        int &y2 = lvalue1();
        // int&& y3 = lvalue();		//CE: bind rvalue to lvalue

        // int z1 = xvalue();	// Potential RTE
        // int &z2 = xvalue();	//CE  bind lvalue to rvalue
        // int&& y3 = xvalue();	// Potential RTE

        cout << x3;

        cout << "\nbye\n";
    }
    return 0;
}