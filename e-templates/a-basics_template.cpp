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

// * 1 basic syntax
template <typename type>
type findMax(type num1, type num2)
{
    if (num1 > num2)
        return num1;

    return num2;
}
//---------------------------------------------------------
int main()
{
    // * 1 basic syntax
    cout << "* 1 basic syntax " << endl;
    cout << findMax(2, 5) << "\n"; // 5: Guessed as int

    cout << findMax<int>(2, 5) << "\n"; // 5

    cout << findMax<double>(2.5, 5.4) << "\n"; // 5.4

    cout << findMax('A', 'X') << "\n"; // X

    // cout << findMax(2, 5.4) << "\n"; //CE: // Can't guess

    cout << findMax<int>(2, 5.4) << "\n"; // 5

    cout << findMax<double>(2, 5.4) << "\n"; // 5.4

    // Employee a, b;
    // cout - << findMax<Employee>(a, b) << "\n";    // CE: can't compare
    cout << "---------------------------------------------------------" << endl;
}