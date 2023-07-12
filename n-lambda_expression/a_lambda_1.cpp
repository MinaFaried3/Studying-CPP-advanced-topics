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

// operation: Anything that act as a function
// 		Function pointer, functor, lambda
template <typename Function>
void foreach (vector<int> &vec, Function operation)
{
    for (auto &item : vec)
        operation(item);
}

// You can't auto, but can use template
void square(int &x)
{
    x = x * x;
}

//! notice the struct
struct AddOne
{
    void operator()(auto &x)
    {
        ++x;
    }
};

auto print = [](const auto x)
{ cout << x << " "; };

int main()
{
    LABEL("Basic Syntax");
    auto fsum1 = [](int x, int y)
    {
        return x + y;
    };

    cout << "fsum1(2,3) = " << fsum1(2, 3) << endl;

    // when have more than return different type you must add the return type
    auto fsum2 = [](int x, int y) -> int
    {
        if (true)
            return 3.5; // return double
        return x + y;   // return int
    };

    cout << "fsum2(2,3) = " << fsum2(2, 3) << endl;

    BREAK; //------------------------------------------------------

    LABEL("In Other function");

    vector<int> v{1, 2, 3, 4, 5};

    auto IsOdd2 = [](int n)
    { return n % 2 != 0; };

    cout << count_if(v.begin(), v.end(), IsOdd2) << "\n"; // 3

    // Passing anonymous (unnamed) function object
    cout << count_if(v.begin(), v.end(), [](int n)
                     { return n % 2 != 0; })
         << "\n";

    cout << [](int n)
    { return n % 2 != 0; }(11)
         << "\n";

    []()
    { cout << "anonymous\n"; }(); // anonymous

    sort(begin(v), end(v),
         [](int i, int j)
         { return i > j; }); // 5 4 3 2 1

    BREAK; //------------------------------------------------------

    LABEL("High Order Function");
    vector<int> vec{1, 2, 3, 4, 5};

    foreach (vec, AddOne())
        ; // Functor
    foreach (vec, square)
        ; // Function pointer

    foreach (vec,
             [](int &x)
             { --x; })
        ;

    foreach (vec, print)
        ; // 3 8 15 24 35

    BREAK; //------------------------------------------------------
}