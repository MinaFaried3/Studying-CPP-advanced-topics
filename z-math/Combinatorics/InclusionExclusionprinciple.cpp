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
int InclusionExclusion(int number)
{
    // * How many integers in {1,2 ...,100} are divisible by 2, 3, 5 or 7?
    /*
        ◼ F(2)+F(3)+F(5)+F(7)
        ◼ -F(2, 3)-F(2, 5)-F(2, 7)-F(3, 5)-F(3, 7)-F(5, 7)
        ◼ +F(2, 3, 5)+F(2, 3, 7)+F(2, 5, 7)+F(3, 5, 7)
        ◼ -F(2, 3, 5, 7)

        ?NOTICE that if num inside f() is odd we add else we subtract
        ?compute 2^4 -1 terms = 15 terms

        ◼ How many divisible by 2? 100 / 2 = 50
        ◼ How many divisible by 3? 100 / 3 = 33
        ◼ How many divisible by 2, 3? 100 / (2*3) = 16
        ◼ How many divisible by 2, 3, 7? 100 / 42 = 2 => {42, 84}

    */

    // they are 4 divisors so we will use 4 loops
    int counts = 0;

    for (int i2 = 0; i2 <= 1; i2++)
        for (int i3 = 0; i3 <= 1; i3++)
            for (int i5 = 0; i5 <= 1; i5++)
                for (int i7 = 0; i7 <= 1; i7++)
                {
                    int num = 1, countsTime = 0;

                    if (i2)
                        num *= 2, countsTime++;
                    if (i3)
                        num *= 3, countsTime++;
                    if (i5)
                        num *= 5, countsTime++;
                    if (i7)
                        num *= 7, countsTime++;

                    if (countsTime == 0)
                        continue;

                    //?NOTICE that if num inside f() is odd we add else we subtract
                    int sign = countsTime % 2 == 0 ? -1 : 1;

                    counts += (sign * number) / num;
                }

    return counts;
}

/// NOTE wit RECURSION
int divisors[4]{2, 3, 5, 7};
int number = 100;
int InclusionExclusionRecursion(int index = 0, int num = 1, int sign = -1)
{
    if (index == 4)
    {
        if (num == 1)
            return 0;

        return sign * number / num;
    }

    return InclusionExclusionRecursion(index + 1, num, sign) +
           InclusionExclusionRecursion(index + 1, num * divisors[index], sign * -1);
}

/// NOTE - How many integers in {1,2 ...,100} are NOT divisible by 2, 3, 5 or 7?
int InclusionExclusionRecursionReverse(int index = 0, int num = 1, int sign = 1)
{
    if (index == 4)
    {
        return sign * number / num;
    }

    return InclusionExclusionRecursionReverse(index + 1, num, sign) +
           InclusionExclusionRecursionReverse(index + 1, num * divisors[index], sign * -1);
}

int main()
{

    cout << "counts : " << InclusionExclusion(100) << endl;
    cout << "counts : " << InclusionExclusionRecursion() << endl;

    /// NOTE - How many integers in {1,2 ...,100} are NOT divisible by 2, 3, 5 or 7?

    cout << "integers are NOT divisible by 2, 3, 5, 7 : " << 100 - InclusionExclusion(100) << endl;
    cout << "counts : " << InclusionExclusionRecursionReverse() << endl;
}