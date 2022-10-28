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

// 1 * find the right max
/*
    {1,3,5,7,4,2} => {7,7,7,7,4,2}
*/

void rightMaxWithPos(int arr[], int length, int postion)
{
    if (postion == length - 1)
        return;

    rightMaxWithPos(arr, length, postion + 1);

    arr[postion] = max(arr[postion], arr[postion + 1]);
}

void rightMax(int arr[], int length)
{
    if (length == 1)
        return;

    //*NOTE -
    rightMax(arr + 1, length - 1);

    arr[0] = max(arr[0], arr[1]);
}
//----------------------------------------------------------------------------
// 2 * suffix sum
/*
    sum last n elements in array
*/

int suffixSum1(int arr[], int length, int lasts)
{
    if (lasts == 0)
        return 0;

    return arr[length - 1] + suffixSum1(arr, length - 1, lasts - 1);
}
int sums = 0;
void suffixSum2(int arr[], int length, int lasts)
{
    if (length == 0)
        return;

    suffixSum2(arr + 1, length - 1, lasts);

    if (lasts >= length)
        sums += arr[0];
}
//----------------------------------------------------------------------------
int main()
{

    cout << "// 1 * find the right max" << endl;
    int arr[]{1, 3, 5, 7, 4, 2};

    // rightMaxWithPos(arr, 6, 0);
    rightMax(arr, 6);

    for (size_t i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    //-------------------------------------------------------!SECTION

    cout << " 2 * suffix sum" << endl;
    // suffixSum2(arr, 6, 3);
    // cout << sums << endl;
    cout << suffixSum1(arr, 6, 3) << endl;
}