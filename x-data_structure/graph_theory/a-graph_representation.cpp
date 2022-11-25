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
#define loop0(n) for (size_t i = 0; i < n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)

const int N = 100;

// * 1- adjacency matrix
bool adjMatrixBool[N][N];
int adjMatrixWeight[N][N]; // weight graph

//--------------------------------------------

// * 2- Adjacency lists
vector<vector<int>> adjListOrder;              // boolean relation save only node
vector<vector<pair<int, int>>> adjListWeight; // cost relation (node, cost): Select 1 of multiple edges cost is weight

//--------------------------------------------

// * 3- Edges List
struct edge
{
    int from, to, weight;

    edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}

    bool operator<(const edge &e) const
    {
        return weight > e.weight; // Sort with smaller weight first
    }
};

vector<edge> edgeList;

//--------------------------------------------

// * 4-
vector<int> adjMatrixAll[N][N]; // Keep all edges for a given pair of nodes

// * 5- large graph
//  pair<from,to >, weight
map<pair<int, int>, int> adjMatrixMap; // Imagine graph of 100000 node, but total number of edges is 50000!

int main()
{
    int count;
    // * 1- adjacency matrix
    // Assume all input is ZERO based. Node values [0 - n-1]

    // 1- bool
    /*
        3
        0 1 0
        1 1 0
        0 1 1
     */
    cin >> count;
    loop(i, count) loop(j, count)
    {
        bool isExist;
        cin >> isExist;
        adjMatrixBool[i][j] = isExist;
    }

    // 2- weight
    /*
        3
        0 10 5
        2 7 9
        3 2 0
     */
    cin >> count;
    loop(i, count) loop(j, count)
    {
        int weight;
        cin >> weight;
        adjMatrixWeight[i][j] = weight;
    }
    ////---------------------------------------
    //  2- another way to  weight Matrix
    //! adjMatrix initialize with Max number first
    int edges;
    cin >> count >> edges;
    /*
         3 5
         from to cost
         0 3 10
         1 5 2
         3 7 -2
         0 3 2
         2 4 6
     */
    loop(i, edges)
    {
        int from, to, cost;
        cin >> from >> to >> cost;

        adjMatrixWeight[from][to] = min(adjMatrixWeight[from][to], cost); // if directed

        // if undirected: add following
        // notice the order => to from= from to // this for save two edges
        adjMatrixWeight[to][from] = adjMatrixWeight[from][to];
    }

    //--------------------------------------------
    // * 2- Adjacency lists
    // 1- node Order
    /*
        3
        2	1 2
        1	2
        2	0 1
     */
    cin >> count;
    adjListOrder = vector<vector<int>>(count);
    loop(i, count)
    {
        int connectedNodes; 
        cin >> connectedNodes;
        loop(j, connectedNodes)
        {
            int to;
            cin >> to;
            adjListOrder[i].push_back(to);
        }
    }

    // 2-weight
    /*
        3
        2	1 13	2 4
        1	2 9		3 -4
        2	0 -7	1 8
     */
    cin >> count;
    adjListWeight = vector<vector<pair<int, int>>>(count);
    loop(i, count)
    {
        int connectedNodes;
        cin >> connectedNodes;
        loop(j, connectedNodes)
        {
            int to, cost;
            cin >> to >> cost;
            adjListWeight[i].push_back(make_pair(to, cost));
        }
    }
}
