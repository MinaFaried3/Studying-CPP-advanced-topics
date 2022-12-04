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
                   << "--------------------------------------------------------------------" << endl
#define LABEL(i, title) cout << " " << i << " - " << title << " :-" << endl \
                             << endl;
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)

void mino()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// 2 - return a reference

int x = 4;
int &returnReference()
{
    cout << "x reference : " << &x << endl;
    return x;
}

//--------------------------------!SECTION

// 3- use function in overriding values
struct person
{
    string name = "mina";

    string &getName()
    {
        return name;
    }

    void print()
    {
        cout << "name : " << name << endl;
    }
};

int main()
{
    LABEL(1, "take a reference");

    int val = 3;
    int &val1 = val;
    cout << &val1 << endl;
    int val2 = 4;
    val1 = val2;
    cout << &val1 << endl;
    cout << " == "
         << "val : " << &val << endl
         << " == "
         << "val1 : " << &val1 << endl
         << " != "
         << "val2 is different: " << &val2 << endl;

    BREAK; //--------------------------------------------------
    LABEL(2, "return a reference ");

    int &y = returnReference();
    cout << "y reference : " << &y << endl;

    BREAK; //--------------------------------------------------
    LABEL(3, "use function in overriding values");

    person mina;

    //?notice the function postion
    mina.getName() = "mina faried essa";
    mina.print();

    BREAK; //--------------------------------------------------
    LABEL(4, "its null pointer");
    
    int *ptr = &val;
    if (ptr)
        cout << "ptr : " << *ptr << endl;
    ptr = nullptr;
    if (!ptr) // true if null
        cout << "ptr : "
             << "null" << endl;

    ptr = 0;  // 0 is also a nullptr
    if (!ptr) // true if null
        cout << "ptr : "
             << "null = 0" << endl;

    // ptr = 1; //compiler error
}