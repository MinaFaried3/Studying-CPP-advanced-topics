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

//? grid sum -> greedy robot
int di[]{1, 0, 1};
int dj[]{0, 1, 1};

int greedyRobot(int arr[3][3], int Rows, int Cols, int row = 0, int col = 0)
{
    int sum = arr[row][col];

    if (row == Rows - 1 && col == Cols - 1)
        return sum;

    int maxVal = -1, maxIdx = -1;
    for (int d = 0; d < 3; d++)
    {
        int newRow = row + di[d];
        int newCol = col + dj[d];

        if (newRow >= Rows || newCol >= Cols)
            continue;

        if (maxVal < arr[newRow][newCol])
        {
            maxVal = arr[newRow][newCol];
            maxIdx = d;
        }
    }

    row += di[maxIdx];
    col += dj[maxIdx];

    return sum + greedyRobot(arr, Rows, Cols, row, col);
}
//---------------------------------------------------------------------
//? fibonacci

long long fibonacci(long long num)
{
    if (num <= 1)
        return 1;

    return fibonacci(num - 1) + fibonacci(num - 2);
}
long long fibArr[100]{0};
long long effFibonacci(long long num)
{
    if (num <= 1)
        return 1;

    if (fibArr[num] == 0)
        fibArr[num] = effFibonacci(num - 1) + effFibonacci(num - 2);

    return fibArr[num];
}
int main()
{
    //? grid sum -> greedy robots
    int arr[3][3] = {
        {1, 7, 8},
        {2, 10, 11},
        {20, 5, 9},
    };

    cout << "greedy robot : " << greedyRobot(arr, 3, 3) << endl;
    //--------------------------------------------------------------------------
    cout << "----------------------------------------------------------" << endl;
    cout << "fibonacci(10) : " << fibonacci(10) << endl;
    //! don't work
    // cout << fibonacci(50) << endl;
    cout << "effFibonacci(41) : " << effFibonacci(41) << endl;
    cout << "effFibonacci(38) : " << effFibonacci(38) << endl;
    cout << "effFibonacci(50) : " << effFibonacci(50) << endl;
    int x;
    cout << x;

    int a = 3, b = 2, c = 1;
    if (a > b > c)
        cout << "yes0";
    if (a > b == c)
        cout << "yes1";
    if (a > (b > c))
        cout << "yes2";
    if ((a > b) > c)
        cout << "yes3";
    if ((a > b) && (b > c))
        cout << "yes4";
}
