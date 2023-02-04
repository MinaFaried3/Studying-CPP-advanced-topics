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

// 2 - compare double
string compare_doubles(double a, double b, double EPS = 1e-10)
{
    if (fabs(a - b) <= EPS)
        return "a = b";
    if (a < b)
        return "a < b";
    if (a > b)
        return "a > b";
}

int main()
{

    BREAK //------------------------------------------------------
        LABEL("solve to compare compare double");

    double a = 3.0 / 7.0;
    double b = 1 + 3.0 / 7.0 - 1;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "a == b : " << boolalpha << (a == b) << endl; // notice is false
    cout << "a - b : " << setprecision(20) << (a - b) << endl;
    cout << "compare_double(a,b) = " << compare_doubles(a, b) << endl;

    a = 5.0;
    b = 4.999999999;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a == b : " << boolalpha << (a == b) << endl; // notice is true
    cout << "compare_double(a,b) = " << compare_doubles(a, b) << endl;
    cout << "compare_double(a,b) = " << compare_doubles(a, b, 1e-8) << endl; // 1e-8 > 1e-10

    BREAK //------------------------------------------------------
        LABEL("looping using double counter");
    int cnt = 0;
    for (double i = 0.0; i != 1.0; i += 0.5)
        ++cnt; // 2 *
    cout << cnt << "  0.5 : *";
    cout << endl;
    cnt = 0;
    for (double i = 0.0; i != 1.0; i += 0.2)
        ++cnt; // 5 #
    cout << cnt << "  0.2 : #";
    cout << endl;

    // for (double i = 0.0; i != 1.0; i += 0.1) //!infinity loop
    //     cout << "0.1 : "
    //          << "$" << endl;

    /*
       ? because 0.1 in binary = 0.0(0011) not 0.100000000000
    */
    cnt = 0;
    for (double i = 0.0; i < 1.0; i += 0.1)
        ++cnt; //?works
    cout << cnt << " 0.1 : $";
    cout << endl;

    BREAK //------------------------------------------------------
        LABEL("setprecision") double c = 3.14159;
    cout << "setprecision(5) : " << setprecision(5) << c << '\n';
    cout << "setprecision(9) : " << setprecision(9) << c << '\n';
    cout << "Fixed : " << fixed;
    cout << "setprecision(5) : " << setprecision(5) << c << '\n';
    cout << "setprecision(9) : " << setprecision(9) << c << '\n';
    // 1 use with setprecision 1 Rounding
    cout << "setprecision(7) : " << setprecision(7) << 1.21658 << "\n";
    cout << "setprecision(6) : " << setprecision(6) << 1.21658 << "\n";
    cout << "setprecision(5) : " << setprecision(5) << 1.21658 << "\n";
    cout << "setprecision(4) : " << setprecision(4) << 1.21658 << "\n";
    cout << "setprecision(3) : " << setprecision(3) << 1.21658 << "\n";
    cout << "setprecision(2) : " << setprecision(2) << 1.21658 << "\n";
    cout << "setprecision(1) : " << setprecision(1) << 1.21658 << "\n";
    cout << "setprecision(0) : " << setprecision(0) << 1.21658 << "\n";

    BREAK //------------------------------------------------------
        LABEL("double vs float vs long double");
    cout << fixed;
    cout << setprecision(19);
    cout << 3.33333333333333333333333333333333333333f << '\n';
    cout << 3.33333333333333333333333333333333333333 << '\n';
    cout << 3.33333333333333333333333333333333333333L << '\n';
    // 3.3333332538604736328 for float
    // 3.33333333333333348l4 for double
    // 3.3333333333333333333 for long double
    // Observe: 1) NOT equal. 2) float is less accurate
    float f1{2147483648.0f}; //_ f has 11 significant digits
    cout << f1 << "\n";      // 2147483648.0000000000000e00000
    float f2{123456789.0f};  // 11 f has 10 significant digits
    cout << f2 << "\n";      // 123456792.0õ00000000000600000
    double d = 123456789.0;  // d has 10 significant digits
    cout << d << "\n";       // 123456789. 0000000000000000000

    BREAK

    double zero = 0.0;
    double positive_infinity = 5.0 / zero;
    cout << "positive_infinity = " << positive_infinity << endl;
    double negative_infinity = -5.0 / zero;
    cout << "negative_infinity = " << negative_infinity << endl;

    double nan = zero / zero; //! not a number (mathematically not valid )
    cout << "nan = " << nan << endl;

    if (nan == nan)
        cout << "nan is equal nan" << endl;
}