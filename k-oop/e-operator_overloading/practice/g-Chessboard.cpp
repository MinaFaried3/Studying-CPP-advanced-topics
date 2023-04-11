#include <set>
#include <map>
#include <array>
#include <list>
#include <iomanip>
#include <cmath>
#include <climits>
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
#define all(v) ((v).begin()), ((v).end())
#define loop0(n) for (int i = 0; i < n; i++)
#define loop1(n) for (int i = 1; i <= n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define loopSz(i, v) for (int i = 0; i < sz(v); ++i)
#define BREAK cout << "--------------------------------------------------------------------" << endl
int numIDX = 0;
#define LABEL(title) cout << endl                                        \
                          << ++numIDX << " - " << title << " :-" << endl \
                          << endl;
#define PI 3.14159265358979323846
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)
#define sizeOf(arr) sizeof(arr) / sizeof(arr[0])
#define mino                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

/*
We wanna build chessboard class
○ 2d board of integers
● Change this class to allow these
operators
○ 2 ways of set and get
*/

class ChessBoard
{
private:
    int rows;
    int colums;

    vector<vector<int>> board;

public:
    ChessBoard(int rows, int colums) : rows(rows), colums(colums)
    {
        board = vector<vector<int>>(rows, vector<int>(colums));
    }

    /*
     * There is no double subscript operator [][]
     * overload operator[] to return an object that also overloads operator[]. This will enable [][].
     *
     * If we used internally 2D vector
     * and returned row for []
     * then return allows all operations on a single vector!
     */
    vector<int> &operator[](int row)
    {
        // using board[row][col]
        // then become row[col]
        return board[row];
    }

    int &operator()(int row, int col)
    {
        return board[row][col];
    }
};

int main()
{
    ChessBoard board(2, 3); // 2x3 grid

    board(0, 0) = 10;
    board[0][1] = 20;

    cout << board[0][0] << " " << board(0, 1);

    return 0;
}
