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
/*
    exception
        bad_alloc
        bad_cast
        logic_error
            length_error
            domain_error
            out_of_range
            invalid_argument
        runtime_error
            range_error
            overflow_error
            underflow_error
*/

// * 1 - logical error

void arrayAccess(int pos)
{
    vector<int> vec(5);
    vec.at(pos) = 1; //! throw an exception => out_of_range
}

double mysqrt(double x)
{
    if (x < 0)
        throw domain_error("sqrt of neg num");

    return sqrt(x);
}
double myexp(double x)
{
    double result = exp(x);
    if (result == HUGE_VAL)
        throw out_of_range("exp too large");

    return result;
}

void test(double x)
{
    try
    {
        arrayAccess(x);
        mysqrt(x);
        myexp(x);
    }
    catch (domain_error &e)
    {
        cout << "domain error" << e.what() << endl;
    }
    catch (logic_error &e)
    {
        cout << "logic error" << e.what() << endl;
    }
    catch (...)
    {
        cout << "exception happened" << endl;
    }
}
//-----------------------------------------------------------
int main()
{
}