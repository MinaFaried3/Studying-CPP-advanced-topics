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

class MyPairMC
{
private:
    int first, second;

public:
    MyPairMC(int first, int second) : first(first), second(second)
    {
    }

    MyPairMC Add(const MyPairMC &c2)
    {
        MyPairMC &c1 = *this;
        return MyPairMC(c1.GetFirst() + c2.GetFirst(),
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
    MyPairMC operator+(const MyPairMC &c2)
    {
        MyPairMC &c1 = *this;
        return MyPairMC(c1.GetFirst() + c2.GetFirst(),
                        c1.GetSecond() + c2.GetSecond());
    }
};

//? 2- can overload  out class with two parameter functions
MyPairMC operator+(const MyPairMC &c1, const MyPairMC &c2)
{
    return MyPairMC(c1.GetFirst() + c2.GetFirst(),
                    c1.GetSecond() + c2.GetSecond());
}

MyPairMC operator+(const MyPairMC &c1, int x)
{
    return MyPairMC(c1.GetFirst() + x,
                    c1.GetSecond() + x);
}
MyPairMC operator*(int x, const MyPairMC &c1)
{
    return MyPairMC(c1.GetFirst() * x,
                    c1.GetSecond() * x);
}
MyPairMC operator-(const MyPairMC &c1, pair<int, int> p)
{
    return MyPairMC(c1.GetFirst() - p.first,
                    c1.GetSecond() - p.second);
}

int main()
{
    LABEL("basic syntax");
    MyPairMC XX(1, 2);
    MyPairMC YY(10, 20);

    // MyPair z = XX.Add(y);
    MyPairMC z = XX + YY;
    z.print(); // (11,22)
    BREAK;     //------------------------------------------------------

    LABEL("test more operators");
    pair<int, int> p = make_pair(1, 3);
    MyPairMC x(1, 2);
    MyPairMC z1 = x + 5; //! CE: 5+x
    MyPairMC z2 = 3 * x; //! CE: x * 3
    MyPairMC z3 = x - p; //! CE: p - x
    z1.print();          // (6,7)
    z2.print();          // (3,6)
    z3.print();          // (0,-1)

    MyPairMC z4 = 3 * x + 5 + x;
    BREAK; //------------------------------------------------------

    return 0;
}
