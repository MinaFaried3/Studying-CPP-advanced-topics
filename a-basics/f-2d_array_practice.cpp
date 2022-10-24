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
int di[8]{1, 0, -1, 0, -1, 1, -1, 1};
int dj[8]{0, 1, 0, -1, -1, 1, 1, -1};
int main()
{
    // * 1- lower and upper triangle matrix
    cout << "lower and upper triangle matrix: " << endl;

    int arr[3][3]{
        {1, 2, 2},
        {1, 1, 2},
        {1, 1, 1},
    };
    // int arr[3][3]{
    //     {8, 16, 9},
    //     {3, 15, 27},
    //     {14, 25, 29},
    // };

    // we can solve this problem on fly without storing data
    int upper = 0, lower = 0;
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
        {
            if (i >= j)
                lower += arr[i][j];
            if (i <= j)
                upper += arr[i][j];
        }

    cout << "lower : " << lower << " upper : " << upper << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 2- transpose turn row into column and vers
    cout << "transpose turn row into column and vers : " << endl;

    int arr1[3][3]{
        {8, 16, 9},
        {3, 15, 27},
        {14, 25, 29},
    };
    // NOTE - we can make this on fly just cin>> arr1[j][i];
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {

            cout << arr1[j][i] << " ";
            // NOTE - we can make this on fly just cin>> arr1[j][i];
        }
        cout << endl;
    }

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 3- find mountains the max value between neighbour
    cout << "find mountains : " << endl;

    int arr2[3][3]{
        {8, 6, 1},
        {3, 2, 9},
        {1, 6, 4},
    };

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {

            bool valid = true;
            for (size_t d = 0; d < 8 && valid; d++)
            {
                int ni = i + di[d];
                int nj = j + dj[d];

                if (ni < 0 || ni >= 3 || nj < 0 || nj >= 3)
                    continue;

                if (arr2[i][j] <= arr2[ni][nj])
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
                cout << i << " " << j << endl;
        }
    }

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // * 3- active robot move in empty matrix in d direction and n steps
    cout << "active robot : " << endl;
    int rows = 3, cols = 4;

    int dir, steps;
    int tests = 4;

    int rd[4]{-1, 0, 1, 0};
    int cd[4]{0, 1, 0, -1};

    int r = 0, c = 0;
    /*

    //NOTE - copy to the console
        2 1
        3 2
        4 2
        1 3
    */
    while (tests--)
    {
        cin >> dir >> steps;
        dir--;

        // NOTE - this
        r = (r + rd[dir] * steps) % rows;
        c = (c + cd[dir] * steps) % cols;

        if (r < 0)
            r += rows;
        if (c < 0)
            c += cols;

        cout << r << " " << c << endl;
    }

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    // TODO * 3- flatten 3d array :
    cout << "flatten 3d array : " << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}