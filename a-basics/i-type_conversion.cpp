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
#include <limits.h>
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
#define loop0(n) for (size_t i = 0; i < n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define loopSz(i, v) for (int i = 0; i < sz(v); ++i)
#define BREAK cout << endl \
                   << "--------------------------------------------------------------------" << endl;
int numIDX = 0;
#define LABEL(title) cout << endl                                        \
                          << ++numIDX << " - " << title << " :-" << endl \
                          << endl;
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)

int main()
{
    LABEL("implicit type conversion")
    cout << 20 - 30 << "\n";
    // no conversion: -ve = underflow
    unsigned int a = 20, b = 30;
    cout << a - b << "\n";  // 4294967286
    short x = 10;           // short converted here t int
    cout << x + 90 << "\n"; // 100
    // both x and 85 converted to double
    cout << x * 85 + 5.1 << "\n"; // 100.1
    // no conversion, overflow
    // cout << 2000000000 + 2000000000 << "\n";
    // convert first 2000000000 to long long
    cout << 2000000000 + 2000000000LL << "\n"; // 400000000
    // auto z = 2000000000 + 2000000000L;         // LL
    // -294967296
    long long dl = LLONG_MAX - 807; // 9223372036854775000
    double d2 = dl - 0.0;
    double d3 = dl - 100.0;
    // 92233720368547
    // 92233720368541

    // char or short values(signed or unsigned) are pro 1l int(or unsigned) before anything else happens
    char c = CHAR_MAX;     // 127
    cout << c + c << "\n"; //  254 / no overflow

    BREAK //-----------------------------------------
        LABEL("Explicit") double x = 10.5;
    // C-style casting DON'T Use
    cout << (int)x << " * " << int(x) << "\n"; // 10 10
    // C++ Style: Conversion using Cast operator
    // Express the intent of the prog rammer
    // Less readable? but may search code for casting easier
    // compile time checking ability: Safer with pointers
    cout << static_cast<int>(x) << "\n"; // 10
    char c = 10;                         // 1 byte
    int *pl = (int *)&c;                 // 4 bytes BAD no CE
    // int *p2 = static_cast<int>(&c);      // CE
    // const_cast: Removes the const modifier DON'T
    // reinterpret_cast to cast any pointer or integral type
    // to any other pointer or integral DON'T
}