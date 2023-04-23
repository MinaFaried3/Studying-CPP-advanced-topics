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

void f2(int &a) { cout << "f2() \n"; }
void f2(int &&a) { cout << "f2&&() \n"; }

void f1(int &a)
{
    cout << "f1() \n";
    f2(a);
}
void f1(int &&a)
{
    cout << "f1&&() \n";
    f2(static_cast<int &&>(a));
}

int &&OurMove(int &x)
{
    return static_cast<int &&>(x);
}
void foo2(int &a) { cout << "foo2() \n"; }
void foo2(int &&a) { cout << "foo2&&() \n"; }

void foo1(int &a)
{
    cout << "foo1() \n";
    foo2(a);
}
void foo1(int &&a)
{
    cout << "foo1&&() \n";
    // Return of OurMove is interesting
    // It originally has identity (a)
    // It is now Rvalue Reference (can be moved)
    // This is called xvalue
    // Has identity and movable
    foo2(OurMove(a));
}
int main()
{
    {
        int x = 10;
        // By casting x to int&&, we force it be Rvalue reference
        // That we convert an Lvalue to Rvalue Reference!
        int &&xr = static_cast<int &&>(x);

        f1(10); // f1&&()    f2&&()

        // xr is a name
        // name ==> lvalue
        // Don't fotget :)
        f1(xr); // f1() f2()
    }
    {
        	foo1(10); // foo1&&()    foo2&&()
    }

    return 0;
}
