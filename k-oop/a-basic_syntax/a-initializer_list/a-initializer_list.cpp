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

class MyNumber
{
    int x;
    int y;

public:
    MyNumber(const initializer_list<int> &list)
    {
        x = *(list.begin());
        y = *(list.end());
    }
};

struct A
{
    int x, b;
};

struct B
{
    int x, y;
    B(int x, int y) : x(x), y{y}
    {
        cout << "Initializer list B" << endl;
    }
};
struct C
{
    int x, y;
    C(int x, int y) : x(x), y{y}
    {
        cout << "Initializer list C2" << endl;
    }

    C(const initializer_list<int> &list)
    {
        x = *(list.begin());
        y = *(list.end());
    }
};

void printVec(const vector<int> &vec)
{
    for (int x : vec)
        cout << x << " ";
    cout << endl;
}

int main()
{
    LABEL("initializer list basics syntax");

    MyNumber num({1, 2});
    A a{3, 5};
    B b{6, 9};
    C c1{4, 6}; //?initializer_list has a higher priority
    C c2(4, 6);
    BREAK; //------------------------------------------------------

    LABEL("STL");

    vector<int> v1{5, 20}; // v1 = 5 20
    cout << "v1 = ";
    printVec(v1);

    vector<int> v2(5, 20); // v2 = 20 20 20 20 20
    cout << "v2 = ";
    printVec(v2);

    auto x = {1, 3}; // save it as initializer_list
    // auto x2 = {1.5, 3}; //can't save it as initializer_list because different data types
    //  auto x3 {1, 3}; // must save one value
    auto x4 = {4}; // save it as initializer_list
    auto x5{8};    // int
    BREAK;         //------------------------------------------------------
}