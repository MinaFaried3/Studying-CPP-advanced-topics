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
lol gcd(lol a, lol b)
{
    return b == 0 ? a : gcd(b, a % b);
}
lol lcm(lol a, lol b) { return a / gcd(a, b) * b; }

// * 1 - BFS with Shortest path from root node (start)
const int OO = 1e6;
vector<int> BFS_shortest_path(int start, vector<vector<int>> &adjacentList)
{
    vector<int> result(sz(adjacentList), OO);
    queue<pair<int, int>> que;

    que.push(make_pair(start, 0));
    result[start] = 0;

    int curr_node, depth;

    while (!que.empty())
    {
        pair<int, int> front = que.front();
        que.pop();

        curr_node = front.first;
        depth = front.second;

        for (int i = 0; i < adjacentList[curr_node].size(); i++)
        {
            int child_node = adjacentList[curr_node][i];

            if (result[child_node] == OO)
            {
                que.push(make_pair(child_node, depth + 1));
                result[child_node] = depth + 1;
            }
        }
    }

    return result;
}

// * another way more efficient in memory because of not using pair<> in queue
// depend on the size of queue in curr_node is the same level
vector<int> BFS2(int s, vector<vector<int>> &adjList)
{
    vector<int> len(sz(adjList), OO);
    queue<int> q;
    q.push(s), len[s] = 0;

    int dep = 0, cur = s, sz = 1;
    for (; !q.empty(); ++dep, sz = q.size())
    {
        while (sz--)
        {
            cur = q.front(), q.pop();
            loop0(i, adjList[cur]) if (len[adjList[cur][i]] == OO)
                q.push(adjList[cur][i]),
                len[adjList[cur][i]] = dep + 1;
        }
    }
    return len; // cur is the furthest node from s with depth dep
}

//-----------------------------------------------------------

// * 2 - search for shortest path from node to another

vector<int> BFS_path(int start, int destination, vector<vector<int>> &adjacentList)
{
    vector<int> result(sz(adjacentList), OO);
    vector<int> parent(sz(adjacentList), -1);
    queue<int> que;

    que.push(start);
    result[start] = 0;

    int curr_node = start;
    int depth = 0;
    int size = 1;
    bool search = true;

    for (; search && !que.empty(); ++depth, size = que.size())
    {
        while (search && size--)
        {
            curr_node = que.front();
            que.pop();

            for (int i = 0; i < adjacentList[curr_node].size(); i++)
            {
                int child_node = adjacentList[curr_node][i];
                if (result[child_node] == OO)
                {
                    que.push(child_node);
                    result[child_node] = depth + 1;
                    parent[child_node] = curr_node;

                    if (child_node == destination) // we found target no need to continue
                    {
                        search = false;
                        break;
                    }
                }
            }
        }
    }

    vector<int> path;
    while (destination != -1)
    {
        path.push_back(destination);
        destination = parent[destination];
    }

    reverse(all(path));

    return path;
}

//-----------------------------------------------------------

// All is done by 1 BFS
// 1-1, 1-m
// m-1 -> Reverse it, start with target and go to sources
// m-m -> Set all start nodes in Q, and find targets

// Testing a graph for bipartiteness

// Edge Split, Vertex Split Tricks



// N=5
// 3	3
// 3 - 6, 6 - 7, 7 - 8
// in(3) = 3, out(3) = 8
// sp(1, 3) = sp( in(1), out(3)) = (1, 8)


int main()
{
}