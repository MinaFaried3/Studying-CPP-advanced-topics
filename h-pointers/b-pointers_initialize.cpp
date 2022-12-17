#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include <bitset>
using namespace std;

#define lol long long int
#define endl '\n'
#define sz(v) ((int)((v).size()))
#define loop0(n) for (size_t i = 0; i < n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define loopSz(i, v) for (int i = 0; i < sz(v); ++i)
#define BREAK cout << endl \
                   << "--------------------------------------------------------------------" << endl
#define LABEL(i, title) cout << " " << i << " - " << title << " :-" << endl \
                             << endl;
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)

int main()
{
    BREAK; //--------------------------------------------------
    LABEL(1, "const pointer");
    int x = 20;
    int y = 40;

    const int *ptr1 = &x; // can change the pointer only
    // *ptr1 = 30; //error
    ptr1 = &y; // can change the pointer
    cout << "ptr1 = " << *ptr1 << endl;

    int *const ptr2 = &x; // can change the value in x only
    // ptr2 = &y; // can't change the pointer error
    *ptr2 = 50;
    cout << "ptr2 = " << *ptr2 << " x = " << x << endl;

    const int *const ptr3 = &x; // can't change any of them
                                // ptr3 = &y; // can't change the pointer error
                                // *ptr3 = 50; //error

    BREAK; //--------------------------------------------------
    LABEL(2, "initialize value in heap");

    // variable
    int *num = new int{4};
    cout << "num = " << *num << endl;

    // array
    int *arr = new int[*num]{1, 2, 3, 4};
    loop0(*num)
            cout
        << arr[i] << " ";

    cout << endl;

    //must delete it from heap memory to avoid memory leak
    delete num;
    delete[] arr;
    num = nullptr;
    arr = nullptr;

}