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
#define BREAK cout << "--------------------------------------------------------------------" << endl
#define LABEL(i, title) cout << " " << i << " - " << title << " :-" << endl

// * 1- DepthFirstSearch
// the bigO = nodes + edges
int nodes, edgeQuery;
vector<vector<int>> adjacency;
vector<bool> visited;

// * 2- topology sort dfs
vector<int> topologySort;

void DepthFirstSearch(int node)
{

    visited[node] = true;

    loopSz(i, adjacency[node])
    {
        int connectedNode = adjacency[node][i];

        if (!visited[connectedNode]) // To avoid cyclic behavior
            DepthFirstSearch(connectedNode);
    }

    topologySort.push_back(node); // DAG // Other way InDegree / OutDegree
    // InDegree / OutDegree is not always work when there is a cyclic graph
}

//------------------------------------------------------------------------
// * 3 - Connected Components Count
int ConnectedComponentsCount()
{
    // must call it before any DepthFirstSearch() function to avoid visited node before
    int count = 0;

    loop0(nodes)
    {
        if (!visited[i])
        {
            DepthFirstSearch(i);
            count++;
        }
    }

    return count;
}

//------------------------------------------------------------------!SECTION
// * 4 - Edge Classification
vector<int> start, finish;
bool anyCycle = false;
int timer = 0;

void EdgeClassification(int node)
{
    start[node] = timer++;

    loopSz(i, adjacency[node])
    {
        int child = adjacency[node][i];

        if (start[child] == -1) // tree edge
            EdgeClassification(child);
        else
        {
            if (finish[child] == -1) // back edge
                anyCycle = 1;
            else if (start[node] < start[child]) // forward edge
                ;
            else // cross edge
                ;
        }
    }

    finish[node] = timer++;
}

// * 5

// Flood Fill...given maze where cells are . or X. You start at 0, 0..how many cells you could reach?
/*
..X.
.X.X
..X.

...x.
..x..
.x...
x....


....X...
....XXXX
..X.....
.X....XX
..X.X.X.
..X...X.
...X..XX
*/

// A reachable block is called connected components. Each set of positions reachable together are connected component.

int cnt = 0;
const int MAX = 100;
bool valid(int i, int j) { return 1; }
char maze[MAX][MAX];
bool vis[MAX][MAX];
void cntReachableCells(int r, int c)
{
    if (!valid(r, c) || maze[r][c] == 'X' || vis[r][c] == 1)
        return; // invalid position or block position

    vis[r][c] = 1; // we just visited it, don't allow any one back to it
    cnt++;

    // Try the 4 neighbor cells
    cntReachableCells(r, c - 1);
    cntReachableCells(r, c + 1);
    cntReachableCells(r - 1, c);
    cntReachableCells(r + 1, c);
}

int main()
{
    LABEL(1, "DepthFirstSearch");
    cin >> nodes >> edgeQuery;

    adjacency = vector<vector<int>>(nodes);
    visited = vector<bool>(nodes);

    loop0(edgeQuery)
    {
        int from, to;
        cin >> from >> to;
        adjacency[from - 1].push_back(to - 1);
    }

    BREAK; //------------------------------------------------------------------------
    LABEL(4, "Edge Classification");
    start = vector<int>(nodes, -1);
    finish = vector<int>(nodes, -1);

    loop0(nodes)
    {
        EdgeClassification(i);
    }

    cout << anyCycle;
}
