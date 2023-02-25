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

class Employee
{
public:
    int id;
    int salary;
    string name;

    Employee(int id, int salary, string name) : id(id), salary(salary), name(name)
    {
    }
    bool operator<(const Employee &c2)
    {
        return std::tie(id, salary, name) <
               std::tie(c2.id, c2.salary, c2.name);
    }

    void print()
    {
        cout << id << " " << name << " " << salary << "\n";
    }
};

class EmployeeComparatorId
{
public:
    bool operator()(const Employee &c1, const Employee &c2)
    {
        return c1.id < c2.id;
    }
};

class EmployeeComparatorSalary
{
public:
    bool operator()(const Employee &c1,
                    const Employee &c2)
    {
        return c1.salary < c2.salary;
    }
};

int main()
{
    LABEL("Sort base on relation operator in class");

    vector<Employee> emps;

    emps.push_back({9, 500, "ali"});
    emps.push_back({1, 1000, "mostafa"});
    emps.push_back({5, 700, "hani"});

    sort(emps.begin(), emps.end()); // overloaded <

    for (auto &emp : emps)
        emp.print();

    BREAK; //------------------------------------------------------

    LABEL("Sort base on another class");
    vector<Employee> emps1;

    emps1.push_back({9, 500, "ali"});
    emps1.push_back({1, 1000, "mostafa"});
    emps1.push_back({5, 700, "hani"});

    EmployeeComparatorSalary comparator =
        EmployeeComparatorSalary();
    sort(emps1.begin(), emps1.end(), comparator);

    for (auto &emp : emps1)
        emp.print();
    BREAK; //------------------------------------------------------

    LABEL("Sort base on lambda expresion function");
    vector<Employee> emps2;

    emps2.push_back({9, 500, "ali"});
    emps2.push_back({1, 1000, "mostafa"});
    emps2.push_back({5, 700, "hani"});

    sort(emps2.begin(), emps2.end(), [](const Employee &c1, const Employee &c2)
         { return c1.salary < c2.salary; });

    for (auto &emp : emps2)
        emp.print();
    BREAK; //------------------------------------------------------

    return 0;
}
