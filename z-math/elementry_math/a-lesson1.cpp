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
// comparing double
int comp_double(double a, double b)
{
    if (fabs(a - b) <= 1e-10)
        return 0; // equal

    return a < b ? -1 : 1;
}
int main()
{

    // * 1- rounding value
    cout << "rounding value" << endl;
    /**
        ◼ round: nearest integer to x [halfway cases away from 0]
        ◼ floor: round down
        ◼ ceil: round up
        ◼ trunc: rounds toward zero (remove fraction)

     *
        To round to multiple of a specified amount
            round(x, m) = round(x / m) * m
            round(48.2 seconds, 15) = 45 seconds
            round(2.1784 dollars, 0.01 (1 cent) ) = 2.18 dollars
     */

    cout << "round(48.2 seconds, 15) = 45 seconds : " << round(48.2 / 15) * 15 << endl;
    cout << "  round(2.1784 dollars, 0.01 (1 cent) ) = 2.18 dollars " << round(2.1784 / 0.01) * 0.01 << endl;

    cout
        << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}