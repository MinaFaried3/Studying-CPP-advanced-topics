#include <iostream>
#include <vector>
using namespace std;

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
};

class MyPair2
{
private:
    int first, second;

public:
    MyPair2() : // Empty constructor to allow using default
                first(-1), second(-1)
    {
    }

    MyPair2(int first, int second) : first(first), second(second)
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

    friend istream &operator>>(istream &input, MyPair2 &pair);
    friend ostream &operator<<(ostream &output, const MyPair2 &pair);
};

//! must be out side of class
void operator>>(istream &input, MyPairMC &pair)
{
    int a, b;
    cin >> a >> b;
    pair.SetFirst(a);
    pair.SetSecond(b);
}

//----------------------------------------------
istream &operator>>(istream &input, MyPair2 &pair)
{
    input >> pair.first >> pair.second;
    return input;
}

ostream &operator<<(ostream &output, const MyPair2 &pair)
{
    output << "(" << pair.first << " " << pair.second << ")\n";
    return output;
}

int main()
{
    MyPairMC x, y;
    cin >> x;
    x.print();

    // But we can't read several objects
    // Recall cin>>x is function that return void
    // What if it return cin object again!
    // cin >> x >> y;

    MyPair2 x2, y2;
    cin >> x2 >> y2;
    cout << x2 << y2;
    return 0;
}
