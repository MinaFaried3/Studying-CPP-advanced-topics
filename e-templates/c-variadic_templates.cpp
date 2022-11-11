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

// * 1 basic syntax
template <class... Args>
void Hello(Args... args)
{
    int argsNum = sizeof...(args);

    cout << argsNum << " args : " << __PRETTY_FUNCTION__ << endl;
}
//-------------------------------------------------------------------------------------
// * 2 sum with variadic
int sum() // this fun is base case here
{
    return 0;
}

template <typename... Args>
int sum(int num, Args... args)
{
    return num + sum(args...);
}
//-------------------------------------------------------------------------------------
// * 3 sum with variadic template
template <typename Type>
Type sumType() // this fun is base case here
{
    return 0;
}

template <typename type, typename... Args>
type sumType(type num, Args... args)
{
    return num + sumType<type>(args...);
}

//-------------------------------------------------------------------------------------
// * 4 printing different types
void print()
{
    cout << endl;
}

template <typename type, typename... Args>
void print(const type &thing, const Args &...args)
{
    int argsNum = sizeof...(args);

    cout << thing;

    if (argsNum > 0)
        cout << ", ";

    print(args...);
}



int main()
{
    cout << " * 1 basic syntax" << endl;
    Hello(1, 2, 3, 4, 5);
    Hello("mina", 4.4, true, 5);
    Hello();
    cout << "------------------------------------------------------------------------" << endl;

    cout << " * 2 sum with variadic " << endl;

    cout << "1+2+3+4+5+6 = " << sum(1, 2, 3, 4, 5, 6) << endl;
    cout << "1+2 = " << sum(1, 2) << endl;

    cout << "------------------------------------------------------------------------" << endl;

    cout << " * 2 sum with variadic template " << endl;

    cout << "1+2.2+3+4.3+5+6 = " << sumType(1, 2.2, 3, 4.3, 5, 6) << endl;
    cout << "1.2+2 = " << sumType(1.2, 2) << endl;

    cout << "1+2.2+3+4.3+5+6 = " << sumType<double>(1, 2.2, 3, 4.3, 5, 6) << endl;

    cout << "------------------------------------------------------------------------" << endl;
    cout << " * 4 printing different types " << endl;

    print("mina", "faried", 21, 9.8, false);

    cout << "------------------------------------------------------------------------" << endl;
}