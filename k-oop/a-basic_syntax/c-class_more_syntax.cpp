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

// * 1 - default constructor and prevent copy constructor

class Employee
{
    int salary;
    string name;

public:
    Employee() = default; // not-user provided default constructor;

    Employee(const Employee &) = delete;
    Employee operator=(const Employee &) = delete;
};

class A
{
public:
    // user provided default constructor;
    A() {}
    int i;
};
class B
{
public:
    // not-user provided default constructor;
    int i;
};
class C
{
public:
    C() = default; // not-user provided default constructor;
    int i;
};
class D
{
public:
    // user provided default constructor;
    D();
    int i;
};
D::D() = default;

//-----------------------------------------------------------

// * 3 - Const

class Rectangle
{
    double width, height;

public:
    const double r = 0;
    Rectangle(double width = 4, double height = 8) : width(width), height(height) {}
    double calcArea() const
    {
        // width = 3;// !error const function can't change data members
        return width * height;
    }

    void setWidth(double width)
    {
        this->width = width;
    }
    void setHeight(double height)
    {
        this->height = height;
    }
};
//-----------------------------------------------------------

class Emp
{
private:
    int salary;
    string name;
    static int employees;

public:
    Emp()
    {
        ++Emp::employees;
    }

    static int getEmployeeNums()
    {
        return Emp::employees;
    }
    friend class EmpFriend;
};
int Emp::employees = 0; //! must initialize

class EmpFriend
{
public:
    void printEmp(Emp emp)
    {
        // can access private data member
        cout << emp.name << emp.salary << endl;
    }
};
int main()
{
    LABEL("default constructor and prevent copy constructor");

    Employee e1;
    // Employee e2(e1); //error
    // Employee e3 = e1; //error
    BREAK; //------------------------------------------------------

    LABEL("user and not-user default constructor");

    A A1;
    B B1;
    C C1;
    D D1;

    cout << "A1.i = " << A1.i << endl; // garbage
    cout << "B1.i = " << B1.i << endl; // garbage
    cout << "C1.i = " << C1.i << endl; // garbage
    cout << "D1.i = " << D1.i << endl; // garbage

    A A2{};
    B B2{};
    C C2{};
    D D2{};

    cout << "A2.i = " << A2.i << endl; // garbage
    cout << "B2.i = " << B2.i << endl; // 0
    cout << "C2.i = " << C2.i << endl; // 0
    cout << "D2.i = " << D2.i << endl; // garbage

    BREAK; //------------------------------------------------------

    LABEL("const in classes");

    const Rectangle rec; // const object can access only const function
    cout << "area rec = " << rec.calcArea() << endl;
    // rec.r = 5; //error
    // rec.setWidth(39); //error

    //?pointers

    const Rectangle *rec1 = new Rectangle(35.7, 66);
    cout << "area rec1 = " << rec1->calcArea() << endl; // can access only const function
    rec1 = &rec;                                        // ok not const pointer

    Rectangle const *rec2 = new Rectangle(35.7, 66);
    cout << "area rec2 = " << rec2->calcArea() << endl; // can access only const function
    // rec2->setWidth(44.5);
    rec2 = &rec; // ok not const pointer

    Rectangle *const rec3 = new Rectangle(35.7, 66);
    cout << "area rec3 = " << rec3->calcArea() << endl; // can access all
    rec3->setWidth(44.5);
    // rec3 = &rec; //  const pointer

    const Rectangle

        *const rec4 = new Rectangle(35.7, 66);
    cout << "area rec4 = " << rec4->calcArea() << endl; // can access only const function
    // rec4->setWidth(44.5);// can access only const function
    // rec4 = &rec; //  const pointer

    BREAK; //------------------------------------------------------

    LABEL("Static");
    Emp emp1;
    Emp emp12;
    Emp emp13;
    Emp emp14;
    cout << "emp nums = " << Emp::getEmployeeNums() << endl;
    BREAK; //------------------------------------------------------
}