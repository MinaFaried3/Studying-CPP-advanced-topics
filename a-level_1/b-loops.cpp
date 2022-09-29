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
    // want to find 2 num equals sum
    int r1 = 10, r2 = 20, sum = 6;
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
            // cout << i << " + " << j << " = " << sum << endl;
            counts++;
        }
    }
    cout << counts << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 2- find Triple of numbers less than or equal sum
    cout << "find Triple of numbers less than or equal sum: " << endl;

    r1 = 100, r2 = 200;
    int r3 = 20;
    counts = 0;

    for (int i = 1; i <= r1; i++)
        for (int j = i; j <= r1; j++)
        {
            int k = i + j;

            if (1 <= k && k <= r3)
            {
                // cout << i << " + " << j << " <= " << k << endl;
                counts += r3 - k + 1;
            }
        }

    cout << counts << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 2- fibonacci in different way
    cout << "fibonacci in different way: " << endl;

    int limit = 10;

    for (int a = 0, b = 1, c = -1, i = 0; i < limit; i++, c = a + b, a = b, b = c)
        cout << a << " ";

    cout << endl;
}