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

struct Employee1
{
    int *arr;

    Employee1()
    {
        arr = new int[5]{1, 2, 3, 4, 5};
    }
    ~Employee1()
    {
        cout << "delete arr" << endl;
        delete[] arr;
        arr = nullptr;
    }

    void print()
    {
        cout << "this = " << this << endl
             << " , *arr = " << *arr << endl
             << " , arr = " << arr << endl
             << " , &arr = " << &arr << endl;
    }
};
struct Employee2
{
    int *arr;

    Employee2()
    {
        arr = new int[5]{1, 2, 3, 4, 5};
    }
    ~Employee2()
    {
        cout << "delete arr" << endl;
        delete[] arr;
        arr = nullptr;
    }

    void print()
    {
        cout << "this = " << this << endl
             << " , *arr = " << *arr << endl
             << " , arr = " << arr << endl
             << " , &arr = " << &arr << endl;
    }

    Employee2(const Employee2 &emp) = delete;
    void operator=(const Employee2 &emp) = delete;
};
int main()
{
    Employee1 emp1, emp2;
    emp1.arr[0] = 20;

    cout << "emp 1: ";
    emp1.print();
    cout << "emp 2: ";
    emp2.print();

    emp2 = emp1;
    cout << "emp 2: ";
    emp2.print();
    Employee1 emp4 = emp1;
    /*problems
        1- memory leak because of lost emp2 created memory
        2- emp1 arr will be deleted twice = dangling = crash
    */

    Employee2 emp21, emp22;
    // emp21 = emp22;           // error
    // Employee2 emp24 = emp21; // error
}