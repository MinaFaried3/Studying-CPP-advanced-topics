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

// * 1 - prevent overriding

class Shape1
{
public:
    virtual void area() final
    { // final to prevent overriding
        return;
    }
};

class Rectangle1 : public Shape1
{
public:
    //  void area(){} //!error
};

//-----------------------------------------------------------

// * 2 -  override

class Shape2
{
public:
    virtual void area()
    {
        cout << "area form shape" << endl;
    }

};

class Rectangle2 : public Shape2
{
public:
    void area() override { cout << "area form rec" << endl; }

};

//-----------------------------------------------------------
int main()
{
    LABEL("override test");
    Shape2 *rec = new Rectangle2();
    rec->area();


    BREAK; //------------------------------------------------------
}