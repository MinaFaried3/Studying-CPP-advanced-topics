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
lol gcd(lol a, lol b)
{
    return b == 0 ? a : gcd(b, a % b);
}
lol lcm(lol a, lol b) { return a / gcd(a, b) * b; }

struct Employee
{
    int salary = 10; // salary is lvalue

    // Return by value 			=> prvalue
    int get1() { return salary; }
    // Return by reference 		=> lvalue reference
    int &get2() { return salary; }
};
int main()
{
    int salary = 100;
    // * Salary is lvalue and 100 is prvalue

    // Salary: has some identifiable address
    // we can change it (unless const used)
    // EVERY variable name is lvalue

    //* 100: literate - a TEMPORARY value
    // No name / No identifiable address
    // Not assignable

    // Normal. Go to addressof(sal2) set value 200
    salary = 200;

    //! CE: lvalue required as left operand of assignment
    // It means 200 is not lvalue: no identifiable address to put salary
    // 200 = salary;		// Not assignable

    int a = 3, b = 2, c = 2 * a + b;
    const double D = sqrt(25.0);
    string lang = "cpp";

    // 3, 2, 2*a+b, "cpp", sqrt(25) => prvalues
    // a, b, c, D, lang             => lvalue

    // referencing an lvalue
    int &ref1 = b; // lvalue reference (non-const)
    ref1 = 20;     // ok, ref1 is addressable
    // ref1+1 = 4;	// CE ref1+1 is a prvalue = temporary

    const int &ref2 = b; // lvalue reference (const)
    // ref2 = 20;			// CE const lvalue

    // operator + needs prvalues
    c = a + b; // a and b are converted to prvalues implicitly
    // Most operators expect prvalues as their operands
    // Assignment operator requires an lvalue (lvalue = expr)

    // No name = temporary = prvalue
    vector<int>(10); // prvalue
    double{};        // prvalue
 BREAK; //------------------------------------------------------
    LABEL("");
    Employee e;

    int s1 = e.get1();

    // CE: lvalue required as left operand of assignment
    // e.get1() = 50;

    // get2 return identifiable address (lvalue)
    int s2 = e.get2();
    int &s3 = e.get2();
    s3 = 70;       // now salary = 70
    e.get2() = 50; // int &salary = 50;

    // max return "const lvalue reference" NOT prvalue  [in gcc]
    const int &r = max(2, 3);

    // in std: getline(cin, str), cout << 1, str1 = str2, or ++it
    // all return by reference => lvalue

    BREAK; //------------------------------------------------------
    return 0;
}
