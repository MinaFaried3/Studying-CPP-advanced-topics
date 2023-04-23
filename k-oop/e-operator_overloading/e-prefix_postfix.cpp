#include <iostream>
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

    // ++x prefix increment operator
    MyPairMC &operator++()
    {
        ++first, ++second; // increment first
        return *this;      // then return reference
    }

    // x++ postfix increment operator
    // DON'T return MyPair&: this is local var
    MyPairMC operator++(int)
    {
        MyPairMC cpy = *this; // Copy first
        ++first, ++second;    // Then increment
        return cpy;
    }
};

int main()
{
    MyPairMC x1(1, 2);
    (++x1).print(); // (2,3)

    MyPairMC x2(1, 2);
    x2++.print(); // (1,2)
    x2.print();   // (2,3)

    return 0;
}
