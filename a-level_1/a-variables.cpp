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
int main()
{

    // * 1- Swapping 3 nums
    cout << "Swapping 3 nums" << endl;
    int num1 = 115, num2 = 20, num3 = 301, temp = -1;
    temp = num1;
    num1 = num2;
    num2 = num3;
    num3 = temp;

    cout << num1 << " " << num2 << " " << num3 << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 2- Checking isEven in Three ways
    cout << "Checking isEven in Three ways" << endl;
    int num = 8;

    bool even1 = (num % 2 == 0);
    bool even2 = num % 10 == 0 || num % 10 == 2 || num % 10 == 4 || num % 10 == 6 || num % 10 == 8;

    double res = (double)num / 2.0;
    res = res - (int)res;
    bool even3 = (res == 0);

    res = (double)num / 2.0;
    bool even4 = ((int)res * 2 == num);

    cout << "even 4 " << even4 << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 3- Getting digit in num
    cout << "Getting digit in num" << endl;

    num = 123456;
    /*
    1000 => 4th num
    */
    cout << (num / 1000) % 10 << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 4- Find the biggest num is less than 100
    cout << "Find the biggest num is less than 100" << endl;

    int a = 20, b = 90, c = 115;
    res = -1;

    if (a < 100 && a > res)
        res = a;
    if (b < 100 && b > res)
        res = b;
    if (c < 100 && c > res)
        res = c;

    cout << res << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 5- add bool
    cout << "add bool" << endl;

    int counts = 0;
    a = 3, b = 4;
    counts += (a < b);
}