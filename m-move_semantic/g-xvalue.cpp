#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void f1(int t) {}
int &&f2() { return 10; }

struct Employee
{
    string name;
};

int main()
{
    // x = xr = lvalue = identity
    int x = 15;
    int &&xr = 15;
    // 20 = temp = prvalue
    20;
    // xvalue: moveable with HIDDEN name of lvalue
    move(x);
    // lvalue as back to a NAME
    int y = move(x);
    f1(f2()); // xvalue (function return &&)

    // [] on rvalue = xvalue
    string("mostafa")[1];
    // . on rvalue (non static member data) = xvalue
    Employee{}.name;

    // You can cast xvalue to rvalue reference
    (string &&) Employee{}.name;
    // CE: You can't cast prvalue to rvalue reference!
    //(string &&)string("mostafa")
}
