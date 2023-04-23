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
    int *firstPtr = nullptr;
    int *secondPtr = nullptr;

public:
    MyPairMC(int first = 0, int second = 0)
    {
        cout << "Constructor\n";
        SetFirst(first), SetSecond(second);
    }
    MyPairMC(const MyPairMC &other)
    {
        cout << "Copy Constructor\n";
        SetFirst(*other.firstPtr), SetSecond(*other.secondPtr);
    }
    void print()
    {
        cout << "(" << *firstPtr << "," << *secondPtr << ")\n";
    }
    int GetFirst() const
    {
        return *firstPtr;
    }
    void SetFirst(int first)
    {
        if (firstPtr == nullptr)
            firstPtr = new int;
        *firstPtr = first;
    }
    int GetSecond() const
    {
        return *secondPtr;
    }
    void SetSecond(int second)
    {
        if (secondPtr == nullptr)
            secondPtr = new int;
        *secondPtr = second;
    }
    ~MyPairMC()
    {
        cout << "~MyPair()\n";
        if (firstPtr != nullptr)
            delete firstPtr;

        if (secondPtr != nullptr)
            delete secondPtr;
    }
};

class MyPairMC
{
private:
    int *firstPtr = nullptr;
    int *secondPtr = nullptr;

public:
    MyPairMC(int first = 0, int second = 0)
    {
        cout << "Constructor\n";
        SetFirst(first), SetSecond(second);
    }

    MyPairMC(const MyPairMC &other)
    {
        cout << "Copy Constructor\n";
        SetFirst(*other.firstPtr);
        SetSecond(*other.secondPtr);
    }
    MyPairMC(MyPairMC &&other)
    {
        cout << "Move Constructor\n";
        // 1) copy pointer addresses
        firstPtr = other.firstPtr;
        secondPtr = other.secondPtr;
        // 2) Null other
        other.firstPtr = other.secondPtr = nullptr;
    }

    MyPairMC &operator=(MyPairMC &other)
    {
        cout << "Assignment lvalue\n";
        if (this == &other)
            return *this;

        if (other.firstPtr != nullptr)
            SetFirst(*other.firstPtr);

        if (other.secondPtr != nullptr)
            SetSecond(*other.secondPtr);

        return *this;
    }
    MyPairMC &operator=(MyPairMC &&other)
    {
        cout << "Assignment rvalue\n";
        if (this == &other)
            return *this;

        // Free mine
        if (firstPtr != nullptr)
            delete firstPtr;

        if (secondPtr != nullptr)
            delete secondPtr;

        // 1) copy pointer addresses
        firstPtr = other.firstPtr;
        secondPtr = other.secondPtr;
        // 2) Null other
        other.firstPtr = other.secondPtr = nullptr;

        return *this;
    }

    ~MyPairMC()
    {
        cout << "~MyPairMC()\n";

        if (firstPtr == nullptr && secondPtr == nullptr)
            cout << "\tFreed already by a move!\n";

        if (firstPtr != nullptr)
            delete firstPtr;

        if (secondPtr != nullptr)
            delete secondPtr;
    }
    void SetFirst(int first)
    {
        if (firstPtr == nullptr)
            firstPtr = new int;
        *firstPtr = first;
    }

    void print()
    {
        cout << "(" << *firstPtr << "," << *secondPtr << ")\n";
    }
    int GetFirst() const
    {
        return *firstPtr;
    }

    int GetSecond() const
    {
        return *secondPtr;
    }
    void SetSecond(int second)
    {
        if (secondPtr == nullptr)
            secondPtr = new int;
        *secondPtr = second;
    }
};

int main()
{
    {
        vector<MyPairMC> v;

        v.push_back(MyPairMC(3, 6));
        // Constructor for temp MyPair(3, 6)
        // Create 2 integers
        // Copy Constructor
        // Create 2 integers, copy data
        // ~MyPair()
        // Delete 2 integers
        // ~MyPair()
        // Delete 2 integers
    }
    BREAK;
    {
        vector<MyPairMC> v;

        v.push_back(MyPairMC(3, 6)); // rvalue
        // Constructor for temp MyPairMC(3, 6)
        // Create 2 integers
        // Move Constructor
        // No creation/copying
        // ~MyPairMC()
        // Freed already by a move!
        // ~MyPairMC()
        // Delete 2 integers

        MyPairMC p1(1, 5);
        MyPairMC p2(p1); // lvalue -> copy constructor
    }
    BREAK;
    {
        MyPairMC p1;         // Empty Constructor
        p1 = MyPairMC(1, 5); // Rvalue
        // Constructor MyPairMC(1, 5)
        // Assignment rvalue: steal data
        // ~MyPairMC()
        // Freed already by a move!
        //~MyPairMC()

        MyPairMC p2; // Empty Constructor
        p2 = p1;     // Assignment lvalue

        p1.print();
        p2.print();
    }
    return 0;
}
