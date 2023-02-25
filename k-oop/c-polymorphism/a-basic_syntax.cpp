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
// * 1 - explain problem
class A1
{
public:
    void print() { cout << "Print of A1" << endl; }
};
class B1 : public A1
{
public:
    void print() { cout << "Print of B1" << endl; }
};
//-----------------------------------------------------------

// * 2 - solution virtual key word
class A2
{
public:
    virtual void print() { cout << "Print of A2" << endl; }
    //! must make the destructor virtual also
    virtual ~A2() {}
};
class B2 : public A2
{
public:
    void print() { cout << "Print of B2" << endl; }
};
//-----------------------------------------------------------

// * 3 - trace polymorphism

class AA
{
public:
    virtual void f1() { cout << "AA::f1" << endl; } // virtual
    void f2() { cout << "AA::f2" << endl; }
    void f3() { cout << "AA::f3" << endl; }
};
class BB : public AA
{
public:
    void f1() { cout << "BB::f1" << endl; }         // virtual
    virtual void f2() { cout << "BB::f2" << endl; } // virtual
    void f3() { cout << "BB::f3" << endl; }
};
class CC : public BB
{
public:
    void f1() { cout << "CC::f1" << endl; } // virtual
    void f2() { cout << "CC::f2" << endl; } // virtual
    virtual void f3() { cout << "CC::f3" << endl; }
};
class DD : public CC
{
public:
    void f1() { cout << "DD::f1" << endl; } // virtual
    void f2() { cout << "DD::f2" << endl; } // virtual
    void f3() { cout << "DD::f3" << endl; } // virtual
};

//-----------------------------------------------------------
int main()
{
    LABEL("explain problem");
    //! notice may be cause a memory leak because will call parent destructor only

    A1 p1 = B1();
    p1.print(); // print from A1

    BREAK; //------------------------------------------------------

    LABEL(" solution virtual key word");

    A2 *p2 = new B2(); // must be a pointer
    p2->print();       // print from B2

    //? explict call
    p2->A2::print(); // print from A2

    BREAK; //------------------------------------------------------

    LABEL("test polymorphism");
    BB *d1 = new DD();

    d1->f1();
    d1->f2();
    d1->f3();
    
    cout << endl;
    
    AA *d2 = new DD();

    d2->f1();
    d2->f2();
    d2->f3();
    BREAK; //------------------------------------------------------
}