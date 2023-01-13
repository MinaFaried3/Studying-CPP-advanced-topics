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
#define LABEL(title) cout << title << " :-" << endl \
                          << endl;
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)

// * 1- throwing in constructor
struct person
{
    string *name;
    int *age;
    person()
    {
        name = new string{"mina"};
        throw 0;
        age = new int{50};
        cout << "person constructor" << endl;
    }
    ~person()
    {
        //! all destructors are implicitly with noexcept operator
        cout << "bye person destructor" << endl;
    }
};

//----------------------------------------------------------------
// * 2 - throw err; vs throw;
void fun3()
{
    throw runtime_error("run time error");
}
void fun2()
{
    try
    {
        fun3();
    }
    catch (runtime_error &err)
    {
        cout << "address of err in fun2 : " << &err << endl;
        throw err;
    }
}
void fun1()
{
    try
    {
        fun2();
    }
    catch (runtime_error &err)
    {
        cout << "address of err in fun1 : " << &err << endl;
        throw err;
    }
}
void fun20()
{
    try
    {
        fun3();
    }
    catch (runtime_error &err)
    {
        cout << "address of err in fun20 : " << &err << endl;
        throw;
    }
}
void fun10()
{
    try
    {
        fun20();
    }
    catch (runtime_error &err)
    {
        cout << "address of err in fun10 : " << &err << endl;
        throw;
    }
}
int main()
{
    LABEL("1- throwing in constructor");
    try
    {
        person();
    }
    catch (...)
    {
        cout << "memory leak because the creation of object dose not complete" << endl;
    }
    BREAK; //--------------------------------------------------------

    LABEL("2 - throw err; vs throw;");
    try
    {
        fun1();
    }
    catch (runtime_error &err)
    {
        cout << "address of err in main : " << &err << endl;
    }
    cout << endl
         << endl;
    try
    {
        fun10();
    }
    catch (runtime_error &err)
    {
        cout << "address of err in main  : " << &err << endl;
    }
    BREAK; //--------------------------------------------------------
}