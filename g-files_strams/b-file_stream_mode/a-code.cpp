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

int main()
{

    auto appendMode = ios::in | ios::out | ios::app;  // this for appending at the exist text
    auto truncMode = ios::in | ios::out | ios::trunc; // this for overwrite the text

    string path = "file.txt";
    fstream fStream(path.c_str(), appendMode);

    if (fStream.fail())
    {
        cout << "cannot open the file" << endl;
        return 0;
    }

    string first, second;
    // reading from it and writing in console
    fStream >> first >> second;
    cout << "first : " << first << " second : " << second << endl;

    fStream.clear(); // to clear any errors before writing

    // writing in file
    fStream << endl
            << "age : " << 21 << endl;

    fstream fStream1(path.c_str());
    string line;
    while (getline(fStream1, line))
        cout << line << endl;

    fStream.close();
    fStream1.close();
}