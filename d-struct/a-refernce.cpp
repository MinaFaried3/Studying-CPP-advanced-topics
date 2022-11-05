#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <tuple>
#include <cmath>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define lol long long int
#define endl '\n'

struct Employee
{
    int num = 0;
    string name;
};

struct Manager
{
    int mgr_id;
    Employee employees[10];
    int idx = 0;

    void AddEmployee(Employee &e)
    {
        e.num++;
        employees[idx] = e;
        employees[idx].name = "mina";
        ++idx;
    }
};

int main()
{
    Employee e;
    e.name = "faried";

    // Even we pass e by reference, once we put it the array it is COPIED. 
    // that is why the name won't be affected. As e.num itself is changed, we see the effect of that.
    
    Manager mgr;
    mgr.AddEmployee(e);
    mgr.AddEmployee(e);
    mgr.AddEmployee(e);

    cout << e.name << " " << e.num;

    return 0;
}