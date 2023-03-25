#include <set>
#include <map>
#include <array>
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
#define sizeOf(arr) sizeof(arr) / sizeof(arr[0])
#define mino                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// *  - C++ prevents classes from initializing inherited member variables in the initialization list of a constructor.
/*
In constructors, line 25, C++ prevents classes from initializing inherited member variables in the initialization list of a constructor.
Why? Think in cases that languages designers considered


1) Because const variables must be initialized with a value at the time of creation, the base class constructor must set its value when the variable is created.

2) However, when the base class constructor finishes, the derived class constructors initialization lists are then executed.
Each derived class would then have the opportunity to initialize that variable, potentially changing its value!
By restricting the initialization of variables to the constructor of the class those variables belong to,
C++ ensures that all variables are initialized only ONCE.
*/

class Base
{
protected:
    int value_;
    const int time;

public:
    Base() : time(0)
    {
        cout << "Default constructor for BASE class" << endl;
    }
    // !const variables must be initialized with a value at the time of creation, the base class constructor must set its value when the variable is created.
    Base(int value) : value_(value), time(0)
    {
        /*
            Here’s what actually happens when base is instantiated:

            1  Memory for base is set aside
            2  The appropriate Base constructor is called
            3  The member initializer list initializes variables
            4  The body of the constructor executes
            5  Control is returned to the caller
        */
        value_ = value * 10; // the body of constructor execute after the initializer list
        std::cout << "Base constructor called" << endl;
    }

    int getValue_() { return value_; }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Default constructor for DERIVED class" << endl;
    }
    Derived(int value1, int value2) : Base(value1), value2_(value2)
    {
        /*
        Here’s what actually happens when derived is instantiated:

            1 Memory for derived is set aside (enough for both the Base and Derived portions)
            2 The appropriate Derived constructor is called
            3 The Base object is constructed first using the appropriate Base constructor. If no base constructor is specified, the default constructor will be used.
            4 The member initializer list initializes variables
            5 The body of the constructor executes
            6 Control is returned to the caller
        */

        std::cout << "Derived constructor called" << endl;
    }

private:
    int value2_;
    int f00;
};

// *  - notice the output
class A
{
public:
    A(string str) { cout << "Constructor " << str << "\n"; }
    ~A() { cout << "~A\n"; }
};

class B
{
    A a1;

public:
    B() : a1(A("Most"))
    {
        cout << "Constructor B"
             << "\n";
    }
    ~B() { cout << "~B\n"; }
};

class C : public B
{
    A a2;

public:
    C() : a2(A("Ali"))
    {
        cout << "Constructor C"
             << "\n";
    }
    ~C() { cout << "~C\n"; }
};
//-----------------------------------------------------------

int main()
{
    LABEL("base constructor");
    Base b1(3);
    cout << b1.getValue_() << endl;
    BREAK; //------------------------------------------------------

    LABEL("by default derived constructor call default constructor if exists");
    Derived d1;
    BREAK; //------------------------------------------------------
    LABEL("notice the output");
    C c;
    /*

This is an exmple for both inheritance and composition

Constructor Most
Constructor B
Constructor Ali
Constructor C
~C
~A
~B
~A


Note, this pointer is not created = no output

Also note: Destroctor doesn't mean destroying

Construction:
    Derived allocated
    Base allocated
    Base constructor called
    Derived constructor called

Destruction:
    Derived destructor called
    Base destructor called
    Base deallocated
    Derived deallocated

Src: https://stackoverflow.com/questions/654428/what-is-the-order-in-which-the-destructors-and-the-constructors-are-called-in-c

 */

    BREAK; //------------------------------------------------------

    return 0;
}