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
int main()
{
    // * 1- direct access
    cout << "direct access: " << endl;

    int arr[3][4]{
        {0, 10, 2, 7},
        {31, 40, 5, 32},
        {11, 12, 15, 16},
    };

    cout << arr[0][10] << " " << arr[1][5] << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 2- Greedy robot move in diagonal,down,right to max value
    cout << "Greedy robot move in diagonal,down,right to max value: " << endl;

    const int rows = 3, cols = 4;

    int arr1[rows][cols]{
        {0, 10, 2, 7},
        {31, 40, 5, 32},
        {11, 12, 15, 16},
    };

    int r = 0, c = 0;
    int sum = 0;
    while (r < rows && c < cols)
    {
        sum += arr1[r][c];

        int best_r = -1, best_c = -1, nextValue;

        if (c + 1 < cols)
        {
            best_r = r, best_c = c + 1;
            nextValue = arr1[r][c + 1];
        }

        if (r + 1 < rows)
            if (best_r == -1 || nextValue < arr1[r + 1][c])
            {
                best_r = r + 1, best_c = c;
                nextValue = arr1[r + 1][c];
            }

        if (r + 1 < rows && c + 1 < cols)
        {
            if (best_r == -1 || nextValue < arr1[r + 1][c + 1])
            {
                best_r = r + 1, best_c = c + 1;
                nextValue = arr1[r + 1][c + 1];
            }
        }

        if (best_r == -1)
            break;

        r = best_r, c = best_c;
    }

    cout << "greedy robot : " << sum << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 3- Greedy robot with direction arr
    cout << "Greedy robot with direction arr: " << endl;

    int arr2[rows][cols]{
        {0, 10, 2, 7},
        {31, 40, 5, 32},
        {11, 12, 15, 16},
    };

    int di[3]{1, 0, 1};
    int dj[3]{0, 1, 1};

    r = 0, c = 0;
    sum = 0;

    while (r < rows && c < cols)
    {
        sum += arr2[r][c];

        int best_r = -1, best_c = -1, nextValue;

        for (int i = 0; i < 3; i++)
        {
            int nr = r + di[i];
            int nc = c + dj[i];

            if (nr < rows && nc < cols)
                if (best_r == -1 || nextValue < arr2[nr][nc])
                {
                    nextValue = arr2[nr][nc];
                    best_r = nr, best_c = nc;
                }
        }

        if (best_r == -1)
            break;

        r = best_r, c = best_c;
    }

    cout << "greedy robot with direction : " << sum << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 4- Flatten array
    cout << "Flatten array : " << endl;

    /*
    **NOTE -  To Convert from (i,j) index to 1d array index :
                 index = i * cols + j;
    *
    **NOTE -  To Convert from  1d array index to (i,j) index :
                 i = index / cols
                 j = index % cols
    */
}