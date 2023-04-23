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

class MyPairMC
{
private:
	int first, second;

public:
	void print()
	{
		cout << "(" << first << "," << second << ")\n";
	}
	int GetFirst() const
	{
		return first;
	}
	void SetFirst(int first)
	{
		this->first = first;
	}
	int GetSecond() const
	{
		return second;
	}
	void SetSecond(int second)
	{
		this->second = second;
	}

	MyPairMC(int x) : MyPairMC(x, x)
	{
		cout << "MyPair(int x)" << endl;
	}

	MyPairMC(int first, int second) : first(first), second(second)
	{
		// cout << "MyPair(int first, int second)" << endl;
	}
};

MyPairMC operator+(const MyPairMC &c1, const MyPairMC &c2)
{
	cout << "operator+" << endl;
	return MyPairMC(c1.GetFirst() + c2.GetFirst(),
					c1.GetSecond() + c2.GetSecond());
}

int main()
{
	LABEL(" Converting constructor MyPair(int x)");
	MyPairMC w = 5; // Converting constructor MyPair(int x)
	w.print();
	BREAK; //------------------------------------------------------

	MyPairMC x(1, 2);
	MyPairMC z1 = x + 5.3;
	z1.print();
	MyPairMC z2 = 3 + x;
	z2.print();
	MyPairMC z3 = 3 + x + 5;
	z3.print();

	return 0;
}
