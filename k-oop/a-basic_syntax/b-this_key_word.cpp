#include <set>
#include <map>
#include <array>
#include <list>
#include <iomanip>
#include <cmath>
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

int main()
{
    mino;
    lol cases;
    cin >> cases;
    while (cases--)
    {
    }
}
class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int hours, int minutes, int seconds)
    {
        SetTime(hours, minutes, seconds);
    }
    void SetTime(int hours, int minutes, int seconds)
    {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
    int GetTotalSeconds()
    {
        return hours * 60 * 60 + minutes * 60 + seconds;
    }
    int GetTotalMinutes()
    {
        return hours * 60 + minutes;
    }
    void PrintHHMMSS()
    {
        cout << ToString(":") << "\n";
    }
    string ToString(string seperator = "-")
    {
        ostringstream oss;
        oss << hours << seperator << minutes << seperator << seconds;
        return oss.str();
    }
    int GetHours()
    {
        return hours;
    }
    Time &SetHours(int hours)
    {
        if (hours < 0)
            hours = 0;
        this->hours = hours;

        return *this;
    }
    int GetMinutes()
    {
        return minutes;
    }
    Time &SetMinutes(int minutes)
    {
        if (minutes < 0)
            minutes = 0;
        this->minutes = minutes;

        return *this;
    }
    int GetSeconds()
    {
        return seconds;
    }
    Time &SetSeconds(int seconds)
    {
        if (seconds < 0)
            seconds = 0;
        this->seconds = seconds;

        return *this;
    }
};

/*
what does it mean to do
    1) t.SetHours(5).Something?
    .Something is a function, then it needs object
    then t.SetHours(5) must return object of type time NOT void

    So we need to return object from these setters

    2) Now each object has pointer to itself this
        *this is the object
        We can return this but there is a problem
        It will be a copy, so NOT same
        This means we are modifying some temporary object NOT t itself!

    To solve that, return the object by reference: Time&T

    So overall
    Time& SomeSetter
        return *this



Q: Was it possible / More OOP to add const to return?:

    const Time& SetMinutes(int minutes)

 */

int main()
{

    Time t(3, 1, 2);
    t.PrintHHMMSS(); // 3:1:2

    t.SetHours(5).SetMinutes(45).SetSeconds(13);
    t.PrintHHMMSS(); // 5:45:13

    return 0;
}
