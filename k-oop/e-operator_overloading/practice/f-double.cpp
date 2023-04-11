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
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
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

/*
● Have u ever failed to compare
doubles directly?
○ This is due to double representation
● More worse: Map<double, >
○ Won’t work
● Never compare doubles directly
○ Either function to compare: EPS
○ Or Double class
● Create double class that supports
operators < > <= >= ==
*/

class Double
{
private:
    double d;
    const double EPS = (1e-10);

    // return -1 if a < b, 0 if equal and 1 if a > b
    int dcmp(double a, double b) const
    {
        return fabs(a - b) <= EPS ? 0 : a < b ? -1
                                              : 1;
    }

public:
    Double() : d(0)
    {
    }
    Double(double d) : d(d)
    {
    }
    bool operator<(const Double &D) const
    {
        return dcmp(d, D.d) < 0;
    }
    bool operator>(const Double &D) const
    {
        return dcmp(d, D.d) > 0;
    }
    bool operator==(const Double &D) const
    {
        return dcmp(d, D.d) == 0;
    }
    bool operator<=(const Double &D) const
    {
        return !(*this > D);
    }
    bool operator>=(const Double &D) const
    {
        return !(*this < D);
    }
};

int main()
{
    double d1 = 1 + 3.0 / 7.0 - 1;
    double d2 = 3.0 / 7.0;

    // 0.428571 0.428571 0
    // If gave true, play with similar examples
    cout << d1 << " " << d2 << " " << (d1 == d2) << "\n";

    Double cd1(d1);
    Double cd2(d2);

    cout << (cd1 == cd2) << "\n"; // true

    map<Double, string> map;
    map[cd1] = 10;
    map[cd2] = 20;

    cout << map.size(); // 1

    return 0;
}
