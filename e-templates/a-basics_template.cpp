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
template <typename type>
type findMax(type num1, type num2)
{
    if (num1 > num2)
        return num1;

    return num2;
}
//---------------------------------------------------------
// * 2 using 2 classes
template <class Type1, class Type2>
Type1 sum(Type1 a, Type2 b)
{
    Type1 r = a + b;
    return r;
}

//-----------------------------------------------------------
// * 3 static and global variables
int globalVAl;

template <typename T>
void increment(T num)
{
    static int staticVAl;
    cout << "static : " << staticVAl++ << " global : " << globalVAl++ << endl;
}

//-----------------------------------------------------------
// * 4 print example with overriding
template <class T>
void print(T a)
{
    cout << "[" << a << "]" << endl;
}

//! notice the difference
// 1 - this is compile error because of int return type
// template <>
// int print(string str)
// {
//     cout << "{{" << str << "}}";
//     return str.size();
// }

// 2 - turn int to void
template <>
void print(string str)
{
    cout << "{{" << str << "}}";
}

//-----------------------------------------------------------
// * 5  best way to initialize template

template <typename T>
void uniFun()
{
    // Uniform initialization can solve this problem as it works in ALL contexts.
    T t{};
}

int main()
{

    cout << "* 1 basic syntax " << endl;
    cout << findMax(2, 5) << "\n"; // 5: Guessed as int

    cout << findMax<int>(2, 5) << "\n"; // 5

    cout << findMax<double>(2.5, 5.4) << "\n"; // 5.4

    cout << findMax('A', 'X') << "\n"; // X

    // cout << findMax(2, 5.4) << "\n"; //CE: // Can't guess

    cout << findMax<int>(2, 5.4) << "\n"; // 5

    cout << findMax<double>(2, 5.4) << "\n"; // 5.4

    // Employee a, b;
    // cout - << findMax<Employee>(a, b) << "\n";    // CE: can't compare
    cout << "---------------------------------------------------------" << endl;

    cout << "* 2 using 2 classes" << endl;
    // cout << sum("I am", "Mostafa") << "\n"; //  CE: char*
    cout << sum(string("I am "), string("Mina")) << "\n";
    cout << sum(string("I am "), "Mina") << "\n";

    cout << "---------------------------------------------------------" << endl;

    cout << " * 3 static and global variabless" << endl;
    // it is make one static type for each generic function
    cout << " int " << endl;
    // for int
    increment(1);
    increment(3);
    increment(4);

    cout << " double " << endl;
    // for double
    increment(1.0);
    increment(3.3);
    increment(4.4);

    cout << "---------------------------------------------------------" << endl;

    cout << " * 4 print example with overriding " << endl;
    // notice it will execute the first function
    print(100);
    print("mina");         // char array
    print(string("mina")); // string
}