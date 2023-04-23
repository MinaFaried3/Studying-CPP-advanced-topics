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

// function overloading
void f1(int &a) { cout << "f1(int &a) \n"; }
void f1(const int &a) { cout << "f1(const int &a) \n"; }
void f2(int &a) { cout << "f2(int &a) \n"; }
void f2(const int &a) { cout << "f2(const int &a) \n"; }
void f2(int &&a) { cout << "f2(int &&a)\n"; }

//--------------------------------------------------------------
void fo1(int a) { cout << "fo1\n"; }
void fo2(int &a) { cout << "fo2\n"; }
void fo3(const int &a) { cout << "fo3\n"; }
void fo4(int &&a) { cout << "fo4\n"; }
int main()
{
    LABEL("lvalue,rvalue reference");
    { // lvalue reference (binds only to lvalue)
        int a = 10;
        int &lvalue_ref = a;
        int t = 2 * a + 1;
        // Create some temp in memory
        // Put value 2*a+1 in it
        // *** Copy the temp to addressof t

        // since c++11: rvalue reference: Reference to temporary objects
        // && (double ampersand): rvalue reference operator

        int &&r1 = 2 * a + 1; // 2*a+1 is temporary expression = prvalue
                              //! int &&r2 = a; //the (a) must be prvalue
                              // Create some temp in memory
                              // Put value 2*a+1 in it
                              // *** Put the temp ADDRESS in r1
                              // no EXTRA copy => A LOT OF performance GAIN for heavy objects
                              // Logic: temp will be gone soon, why not making use of it

        // CE: rvalue reference (binds only to rvalues)
        // int &&r2 = a;
    }

    BREAK; //------------------------------------------------------

    LABEL("parameters");
    {
        int x = 1;       // lvalue
        int &y = x;      // lvaue reference
        const int z = 2; // const lvalue

        f1(x);  // f1(int &a)
        f1(y);  // f1f1(int &a)
        f1(z);  // f1(const int &a)
        f1(10); // f1(const int &a)

        f2(x);  // f2(int &a)
        f2(y);  // f2(int &a)
        f2(z);  // f2(const int &a)
        f2(10); // ff2(int &&a) *****
                // prvalue first priority matching is rvalue reference
                // why? It can avoids us extra copies!}
    }
    BREAK; //------------------------------------------------------

    LABEL("variable type != value category");
    {
        int &&r1 = 10;

        // 21 0x7fff41e81d00 4
        cout << r1 << " " << &r1 << " " << sizeof(r1) << "\n";

        int *p = &r1; // r1 is an lvalue here

        // variable type != value category
        // r1 variable type = rvalue reference &&
        // the NAME of a variable is lvalue, regardless of type
        // As it has identifiable address &r1
        // value_category is BASED on a property of the EXPRESSION

        // Every expression has a type, and belongs to a value category
        // 2 independent properties
        // Value category is a classification of expression not a value

        int x = 1;
        int &y = x; // type: lvalue reference. y value category = lvalue
    }
    BREAK; //------------------------------------------------------

    LABEL("more tips");
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
    BREAK; //------------------------------------------------------
}