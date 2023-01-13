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
#include <limits.h>
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
#define loop0(n) for (size_t i = 0; i < n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define loopSz(i, v) for (int i = 0; i < sz(v); ++i)
#define BREAK cout << endl \
                   << "--------------------------------------------------------------------" << endl;
int numIDX = 0;
#define LABEL(title) cout << ++numIDX << " - " << title << " :-" << endl \
                          << endl;
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)

int main()
{
    LABEL("Short, signed, unsigned");
    short normalMaxShort = SHRT_MAX;
    short normalMinShort = SHRT_MIN;
    cout << "range for normal short : " << normalMinShort << " : " << normalMaxShort << endl;

    //! circular

    normalMaxShort++; //! overflow back to SHRT_MIN = -32768 think in it as circular
    cout << "overflow normalMaxShort++ : " << normalMaxShort << endl;

    normalMinShort--; //! underflow back to SHRT_MAX = 32767 think in it as circular
    cout << "underflow normalMinShort-- : " << normalMinShort << endl;
    normalMaxShort = SHRT_MAX;
    normalMinShort = SHRT_MIN;

    normalMaxShort += normalMaxShort;
    cout << "after adding normalMaxShort " << normalMaxShort << endl; // -2
    normalMaxShort += normalMaxShort;
    cout << "after adding normalMaxShort " << normalMaxShort << endl; // -4
    normalMaxShort += normalMaxShort;
    cout << "after adding normalMaxShort " << normalMaxShort << endl; // -8

    normalMaxShort = SHRT_MAX;
    normalMaxShort -= normalMaxShort;
    cout << "after subtracting normalMaxShort " << normalMaxShort << endl; // 0
    normalMaxShort = SHRT_MAX;
    normalMaxShort -= normalMaxShort - 1;
    cout << "after subtracting normalMaxShort - 1 : " << normalMaxShort << endl; // 1

    normalMaxShort = SHRT_MAX;
    normalMaxShort += normalMinShort;
    cout << "after adding normalMinShort to normalMaxShort " << normalMaxShort << endl; // -2

    normalMinShort -= SHRT_MIN;
    cout << "after subtract normalMinShort " << normalMinShort << endl; // 0
    normalMinShort -= SHRT_MIN;
    cout << "after subtract normalMinShort " << normalMinShort << endl; // 0

    BREAK
    unsigned short unsignedMaxShort = USHRT_MAX;
    cout << "range for unsigned short : " << 0 << " : " << unsignedMaxShort << endl;

    unsignedMaxShort++; //! overflow back to 0 think in it as circular
    cout << "overflow unsignedMaxShort++ : " << unsignedMaxShort << endl;

    unsignedMaxShort = -1; //! underflow back to 0 then to 0xffff = 65535
    cout << "underflow unsignedMaxShort = -1 : " << unsignedMaxShort << endl;
    unsignedMaxShort = -2; //! underflow back to 0 then to 65534
    cout << "underflow unsignedMaxShort = -2 : " << unsignedMaxShort << endl;

    BREAK
    LABEL("Literals with Suffix")
    cout << "int : " << 2 << endl;
    cout << "unsigned int : " << 2u << endl;
    cout << "long : " << 2l << endl;
    cout << "long long : " << 2ll << endl;
    cout << "double : " << 2.2 << endl;
    cout << "float : " << 2.2f << endl;
    cout << "ULLONG_MAX ; " << ULLONG_MAX << endl;
    // cout << 18446744073709551615 << endl; //error
    cout << "ull : " << 18446744073709551615ull << endl;
    BREAK

    LABEL("Scientific Notation")
    cout << 43030 << " " << 4.3030e4 << endl;
    cout << 0.004303 << " " << 4.303e-3 << endl;
    cout << 6.7 << " " << 6.7e0 << endl;
    cout << 6.7 << " " << 6.7e+000 << endl;

    cout << "46521364.323 = " << 46521364.323 << endl;

    // to force printing Scientific
    cout.setf(ios::scientific);
    cout << 6.7 << endl;        // 6.700006e+00
    cout << 9876543.21 << '\n'; // 9.87654e+06

    cout << 0.0000000008 << endl; // 8.000000e-10
    cout << 146000.001 << "\n";   // 1.460000e+05

    std::cout.precision(10);
    cout << 146000.001 << "\n"; // 1.4600000100e+05

    // back use standard not scientific
    cout.setf(ios::fixed, ios::floatfield);

    // show the decimal point for all floating point numbers
    cout << 100.0 << endl;
    cout.setf(ios::showpoint);
    cout << 146000.001 << endl; // 146000.0016000000
}
