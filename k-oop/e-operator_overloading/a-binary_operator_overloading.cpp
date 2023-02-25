#include <set>
#include <map>
#include <array>
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
#define sizeOf(arr) sizeof(arr) / sizeof(arr[0])
#define mino                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

class MyPair
{
private:
    int first, second;

public:
    MyPair(int first, int second) : first(first), second(second)
    {
    }

    MyPair Add(const MyPair &c2)
    {
        MyPair &c1 = *this;
        return MyPair(c1.GetFirst() + c2.GetFirst(),
                      c1.GetSecond() + c2.GetSecond());
    }

    void print()
    {
        cout << "(" << first << "," << second << ")\n";
    }
    int GetFirst() const
    {
        return first;
    }
    void SetFirst(int first)
    {
        this->first = first;
    }
    int GetSecond() const
    {
        return second;
    }
    void SetSecond(int second)
    {
        this->second = second;
    }

    // //? 1- can overload  int class with one parameter functions
    MyPair operator+(const MyPair &c2)
    {
        MyPair &c1 = *this;
        return MyPair(c1.GetFirst() + c2.GetFirst(),
                      c1.GetSecond() + c2.GetSecond());
    }
};

//? 2- can overload  out class with two parameter functions
MyPair operator+(const MyPair &c1, const MyPair &c2)
{
    return MyPair(c1.GetFirst() + c2.GetFirst(),
                  c1.GetSecond() + c2.GetSecond());
}

MyPair operator+(const MyPair &c1, int x)
{
    return MyPair(c1.GetFirst() + x,
                  c1.GetSecond() + x);
}
MyPair operator*(int x, const MyPair &c1)
{
    return MyPair(c1.GetFirst() * x,
                  c1.GetSecond() * x);
}
MyPair operator-(const MyPair &c1, pair<int, int> p)
{
    return MyPair(c1.GetFirst() - p.first,
                  c1.GetSecond() - p.second);
}

int main()
{
    LABEL("basic syntax");
    MyPair XX(1, 2);
    MyPair YY(10, 20);

    // MyPair z = XX.Add(y);
    MyPair z = XX + YY;
    z.print(); // (11,22)
    BREAK;     //------------------------------------------------------

    LABEL("test more operators");
    pair<int, int> p = make_pair(1, 3);
    MyPair x(1, 2);
    MyPair z1 = x + 5; //! CE: 5+x
    MyPair z2 = 3 * x; //! CE: x * 3
    MyPair z3 = x - p; //! CE: p - x
    z1.print();        // (6,7)
    z2.print();        // (3,6)
    z3.print();        // (0,-1)

    MyPair z4 = 3 * x + 5 + x;
    BREAK; //------------------------------------------------------

    return 0;
}
