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
    // * 1- find 3 minumum nums in array
    cout << "find 3 minumum nums in array: " << endl;
    int arr[] = {2, 4, 5, 6, 3, 7, 8, 1, 9};
    int minNums[3];
    for (int i = 0; i < 9; i++)
    {
        if (i < 3)
            minNums[i] = arr[i];
        else
        {
            int maxPosition = 0;
            for (int x = 1; x < 3; x++)
                if (minNums[maxPosition] < minNums[x])
                    maxPosition = x;

            if (arr[i] < minNums[maxPosition])
                minNums[maxPosition] = arr[i];
        }
    }

    cout << minNums[0] << " " << minNums[1] << " " << minNums[2] << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 2- find the most frequent number in array -500:270
    cout << "find the most frequent number in array -500:270 : " << endl;
    int arr1[] = {-1, 2, -1, 3, -1, 5, 5};
    const int size_ = 1 + 500 + 270;
    int frequent[size_] = {0};
    for (int i = 0; i < 7; i++)
    {
        arr1[i] += 500;
        frequent[arr1[i]]++;
    }

    int maxPosition = 0;
    for (int i = 0; i < size_; i++)
        if (frequent[maxPosition] < frequent[i])
            maxPosition = i;

    cout << maxPosition - 500 << " times " << frequent[maxPosition] << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 3- print onl unique nums in array
    cout << "print onl unique nums in array  : " << endl;

    int arr2[] = {1, 2, 1, 3, 1, 5, 5};
    const int size1_ = 1 + 500;
    int isVisited[size1_] = {0};

    for (int i = 0; i < 7; i++)
    {
        if (!isVisited[arr2[i]])
            cout << arr2[i] << " ";
        isVisited[arr2[i]] = 1;
    }

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 3- count increasing sub array
    cout << "count increasing sub array  : " << endl;
    const int size2_ = 4;
    int arr3[size2_] = {1, 2, 3, 4};
    int counts = 0;
    int len = 1;

    for (int i = 1; i < 4; i++)
        if (arr3[i - 1] <= arr3[i])
        {
            counts += len;
            ++len;
        }
        else
            len = 1;

    cout << counts + size2_ << endl;
}