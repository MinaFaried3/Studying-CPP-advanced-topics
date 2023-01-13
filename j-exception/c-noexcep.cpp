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
#define loop0(n) for (size_t i = 0; i < n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define loopSz(i, v) for (int i = 0; i < sz(v); ++i)
#define BREAK cout << endl \
                   << "--------------------------------------------------------------------" << endl;
int numIDX = 0;
#define LABEL(title) cout << ++numIDX << " - " << title << " :-" << endl \
                          << endl;
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)

// * 1- basic syntax
int my_abs(int x) noexcept
{
    if (x < 0)
        return -x;
    return x;
}
int my_abs_div(int x, int y) noexcept(true)
{
    return my_abs(x) / my_abs(y);
}
//------------------------------------------------------------------------------
int my_abs11(int x) noexcept
{
    // will have warning in terminal   throw will always call terminate() [-Wterminate]
    throw 2;
    if (x < 0)
        return -x;
    return x;
}
int my_abs_div11(int x, int y) noexcept(true)
{
    return my_abs11(x) / my_abs11(y);
}

//--------------------------------------------------------------
// * 3 - div by zero
int div_by_zero(int x, int y)
{
    return x / y;
}

int main()
{
    LABEL("basic syntax")
    cout << "my_abs_div(6, 2) : " << my_abs_div(6, 2) << endl;

    BREAK
    try
    {
        // cout << "my_abs_div11(6, 2) : " << my_abs_div11(6, 2) << endl; //terminate the program
    }
    catch (...)
    {
        cout << "error has happened" << endl;
    }
    BREAK

    LABEL("noexcept as operator")

    //? this will return true if function has noexcept or noexcept(true)
    //? this will return false if function has no noexcept or noexcept(false)
    cout << "noexcept(my_abs(4)) is " << boolalpha << noexcept(my_abs(4)) << endl;
    BREAK

    LABEL("div by zero")

    try
    {
        // cout << "div_by_zero(6, 0) : " << div_by_zero(6, 0) << endl; // terminate the program will not be catch
    }
    catch (...)
    {
        cout << "div by zero not handled" << endl;
    }

    BREAK
    LABEL("no throw")
    int sz = 10; // Huge enough to take your whole memory

    try
    { // Way 1)
        int *ptr1 = new int[sz];
        delete[] ptr1;
        ptr1 = nullptr;
    }
    catch (bad_alloc &ex)
    {
        cerr << "Failed to allocate memory: " << ex.what() << "\n";
    }

    int *ptr2 = new (nothrow) int[sz]; // Way 2)
    if (!ptr2)

        cout << "Pailed!\n";
    else
    {
        cout << "Succeeded!\n";
        delete[] ptr2;
        ptr2 = nullptr;
    }
}