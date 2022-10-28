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
// 1 * count the length of (3n+1 if odd) (n/2 if even ) until get 1
// example 6 : 6 3 10 5 16 8 4 2 1 => length is 9
int lengthOf3plus1(int n)
{
    if (n == 1)
        return 1;

    // we write 1 before the recursive call because we count the elements
    if (n % 2 == 0)
        return 1 + lengthOf3plus1(3 * n + 1);

    return 1 + lengthOf3plus1(n / 2);
}
// 2 * find the max element in the array

int findMax1(int arr[], int length)
{
    // in this example notice the connection between base and recursive and value
    if (length == 0) // base
        return arr[0];

    int subResult = findMax1(arr, length - 1); // recursive

    return max(subResult, arr[length - 1]); // value
}
int maxVal = INT16_MIN;
void findMax2(int arr[], int length)
{
    if (length == -1)
        return;

    if (maxVal < arr[length - 1])
        maxVal = arr[length - 1];

    findMax2(arr, length - 1);
}

// 3 * get average

double getAverage(double arr[], int length)
{
    if (length == 0)
        return arr[0];

    double subResult = getAverage(arr, length - 1);

    subResult *= length - 1;

    return (subResult + arr[length - 1]) / length;
    // the math trick is here
    /*  {1, 8, 2, 10, 30}
        1 - when we get the first two element {1+8} / 2
        2 - add third element  to equation and divide by 3
        3 - but how to divide by 3 and in first step we divide by 2
        4 - *NOTE -  so we will multiply by previous length and divide by the current length
    */
}

int main()
{
    cout << "2 * find the max element in the array : " << endl;
    int arr[]{0, 8, 2, 10, 30};
    findMax2(arr, 5);
    cout << "max val is : " << maxVal << endl;
    cout << "max val is : " << findMax1(arr, 5) << endl;
    //---------------------------------------------------------
    double arr1[]{1, 8, 2, 10, 30};
    cout << "3 * get average : " << getAverage(arr1, 5) << endl;
}