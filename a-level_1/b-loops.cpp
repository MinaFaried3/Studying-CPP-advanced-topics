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
    // * 1- find pair of numbers equal sum
    cout << "find pair of numbers equal sum: " << endl;
//want to find 2 num equls sum
    int r1 = 70, r2 = 60, sum = 70;
    int counts = 0;

    for (int i = 1; i <= r1; i++)
    {
        int j = sum - i; // i + j =sum

        if (1 <= j && j <= r2) // notice this condition
        {
            /*
            i is ++
            j is --
            */
            cout << i << " + " << j << " = " << sum << endl;
            counts++;
        }
    }
    cout << counts << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}