#include <set>
#include <map>
#include <array>
#include <list>
#include <iomanip>
#include <cmath>
#include <climits>
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
#define all(v) ((v).begin()), ((v).end())
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
lol gcd(lol a, lol b)
{
    return b == 0 ? a : gcd(b, a % b);
}
lol lcm(lol a, lol b) { return a / gcd(a, b) * b; }
// * 1 - without move
class Employee
{
public:
    Employee() = default;
    Employee(const Employee &emp) { cout << "Copy\n"; }
    Employee(Employee &&emp) { cout << "Move\n"; }
};
class Department
{
private:
    Employee e;

public:
    Department(Employee &&etemp) : e(etemp) {}
    Department(Employee &etemp) : e(etemp) {}
};

//-----------------------------------------------------------
// * 2 - with move
class EmployeeMV
{
public:
    EmployeeMV() = default;
    EmployeeMV(const EmployeeMV &emp) { cout << "Copy\n"; }
    EmployeeMV(EmployeeMV &&emp) { cout << "Move\n"; }
};
class DepartmentMV
{
private:
    EmployeeMV e;

public:
    DepartmentMV(EmployeeMV &&etemp) : e(move(etemp)) {}
    DepartmentMV(EmployeeMV &etemp) : e(etemp) {}
};
//-----------------------------------------------------------
// *  -
// Supports copy & move semantics
class MyPair
{
private:
    int *firstPtr = nullptr;
    int *secondPtr = nullptr;

public:
    MyPair(int first = 0, int second = 0)
    {
        cout << "Constructor\n";
        SetFirst(first), SetSecond(second);
    }

    MyPair(const MyPair &other)
    {
        cout << "Copy Constructor\n";
        SetFirst(*other.firstPtr);
        SetSecond(*other.secondPtr);
    }
    MyPair(MyPair &&other)
    {
        cout << "Move Constructor\n";
        // 1) copy pointer addresses
        firstPtr = other.firstPtr;
        secondPtr = other.secondPtr;
        // 2) Null other
        other.firstPtr = other.secondPtr = nullptr;
    }

    MyPair &operator=(MyPair &other)
    {
        cout << "Assignment lvalue\n";
        if (this == &other)
            return *this;

        if (other.firstPtr != nullptr)
            SetFirst(*other.firstPtr);

        if (other.secondPtr != nullptr)
            SetSecond(*other.secondPtr);

        return *this;
    }
    MyPair &operator=(MyPair &&other)
    {
        cout << "Assignment rvalue\n";
        if (this == &other)
            return *this;

        // Free mine
        if (firstPtr != nullptr)
            delete firstPtr;

        if (secondPtr != nullptr)
            delete secondPtr;

        // 1) copy pointer addresses
        firstPtr = other.firstPtr;
        secondPtr = other.secondPtr;
        // 2) Null other
        other.firstPtr = other.secondPtr = nullptr;

        return *this;
    }

    ~MyPair()
    {
        cout << "~MyPair()\n";

        if (firstPtr == nullptr && secondPtr == nullptr)
            cout << "\tFreed already by a move!\n";

        if (firstPtr != nullptr)
            delete firstPtr;

        if (secondPtr != nullptr)
            delete secondPtr;
    }
    void SetFirst(int first)
    {
        if (firstPtr == nullptr)
            firstPtr = new int;
        *firstPtr = first;
    }

    void print()
    {
        cout << "(" << *firstPtr << "," << *secondPtr << ")\n";
    }
    int GetFirst() const
    {
        return *firstPtr;
    }

    int GetSecond() const
    {
        return *secondPtr;
    }
    void SetSecond(int second)
    {
        if (secondPtr == nullptr)
            secondPtr = new int;
        *secondPtr = second;
    }
};
//-----------------------------------------------------------
int main()
{
    LABEL("without move");
    {
        Employee e1;
        Department d1(e1);         // copy
        Department d2(Employee{}); // copy
    }
    BREAK; //------------------------------------------------------
    LABEL("with move");
    {
        Employee e1;
        Department d1(e1);         // copy
        Department d2(Employee{}); // copy
    }
    BREAK; //------------------------------------------------------
    LABEL("move risks ");
    {
        vector<MyPair> v;
        MyPair p1(2, 5);
        MyPair &&pr = std::move(p1); // like ours, but generic

        v.push_back(pr);            // lvalue :)
        v.push_back(std::move(p1)); // rvalue ref

        v.back().print();
        // p1.print();		// RTE: pointers are null now

        // Let's reuse. Our set functions create new memo if needed
        p1.SetFirst(10);
        p1.SetSecond(20);
        p1.print();
    }
    BREAK; //------------------------------------------------------
    return 0;
}
