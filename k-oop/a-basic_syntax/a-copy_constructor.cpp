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

// * 1 - Shallow Copy
class ShallowCopy
{
    int val;
    int *valPtr;

public:
    ShallowCopy(int x = 3, int y = 5)
    {
        valPtr = new int(x);
        val = y;
    }

    void printClass()
    {
        cout << "val = " << val << " : " << &val << endl;
        cout << "*valPtr = " << *valPtr << " : " << valPtr << endl;
        cout << endl
             << endl;
    }

    ~ShallowCopy()
    {
        //! error because trying to delete the same pointer twice
        // delete valPtr;
    }
};

void fun(ShallowCopy s1) {}
ShallowCopy fun()
{
    ShallowCopy s(2, 3);
    return s;
}

//-----------------------------------------------------------

// * 2 - DeepCopy

class DeepCopy
{
    int val;
    int *valPtr;

public:
    DeepCopy(int x = 3, int y = 5)
    {
        cout << "Normal Constructor" << endl;
        valPtr = new int(x);
        val = y;
    }
    DeepCopy(const DeepCopy &deep)
    {
        cout << "Copy Constructor" << endl;
        valPtr = new int(*(deep.valPtr));
        val = deep.val;
    }

    void printClass()
    {
        cout << "val = " << val << " : " << &val << endl;
        cout << "*valPtr = " << *valPtr << " : " << valPtr << endl;
        cout << endl
             << endl;
    }

    ~DeepCopy()
    {
        //! error because trying to delete the same pointer twice
        // delete valPtr;
    }
};

//-----------------------------------------------------------

// * 3 - Temporary Object

void play1(DeepCopy deep) {}
void play2(DeepCopy &deep) {}
void play3(const DeepCopy &deep) {}

//-----------------------------------------------------------

int main()
{
    LABEL("Shallow Copy");
    ShallowCopy a;
    ShallowCopy b(20, 50);

    a.printClass();
    b.printClass();

    b = a; // assignment not copy constructor

    // notice the pointer address became the same
    // this will throw error when the destructor
    b.printClass();

    ShallowCopy c(b);  // copy constructor to build c
    ShallowCopy d = b; // copy constructor to initialize in declaration

    fun(b); // copy constructor to pass object
    fun();  // copy constructor to return object

    BREAK; //------------------------------------------------------

    LABEL("Deep Copy");
    DeepCopy aD;
    DeepCopy bD(aD);

    aD.printClass();
    bD.printClass();
    BREAK; //------------------------------------------------------

    LABEL("Temporary Object");

    play1(DeepCopy());
    // play2(DeepCopy()); // temporary object can't pass to non constant object
    play3(DeepCopy()); // temporary object can pass to non constant object

    BREAK; //------------------------------------------------------
}