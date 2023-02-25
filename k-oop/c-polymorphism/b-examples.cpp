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

// * 1 - shape and rectangle

class Shape
{
private:
    string name;

public:
    Shape(string name) : name(name) {}

    virtual int area()
    {
        throw logic_error("not implemented , do Override");
        return -1;
    }

    string getName() { return name; }

    virtual ~Shape() {}
};

class Rectangle : public Shape
{
    int width, height;

public:
    Rectangle(string name, int width, int height) : Shape(name), width(width), height(height) {}
    int area()
    {
        return width * height;
    }
};

void proccess(Shape *shape)
{
    cout << " name = " << shape->getName() << endl;
    cout << " area = " << shape->area() << endl;
}
//-----------------------------------------------------------

int main()
{
    LABEL(" shape and rectangle");

    Rectangle rec("Nice rect", 4, 5);
    proccess(&rec);

    BREAK; //------------------------------------------------------
}