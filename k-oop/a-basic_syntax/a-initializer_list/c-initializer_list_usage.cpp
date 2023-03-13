#include <iostream>
#include <vector>
using namespace std;

class ClassA
{
public:
    ClassA()
    {
        cout << "ClassA Constructor\n";
    }
};

class ClassB
{
private:
    ClassA aa; // originally this line needs to call constructor to default in begin
    int x;

public:
    ClassB(int x) : aa(ClassA()), x(x)
    {
        // Originally the constructor of classA called twice
        // Once to be default Initialized
        // Once inside the constructor

        // Moving to Initializer list, then we Initialize it before construction only once

        // Tip: Always use Initializer list
        // Note: If a member object is not initialized through a member initializer, the member object’s default constructor will be called "implicitly".
        // Avoid duplicate initialization!
    }
};

class ClassC
{
private:
    int &y;
    ClassB bb;

public:
    ClassC(int &y, const ClassB &bb) : y(y), bb(bb)
    {
        //! 1- The only way to initialize a reference is initializer list
        //! 1- The only way to initialize a class that doesn't have default constructor (e.g. Class B)  is initializer list
    }
};

// Tip: please use initializer list as much as possible!

int main()
{
    int hello = 10;
    ClassB b(5);
    ClassC cc(hello, b);
    return 0;
}
