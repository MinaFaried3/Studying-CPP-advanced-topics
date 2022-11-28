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
#define loop0(n) for (size_t i = 0; i < n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define BREAK cout << "--------------------------------------------------------------------" << endl
#define LABEL(i, title) cout << " " << i << " - " << title << " :-" << endl

//* 2- struct
struct Employee
{
    string name;
    int age;
    /* data */
};
//--------------------------------------!SECTION

//* 4-value and reference
pair globalPair{"MINO", 33};
auto returnByVal()
{
    return globalPair;
}
auto &returnByRef()
{
    return globalPair;
}
int main()
{
    //! make sure you use c++ 17 or 20
    LABEL(1, "basics of structured binding");

    int arr[]{11, 22, 33, 44};
    auto &[a1, a2, a3, a4] = arr; // by reference
    cout << "a1 = " << a1 << " a2 = " << a2 << " a3 = " << a3 << " a4 = " << a4 << endl;
    auto [b1, b2, b3, b4] = arr; // by value

    BREAK; //-------------------------------------------------------------------------------

    // struct
    LABEL(2, "struct");
    Employee employee{"mina", 21};
    auto [name1, age1] = employee;
    cout << "employee =>" << name1 << " " << age1 << endl;

    BREAK; //-------------------------------------------------------------------------------s

    // pair
    LABEL(3, "pair");
    pair<int, string> pair1{21, "gerges"};
    pair pair2{22, "koko"}; // template argument deduction
    auto &[name2, age2] = pair2;
    cout << "pair2 => " << name2 << " " << age2 << endl;

    BREAK; //-------------------------------------------------------------------------------

    // value and reference
    LABEL(4, "pair value and references");
    auto [name1, salary1] = returnByVal(); // waste in time
    cout << "auto  global by val => " << name1 << " " << salary1 << endl;

    auto &[name2, salary2] = returnByVal(); //! Compile error
    cout << "auto& global by val => " << name2 << " " << salary2 << endl;

    auto &[name3, salary3] = returnByRef(); // return the reference
    cout << "auto& global by Ref => " << name3 << " " << salary3 << endl;

    auto &&[name4, salary4] = returnByVal(); // return the value of the reference
    cout << "auto&& global by val => " << name4 << " " << salary4 << endl;

    BREAK; //-------------------------------------------------------------------------------

    // tuple
    LABEL(5, "tuple");

    tuple<string, int, bool> emp1 = make_tuple("mina", 22, true);
    auto [name5, age5, online] = emp1;
    auto [name6, age6, online] = make_tuple("mina", 22, true);

    BREAK; //-------------------------------------------------------------------------------

    // map
    LABEL(6, "map");

    map<string, string> json{
        {"name", "mino"},
        {"age", "21"},
        {"online", "true"},
    };

    for (const auto &[key, value] : json)
        cout << key << " : " << value << endl;
    BREAK; //-------------------------------------------------------------------------------

    // set
    LABEL(7, "set");

    set<int> list{2, 4, 6, 50, 4, 3};

    auto [itr, isInserted] = list.insert(29); // true
    cout << "iterator : " << *itr << ", isInserted : " << boolalpha << isInserted << endl;
    auto [itr1, isInserted1] = list.insert(50); // false
    cout << "iterator1 : " << *itr1 << ", isInserted1 : " << boolalpha << isInserted1 << endl;

    if (auto [itr1, success] = list.insert(30); success)
        cout << "success insert for 30" << endl;
    else
        cout << "fail insert for 30" << endl;

    BREAK; //-------------------------------------------------------------------------------
}