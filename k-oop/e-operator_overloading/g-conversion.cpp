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

class MyPair
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

	MyPair(int x) : MyPair(x, x)
	{
		cout << "MyPair(int x)" << endl;
	}

	MyPair(int first, int second) : first(first), second(second)
	{
		// cout << "MyPair(int first, int second)" << endl;
	}


};

MyPair operator+(const MyPair &c1, const MyPair &c2)
{
	cout << "operator+" << endl;
	return MyPair(c1.GetFirst() + c2.GetFirst(),
				  c1.GetSecond() + c2.GetSecond());
}

int main()
{
	LABEL(" Converting constructor MyPair(int x)");
	MyPair w = 5; // Converting constructor MyPair(int x)
	w.print();
	BREAK; //------------------------------------------------------

	MyPair x(1, 2);
	MyPair z1 = x + 5.3;
	z1.print();
	MyPair z2 = 3 + x;
	z2.print();
	MyPair z3 = 3 + x + 5;
	z3.print();

	return 0;
}
