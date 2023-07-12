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
#define sz(v) ((lol)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define loop(i, n) for (int i = 0; i < n; i++)
#define loopx(n) for (int x = 0; x < n; x++)
#define loopR(x, n) for (int i = x; i <= (int)(n); ++i)
#define loopSz(v) for (int i = 0; i < sz(v); ++i)
#define loopItr(structure) for (auto itr = structure.begin(); itr != structure.end(); itr++)
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
struct __lambda_unique_name {
	// For mutable: word const is removed
	void operator()(int i) const {
		cout << i;
	}
};
int main()
{
    // Pointer to vec of length 20
	auto p = make_unique<vector<int> >(20);
	*p = {1, 2, 3, 4};
	int t = 1;

	// C++14: initialize (but assign) variables in []
	auto print = [x = 10, y = 2 * t, ptr = move(p)]() {
		for (auto &v : *ptr) {
			cout<<v<<" ";
		}
	};

	print();	// 1 2 3 4

	ofstream ofs("hello.txt");

	// CE: fstream cannot be copied
	//[ofs] () mutable {};

	[&ofs] () mutable {};	// Ok: but stream used after function

	[out = move(ofs)] () mutable {	// Ok & stream closed after it
		out<<"Hello world\n";
	};











    [](int i) {cout << i;};

	// Compiler does 2 things:
	// 1) generate a unique type that cannot be named: __lambda_unique_name

	// 2) generate an instance of the type
	__lambda_unique_name obj;
	obj(10);

	// If you try to capture variables, they will be members in the class

	// Future note:
	// lambdas without state capture = can be converted to function pointers
}