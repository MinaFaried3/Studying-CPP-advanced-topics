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
// 3 * prefix sum
/*
    sum first n elements in array
*/
int prefixSum1(int arr[], int length, int firsts)
{
    if (firsts == 0)
        return 0;

    return arr[firsts - 1] + prefixSum1(arr, firsts - 1, firsts - 1);
}
int prefixSum2(int arr[], int firsts)
{
    if (firsts == 0)
        return 0;

    return arr[firsts - 1] + prefixSum2(arr, firsts - 1);
}
int prefixSum3(int arr[], int firsts)
{
    if (firsts == 0)
        return 0;

    return arr[0] + prefixSum3(arr + 1, firsts - 1);
}
//----------------------------------------------------------------------------
// 4 * is palindrome
//*NOTE -  the order
bool isPalindRome1(int arr[], int start, int end)
{
    if (start >= end)
        return true;

    if (arr[start] != arr[end])
        return false;

    return isPalindRome1(arr, start + 1, end - 1);
}
bool isPalindRome2(int arr[], int end)
{
    if (end <= 0)
        return true;

    if (arr[0] != arr[end])
        return false;
    // NOTE - here we remove 2 from end because we are done with two elements in same time
    return isPalindRome2(arr + 1, end - 2);
}
//----------------------------------------------------------------------------
// 5 * is start with string

bool isStartWith(string str, string subStr, int pos = 0)
{
    if (pos == subStr.size())
        return true;

    if (str[pos] != subStr[pos])
        return false;

    return isStartWith(str, subStr, pos + 1);
}
//----------------------------------------------------------------------------
// 6 * is sub string

bool isSubString(string str, string subStr, int start, int pos = 0)
{
    if (pos == subStr.size())
        return true;

    if (str[start] != subStr[pos])
        return false;

    return isSubString(str, subStr, start + 1, pos + 1);
}

//-------------------------------------------------------
//? 7 * is prime

bool isPrime(int num, int test = 2)
{
    if (num % test == 0 || num == 1)
        return false;

    if (test > num / 2) // base condition
        return true;

    return isPrime(num, test + 1);
}
//? 8 * count primes

int countPrimes1(int start, int end)
{
    if (start > end)
        return 0;

    // return isPrime(start) + countPrimes1(start + 1, end);
    return isPrime(start) + isPrime(end) + countPrimes1(start + 1, end - 1); // more efficient
}
int countPrimes2(int start, int end)
{
    if (start > end)
        return 0;

    int result = countPrimes2(start + 1, end - 1);

    result += isPrime(start) + isPrime(end);

    return result;
}
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
    //-------------------------------------------------------!SECTION

    cout << " 3 * prefix sum" << endl;
    int arr1[]{1, 3, 5, 7, 4, 2};

    cout << prefixSum2(arr1, 4) << endl;
    //-------------------------------------------------------!SECTION

    cout << " 4 * is palindrome" << endl;
    int arr2[]{1, 3, 5, 5, 3, 1};

    cout << isPalindRome2(arr2, 5) << endl;
    //-------------------------------------------------------!SECTION

    cout << " 5 * is start with" << endl;

    cout << isStartWith("abcdeee", "bcd") << endl;
    //-------------------------------------------------------!SECTION

    cout << " 6 * is sub string" << endl;

    cout << isSubString("abcdeee", "bcd", 1) << endl;
    //-------------------------------------------------------!SECTION

    cout << " 7 * is prime" << endl;

    cout << isPrime(5) << endl;
    cout << countPrimes1(10, 20) << endl;
    cout << countPrimes2(10, 20) << endl;
}