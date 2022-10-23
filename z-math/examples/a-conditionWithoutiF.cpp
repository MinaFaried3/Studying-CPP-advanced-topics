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

    // * print without condition
    int choice, num;
    cin >> choice >> num;
    /*
        x * 1 = 0
        x * -1 = 1
    */
    int negativeOne = (choice + 1) / 2;
    int positiveOne = 1 - negativeOne;

    int eq1 = 2 * num + 1;
    int eq2 = num * num;
    int solve = (negativeOne * eq1) + (positiveOne * eq2);
    cout << solve << endl;
}