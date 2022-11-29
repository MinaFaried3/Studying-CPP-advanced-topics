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
    //InDegree / OutDegree is not always work when there is a cyclic graph
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
}
