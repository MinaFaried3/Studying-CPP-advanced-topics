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

vector<int> permutation;
int n_perm = 4, perm_cnt = 0;
bool visited[4]{0};

void print(int i, int x)
{
    cout << " i = " << i << "          "
         << "x = " << x << endl;

    cout << "permutation ";
    for (auto &&v : permutation)
        cout << v << " , ";
    cout << endl;

    cout << "visited ";
    for (int v = 0; v < 4; v++)
        cout << visited[v] << " , ";
    cout << endl;

    cout << endl
         << endl
         << endl;
}

void get_perm(int i = 0)
{
    if (i == n_perm)
    {
        ++perm_cnt;
        return;
    }

    for (int x = 0; x < n_perm; x++)
    {
        if (visited[x])
            continue;

        permutation.push_back(x);
        visited[x] = true;
        print(i, x);

        get_perm(i + 1);

        visited[x] = false;
        permutation.pop_back();
        print(i, x);
    }
}

int main()
{
    LABEL("recursion for permutation");
    get_perm();
    cout << "count " << perm_cnt << endl;
    BREAK; //------------------------------------------------------

    LABEL("c++ stl for permutation");
    int cnt = 0;
    vector<int> per = {0, 1, 2, 3};
    do
    {
        cnt++;
    } while (next_permutation(per.begin(), per.end()));

    cout << "count 4! = " << cnt << endl;

    BREAK; //------------------------------------------------------
}