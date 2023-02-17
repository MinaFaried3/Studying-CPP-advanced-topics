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

// * 1 - overriding
class A
{
public:
    int getVal()
    {
        cout << "getVal from A" << endl;
        return 1;
    }
};

class B : public A
{
public:
    int getVal()
    {
        cout << "getVal from B" << endl;
        return 2;
    }
};
//-----------------------------------------------------------

// * 2 - "Inheriting Constructor"
class parent1
{
public:
    int x;
    int y;
    parent1(int x, int y = 9) : x(x), y(y)
    {
    }
};

class child1 : public parent1
{
    int z;

public:
    // inheriting base class constructor
    using parent1::parent1;
};
//-----------------------------------------------------------

// * 3 - prevent class inheritance and overloading

class X final
{
public:
    int fun() {}
    int fun(int x) {}
    int fun(int x, int y) {}
};
// class Y : public X{};  //!can't inherit

//-----------------------------------------------------------

// * 4 - private and protected inheritance
class P
{
public:
    int x;

protected:
    int y;

private:
    int r;
};

class C : protected P
{
    // ? both x,y are protected
};

class D : private P
{ // ? both x,y are private
};
//-----------------------------------------------------------
int main()
{
    mino;
    LABEL("overriding");
    B object = B();
    cout << object.getVal() << endl;

    A object1 = B();
    cout << object.getVal() << endl;
    BREAK; //------------------------------------------------------

    LABEL("Inheriting Constructor");

    child1 ch(44);

    BREAK; //------------------------------------------------------
}