#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class MyPairMC
{
private:
	int first, second;

public:
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

	MyPairMC &operator++()
	{ // ++p
		++first, ++second;
		return *this;
	}
	// DON'T return MyPair&: this is local var
	MyPairMC operator++(int)
	{
		MyPairMC cpy = *this;
		++first, ++second;
		return cpy;
	}
};

int main()
{
	int a = 1;
	int c = 2 * a + 5; // 2*a+5  => prvalue expression
	c = a++;		   // a++    => prvalue expression
	++a = 10;		   // ++a    => lvalue expression
	cout << a << endl;
	// Now a = 10
	// a++ = 10;			// CE prvalue expression

	MyPairMC p(1, 2);
	++p = MyPairMC(3, 10); // if line 28 became void => CE
	(++p).print();		   // (4,11)

	// This is tricky
	// p++ is return by value so prvalue
	// but we can call member functions of prvalue
	// assign has NO effect
	// the value MyPair(200, 300) will assign to cpy variable
	p++ = MyPairMC(200, 300);

	p++.print(); // (5,12)

	// Hint: same expression on primitives might
	// be different from operator overloading

	// a * 4 = j;	// CE for primitives
	// BUT By overloading operators it could be lvalue.

	return 0;
}
