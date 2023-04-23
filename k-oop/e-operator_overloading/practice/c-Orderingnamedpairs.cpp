#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
To be able to sort a vector of objects as in right
code, the operator < must be supported on
class type
● Add operator < as member function in the
MyPair class to allow such code

Define class NamedPair that inherits
from the previous class
○ It has now extra param for string name
● Define operator <
○ It should utilize parent operator <
○ Don’t duplicate effort
● Override function print to print new
variable
*/

class MyPairMC
{
private:
    int first, second;

public:
    virtual ~MyPairMC() {}
    MyPairMC(int first, int second) : first(first), second(second)
    {
    }

    virtual void print()
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

    bool operator<(const MyPairMC &c2)
    {
        MyPairMC &c1 = *this;

        if (c1.first == c2.first)
            return c1.second < c2.second;

        return c1.first < c2.first;
    }
};

class NamedPair : public MyPairMC
{
private:
    string name;

public:
    NamedPair(string name, int first, int second) : MyPairMC(first, second), name(name)
    {
    }

    bool operator<(const NamedPair &c2)
    {
        NamedPair &c1 = *this;

        if (c1.name == c2.name)
            return MyPairMC::operator<(c2);

        return c1.name < c2.name;
    }

    virtual void print()
    {
        cout << "(" << name << ": " << GetFirst() << "," << GetSecond() << ")\n";
    }
};

int main()
{
    vector<NamedPair> vec;
    vec.push_back(NamedPair("A", 10, 20));
    vec.push_back(NamedPair("B", 10, 7));
    vec.push_back(NamedPair("B", 1, 200));

    sort(vec.begin(), vec.end());

    for (auto &pair : vec)
        pair.print();
    // ((A: 10,20) (B: 1,200) (B: 10,7)

    return 0;
}
