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
#define BREAK cout << "--------------------------------------------------------------------" << endl
#define LABEL(i, title) cout << " " << i << " - " << title << " :-" << endl
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)

void mino()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int num1, num2;
string name;

int main()
{
    LABEL(1, "the easy way freopen C style ");

    // this means will take the input from input.txt file
    //  when use cin
    freopen("input.txt", "rt", stdin);
    // this means will take the output from output.txt file
    // when use cout
    freopen("output.txt", "wt", stdout);

    cin >> num1 >> num2;
    cout << "the sum is : " << num1 + num2 << endl;

    cin >> name;
    cout << "name is : " << name << endl;

    BREAK; //---------------------------------------------------------------------!SECTION

    LABEL(1, "fstream and ostream");

    // this means will take the input from input.txt file
    //  when use cin
    ifstream inStream("input1.txt");
    if (inStream.fail())
    {
        cout << "cannot open the file" << endl;
        return 0;
    }
    // this means will take the output from output.txt file
    // when use coutss
    ofstream outStream("output1.txt");
    if (outStream.fail())
    {
        cout << "cannot open the output file" << endl;
        return 0;
    }

    inStream >> num1 >> num2;
    outStream << "the sum is : " << num1 + num2 << endl;

    inStream >> name;
    outStream << "name is : " << name << endl;
    // if it empty use flush
    outStream << "using flush ,name is : " << name << endl
              << flush;

    // very important to close the stream after finishing from using it
    inStream.close();
    outStream.close();
}