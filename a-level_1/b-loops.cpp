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
    // * 3- fibonacci in different way
    cout << "fibonacci in different way: " << endl;

    int limit = 10;

    for (int a = 0, b = 1, c = -1, i = 0; i < limit; i++, c = a + b, a = b, b = c)
        cout << a << " ";

    cout << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 4- print X in console
    cout << "print X in console: " << endl;

    int x = 3;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            //! notice both come true in line that print single *
            // if (j == i && j == x - i - 1)
            //     cout << "-";

            if (j == i || j == x - i - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 5- a+b = c+d
    cout << "a+b = c+d: " << endl;
    counts = 0;
    for (int a = 1; a <= 200; a++)
        for (int b = 1; b <= 200; b++)
            for (int c = 1; c <= 200; c++)
            {
                int d = a + b - c;
                counts += (1 <= d && d <= 200);
            }

    cout << counts << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 6- x = [50-300] y =[70-400] => (x < y && x+y % 7 == 0)
    cout << "x = [50-300] y =[70-400] => (x < y && x+y % 7 == 0): " << endl;
    counts = 0;
    for (int x = 50; x <= 300; x++)
    {
        int start = max(x + 1, 70);

        for (int y = start; y <= 400; y++)
            counts += ((x + y) % 7 == 0);
    }

    cout << counts << endl;
}