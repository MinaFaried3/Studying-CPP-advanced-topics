#include <iostream>
#include <vector>
using namespace std;

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
	}

	MyPairMC(int first, int second) : first(first), second(second)
	{
	}

	MyPairMC(pair<int, int> p) : // Use explicit
								 first(p.first), second(p.second)
	{
	}

	operator int()
	{
		return first * second;
	}
	operator double()
	{
		return (double)second / (double)first;
	}

	operator pair<int, int>()
	{
		return make_pair(first, second);
	}
};

int main()
{
	MyPairMC x(2, 3);

	int r = x; // 6
	double d = x;
	cout << r << " " << d << endl;
	pair<int, int> p = x; // operator pair<int, int>()
	x = p;				  // MyPair(pair<int, int> p)

	cout << p.first << " " << r << "\n";

	return 0;
}
