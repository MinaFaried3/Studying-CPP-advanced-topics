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
#define LABEL(title) cout << title << " :-" << endl \
                          << endl;
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)

// * 2 - throw exception
bool canPay(const int &money, const int &wanted = 0)
{
    if (money < 0 || wanted < 0)
        throw invalid_argument("invalid_argument :: can have negative money");

    if (money >= wanted)
        return true;
    else
        return false;
}

//-----------------------------------------------------
// * 3 - throw multiple exception
struct bill_exception
{
    string what()
    {
        return "error bill_exception";
    }
};
bool checkBill(const int &money, const int &cost)
{
    canPay(money);

    if (money >= 10000000)
        throw out_of_range("out_of_range :: can have more than 10000000");

    if (money < cost)
        throw 404; // can throw int or any data type
    else
        throw bill_exception();
}

int main()
{
    LABEL("1 - vector [] vs at()");
    vector<int> vec{1, 2, 3};
    cout << "vec[5] = " << vec[5] << endl; // will cout normally
    // cout << "vec.at(5) = " << vec.at(5) << endl; //will throw out_of_range exception
    try
    {
        cout << "vec.at(5) = " << vec.at(5) << endl; // will throw out_of_range exception
    }
    catch (out_of_range &err)
    {
        cout << "exception is : " << err.what() << endl;
    }

    BREAK; //---------------------------------------
    LABEL("2 - throw exception");
    try
    {
        cout << canPay(-1000, 4000);
    }
    catch (invalid_argument &err)
    {
        cout << "exception is : " << err.what() << endl;
    }

    BREAK; //---------------------------------------
    LABEL("3 - throw multiple exception");
    try
    {
        cout << checkBill(1000000, 4000);
    }
    catch (invalid_argument &err)
    {
        cout << "exception is : " << err.what() << endl;
    }
    catch (out_of_range &err)
    {
        cout << "exception is : " << err.what() << endl;
    }
    catch (bill_exception &err)
    {
        cout << "exception is : " << err.what() << endl;
    }
    catch (int &err)
    {
        cout << "exception is : " << err << endl;
    }
    catch (...) // for any exception
    {
        cout << "exception has been thrown " << endl;
    }
}