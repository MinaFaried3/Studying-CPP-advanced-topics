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

// * 1 - access modifier
class Parent
{
    // can't access from outside
    // can't access from child class
private:
    int shape;

    // can't access from outside
    // can access from child class
protected:
    string name;
    int age;

    // access from all
public:
    string face;
};

class Child : public Parent
{
public:
    void print()
    {
        cout << name << " " << age << endl;
    }
};

//----------------------------------------------------
// * 2 - multiple inheritance
class Parent1
{
};
class Child1
{
};
class Employee : public Parent1, public Child1
{
};

//-----------------------------------------------------------

// * 3 -  Constructors & destructor

class Person
{
protected:
    string name;

public:
    Person() : name("most ")
    {
        cout << "Person Default Constructor\n";
    }
    Person(string name) : name(name)
    {
        cout << "Person 2nd Constructor\n";
    }

    ~Person()
    {
        cout << "Person Destructor\n";
    }
};

class Student : public Person
{
private:
    double gpa;

public:
    Student() //: name("f") only data member of child class
    {
        cout << "Student Default Constructor\n";
        gpa = 0;
        name = "Mina";
    }

    Student(double gpa) : Person("Mino"), gpa(gpa)
    {
        cout << "Person 2nd Constructor\n";
    }

    ~Student()
    {
        cout << "Student Destructor\n";
    }
};
//-----------------------------------------------------------
int main()
{
    LABEL(" Constructors & destructor");
    Student s1;

    BREAK; //------------------------------------------------------
}