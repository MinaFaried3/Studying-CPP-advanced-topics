#include <iostream>
#include <vector>
using namespace std;

/*
● Guess the output
● Run the program
● Compare and Guess
● Give a tip
*/
class Boolean
{
private:
    bool is_true;

public:
    Boolean(bool is_true) : is_true(is_true) {}
    bool operator&&(const Boolean &other) const
    {
        return this->is_true && other.is_true;
    }
};

bool T()
{
    cout << "T\n";
    return true;
}
bool F()
{
    cout << "F\n";
    return false;
}

Boolean TC()
{
    cout << "TC\n";
    return Boolean(true);
}
Boolean FC()
{
    cout << "FC\n";
    return Boolean(false);
}

int main()
{
    F() && T();
    T() && F();
    FC() && TC();

    return 0;
}

/*
F
T
F
TC
FC


========
Clearly the first line just give F, because of short-circuit evaluation: As the first one is False, no need to continue (short)

When operators such as &&, || are overloaded, they lose their special properties of short-circuit evaluation and sequencing.
     This means all of them will be evaluated

Tip: DON'T override && ||
    They will be misused. Programmers forget or don't know the short-circuit evaluation case for operator overloading 

    
Tip: Operator overloading is great till you support it unwisely!

*/
