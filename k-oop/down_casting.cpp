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
#define sz(v) ((int)((v).size()))
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
#define mino                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

class A
{ // must be virtual to cast
public:
    virtual ~A(){};
};

class B : public A
{
};
class C : public A
{
};
class D
{
};
int main()
{
    A *ab = new B();

    B *b = static_cast<B *>(ab); // valid conversion
    cout << "b = " << b << endl;

    C *c = static_cast<C *>(ab); // not valid conversion
    cout << "c = " << c << endl; // well get the pointer

    // D *d = static_cast<D *>(ab); // !error
    BREAK;
    B *b1 = dynamic_cast<B *>(ab); // valid conversion
    cout << "b1 = " << b1 << endl;

    C *c1 = dynamic_cast<C *>(ab); // not valid conversion
    cout << "c1 = " << c1 << endl; // null pointer

    D *d1 = dynamic_cast<D *>(ab); // null pointer
    cout << "d1 = " << d1 << endl; // null pointer
}