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
#define LABEL(i, title) cout << " " << i << " - " << title << " :-" << endl \
                             << endl;
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)

//-----------------------!SECTION
// * 1 passing to function
void fun1(int &x)
{
}
void fun2(const int &x) {}
void fun3(int *x) {}

// * 2 struct
struct Employee
{
    int id = -1;
    string name;

    Employee() {}

    Employee(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
    void print()
    {
        cout << "name " << name << " , id = " << id << endl;
    }
};

void overflow()
{
    const lol size = 10000 * 100000;
    int arr[size];
}
int main()
{
    BREAK; //--------------------------------------------------
    LABEL(1, "passing to function");

    int x = 10;
    int *ptr = &x;

    fun1(x);
    // fun1(10);//error
    // fun1(ptr);//error
    fun1(*ptr);

    fun2(x);
    fun2(10);
    // fun2(ptr); // error
    fun2(*ptr);

    // fun3(x); //error
    // fun3(10); //error
    fun3(ptr);
    // fun3(*ptr); //error
    fun3(&x);

    BREAK; //--------------------------------------------------
    LABEL(2, "struct");

    Employee emp1(1, "mina");
    emp1.print();

    Employee *emp2{new Employee(2, "gergess")};
    emp2->print();
    (*emp2).print();

    Employee *emp3 = emp2;
    Employee *emp4{&emp1};
    emp3->print();
    emp4->print();

    Employee &emp5 = *emp2;
    emp5.id = 222;
    emp5.name = "kero";

    emp2->print();

    vector<Employee *> vecEmp;
    vecEmp.push_back(emp2);
    vecEmp.push_back(&emp5);

    BREAK; //--------------------------------------------------
    LABEL(3, "overflow");
    // overflow();

    
}