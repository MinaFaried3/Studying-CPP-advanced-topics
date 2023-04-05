#include <set>
#include <map>
#include <array>
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

// * 2 -  combination recursive back tracking way 4 from 20 c(20,4)
vector<int> combinations;
const lol nums = 20;
lol k = 4;
lol cnt = 0;

void get_combination(int i = 0, int last_val = 0)
{
    if (i == k)
    {
        ++cnt;
        return;
    }

    for (int x = last_val + 1; x <= nums; x++)
    {
        combinations.push_back(x);

        get_combination(i + 1, x);

        combinations.pop_back();
    }
}

//-----------------------------------------------------------

int main()
{
    LABEL("combination for 4 from 20 c(20,4) iterative way");

    lol count1 = 0;

    for (int i1 = 1; i1 <= nums; i1++)
        for (int i2 = i1 + 1; i2 <= nums; i2++)
            for (int i3 = i2 + 1; i3 <= nums; i3++)
                for (int i4 = i3 + 1; i4 <= nums; i4++)
                    count1++;

    cout << count1 << endl;

    BREAK; //------------------------------------------------------

    LABEL("combination recursive back tracking way 4 from 20 c(20,4)");
    get_combination();
    cout << cnt << endl;
    BREAK; //------------------------------------------------------
}