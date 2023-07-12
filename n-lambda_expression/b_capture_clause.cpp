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
#define sz(v) ((lol)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define loop(i, n) for (int i = 0; i < n; i++)
#define loopx(n) for (int x = 0; x < n; x++)
#define loopR(x, n) for (int i = x; i <= (int)(n); ++i)
#define loopSz(v) for (int i = 0; i < sz(v); ++i)
#define loopItr(structure) for (auto itr = structure.begin(); itr != structure.end(); itr++)
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
// *  - this keyword
class Employee
{
private:
    int salary = 0;
    string name;

public:
    void hello()
    {
        // capture member variables by reference
        int a = 1, b = 5;
        auto f = [&a, this, b]()
        {
            salary = 20;
        };
        f();
        cout << salary;
    }
};
//-----------------------------------------------------------
int main()
{
    LABEL("Add Local Variable to scope");
    vector<int> vec{1, 2, 3, 4};

    int factor = 2, sum = 0;

    // [] capture clause
    // You can pass parameters by CONST-by-value or reference
    auto add_user_val1 = [factor](auto &v)
    {
        for (auto &item : v)
            item += factor;
        // factor++; // !CE: read-only variable ‘factor’
    };
    add_user_val1(vec); // apply once: 3 4 5 6

    // mutable: pass by value and allows internal updates for it
    auto add_user_val2 = [factor](auto &v) mutable
    {
        for (auto &item : v)
            item += factor;
        factor = 1000; // change it in this scope only
    };
    add_user_val2(vec);
    cout << factor << "\n"; // still 2

    BREAK; //------------------------------------------------------

    LABEL("pass it by reference");
    vec = vector<int>{1, 2, 3, 4};

    factor = 2, sum = 0;

    // [&sum] = pass by reference

    auto sum_oper = [&sum](auto &v)
    {
        for (auto &item : v)
            sum += item;
    };
    sum_oper(vec); // sum = 10
    cout << "sum = " << sum << endl;

    [&factor, sum]() {}; // factor by ref and sum by value
    BREAK;               //------------------------------------------------------

    LABEL("capture all local by val or ref");
    vec = vector<int>{1, 2, 3, 4};

    factor = 2, sum = 0;

    // [=] capture all local vars by value
    auto add_user_val = [=](auto &v)
    {
        for (auto &item : v)
            item += factor;
    };

    add_user_val(vec); // apply once: 3 4 5 6

    // [&] capture all local vars by reference
    auto sum_oper1 = [&]()
    {
        for (auto &item : vec)
            sum += item;
    };

    sum_oper1();
    cout << sum << "\n"; // 18
    BREAK;               //------------------------------------------------------

    LABEL("choose if passing by ref or val");
    int a = 1, b = 5, c = 20;
    ;

    // captures all by value, except c by reference
    [=, &c]()
    {
        c += 10;
    }();
    // c = 30
    cout << " c = " << c << endl;

    // captures all by ref, except b by value
    [&, b]() mutable
    {
        c += 10;
        b += 100;
    }();
    // b = 5, c = 40
    cout << " c = " << c << endl;
    cout << " b = " << b << endl;

    BREAK; //------------------------------------------------------

    LABEL("Static variables");
    int x = 0;
    static int y = 0;

    auto f = []() 
    {
        //++x; CE you must pass
        ++y; // static ok
    };

    f(), f(), f(); // y = 3
    cout << " y = " << y << endl;

    BREAK; //------------------------------------------------------
}