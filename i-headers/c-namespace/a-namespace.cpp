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
#define loop0(n) for (size_t i = 0; i < n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define loopSz(i, v) for (int i = 0; i < sz(v); ++i)
#define BREAK cout << endl \
                   << "--------------------------------------------------------------------" << endl
#define LABEL(i, title) cout << " " << i << " - " << title << " :-" << endl \
                             << endl;
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)

//* 1 basics of namespace
// Global scope. Can't declare twice
int total_users = 0;

namespace OurSystem
{
    // Visible globally only within OurSystem
    int total_users = 10;

    // Define ALL of your system with such name space
}

namespace OurSystem
{
    // int total_users = 10; CE

    const int SIZE = 10;
}

namespace DownloadedSystem
{

    int total_users = 20;
}
//----------------------------------------------------------------------
// * 2 -using keyword
namespace Customer
{
    int first = 1, second = 2;
}

namespace Admin
{
    int total = 5;
}
// Let first be visible through whole file
using Customer::first;

int main()
{
    LABEL(1, " basics of namespace");
    cout << "OurSystem::total_users " << OurSystem::total_users << endl;
    cout << "DownloadedSystem::total_users  " << DownloadedSystem::total_users << endl;
    cout << "OurSystem::SIZE " << OurSystem::SIZE << endl;

    BREAK; //----------------------------------------------------------------------

    // Easier for repetitive us:
    // But be careful of local collisions
    cout << "using Customer::first; " << first << "\n";

    // second NOT visible
    // cout << second <<,"\n";
    // cout << second << "\n";

    using namespace Customer;
    cout << "using namespace Customer; " << second << "\n"; // valid now

    // Let total be visible through the function
    using Admin ::total;
    cout << "using Admin ::total;" << total << endl;
}
