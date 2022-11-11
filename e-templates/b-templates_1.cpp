#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <tuple>
#include <cmath>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define lol long long int
#define endl '\n'

// * 1 dynamic array in class template
template <class T, int size>
struct Queue
{
    T arr[size];
};

//-------------------------------------------------------------------------
// * 2 example
template <class T>
struct MyNumber
{
    T item;

    bool equal(T another)
    {
        return item == another;
    }
};

template <>
struct MyNumber<double>
{
    double item;

    bool equal(double another)
    {
        cout << "double " << fabs(item - another) << endl;
        if (fabs(item - another) < 0.00001)
            return true;
        return false;
    }
};
int main()
{
    cout << "* 1 dynamic array" << endl;

    //? Queue is a class template not a class.Queue<int,12> is a class that the compiler will generate
    //! All template functions and classes are generated in the compilation time. not runtime

    /*
    C++ is a statically typed language.
    Types cannot be determined at runtime.
    The type of every expression must be known at compile time.
    Even when a variable is declared auto,
    its type is fixed at compile time.
    */

    Queue<int, 12> qu;
    qu.arr[0] = 4;

    cout << "---------------------------------------------------------" << endl;
    cout << " * 2 example" << endl;
    MyNumber<double> num;
    num.item = 0.1;

    double d = 3 * 0.1 - 2 * 0.1;

    cout << num.equal(d);

    cout << "---------------------------------------------------------" << endl;
}
