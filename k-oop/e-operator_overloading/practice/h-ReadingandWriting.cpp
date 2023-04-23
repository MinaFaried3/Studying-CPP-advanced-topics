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
lol gcd(lol a, lol b)
{
	return b == 0 ? a : gcd(b, a % b);
}
lol lcm(lol a, lol b) { return a / gcd(a, b) * b; }

class MyPairMC
{
private:
	int first, second;

public:
	MyPairMC() : // Empty constructor to allow using default
				 first(-1), second(-1)
	{
	}

	MyPairMC(int first, int second) : first(first), second(second)
	{
	}

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

	void operator>>(istream &input)
	{
		input >> first >> second;
	}

	void operator<<(ostream &output)
	{
		output << first << second;
	}
};

//=======================================================
// Original Src: https://en.cppreference.com/w/cpp/language/operators

class Fraction
{
private:
	int n, d;

public:
	Fraction(int n, int d = 1) : n(n / gcd(n, d)), d(d / gcd(n, d))
	{
	}
	int num() const
	{
		return n;
	}
	int den() const
	{
		return d;
	}

	Fraction &operator*=(const Fraction &rhs)
	{
		// Some math to multiply and simplify
		int new_n = n * rhs.n / gcd(n * rhs.n, d * rhs.d);
		d = d * rhs.d / gcd(n * rhs.n, d * rhs.d);
		n = new_n;
		return *this;
	}
};
std::ostream &operator<<(std::ostream &out, const Fraction &f)
{
	return out << f.num() << '/' << f.den();
}

bool operator==(const Fraction &lhs, const Fraction &rhs)
{
	return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}

bool operator!=(const Fraction &lhs, const Fraction &rhs)
{
	return !(lhs == rhs);
}

Fraction operator*(Fraction lhs, const Fraction &rhs)
{
	// Notice first param without const/ref
	return lhs *= rhs; // Don;t duplicate
}

int main()
{
	MyPairMC x, y;

	// Very weird to the used style!
	x >> cin;
	y >> cin;

	x << cout;
	y << cout;

	// Tip 1: using non-member style allow us to extend normally to have cin >>
	// Using >> for both input/output is wrong. Use operators as people expect
	// E.g. don't overload + to do - operations! The code will be misused!

	LABEL("fraction");
	Fraction f1(3, 8);
	Fraction f2 = 2 * f1;
	Fraction f3 = f1 * f2;
	Fraction f4 = f3;
	f4 *= f4;

	cout << f1 << "\n"
		 << f2 << "\n"
		 << f3 << "\n"
		 << f4;
	BREAK; //------------------------------------------------------
	return 0;
}
