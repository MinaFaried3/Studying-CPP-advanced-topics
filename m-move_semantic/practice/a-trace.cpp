#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

int main()

{
    int salary = 100;
    // salary + 1 = 300;
    // 200 = salary;
    int &ref1 = salary;
    ref1 = 20;
    // char *foo = &salary;
    const string &ref2 = "mostafa";
    string const &ref3 = "mostafa";
    // string &ref3 = "mostafa";
    // int *p1 = "mostafa";
    ++salary = 20;
    // salary++ = 40;
    int arr[]{1, 2, 3, 4};
    // arr = &salary;
    int *p = arr;
    // p + 1 = arr;
    *(p + 1) = 10;
    p = &salary;
    // p = &(salary + 1);
    // &salary = 40;
    // &salary = p;

    return 0;
}
