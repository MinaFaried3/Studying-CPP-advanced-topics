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
#define BREAK cout << "--------------------------------------------------------------------" << endl
#define LABEL(i, title) cout << " " << i << " - " << title << " :-" << endl

// * 1- sliding window maximum
// find vector of maximum nums in some range

vector<int> maxSlidingWindow(vector<int> &arr, int range)
{
    multiset<int> multiSet;
    vector<int> result;

    for (int i = 0; i < range; i++)
        multiSet.insert(-arr[i]); // stored in negative to get big values in first of the set

    result.push_back(-*multiSet.begin()); // extract it by negative to get original value

    for (int i = range; i < arr.size(); i++)
    {
        multiSet.erase(multiSet.find(-arr[i - range]));
        multiSet.insert(-arr[i]);
        result.push_back(-*multiSet.begin());
    }

    return result;
}
//-----------------------------------------------------------
// * 2- create stack logic using queue
struct stackQue
{
    queue<int> que;

    void push(int val)
    {
        int size = que.size();
        que.push(val);

        while (size--)
        {
            que.push(que.front());
            que.pop();
        }
    }

    void pop()
    {
        if (!empty())
            que.pop();
    }

    int top()
    {
        return que.front();
    }

    bool empty()
    {
        return que.empty();
    }
};

//-----------------------------------------------------;
// * 3- reverse number using stack
int reverseByStack(int num)
{
    stack<int> digits;

    while (num)
    {
        digits.push(num % 10);
        num /= 10;
    }

    /*
    in this way
    1 - take num
    2 - take next num * 10^i
    3 - add to it the previous num
    */
    int tens = 1;
    while (!digits.empty())
    {
        num = digits.top() * tens + num;
        tens *= 10;
        digits.pop();
    }

    return num;
}

//-----------------------------------------------------
//! notice this example before point number 4
// find the nest greater element [73,74,75,71,69,72,76,73] => 1 2 6 5 5 6 -1 -1
vector<int> nextGreaterNum(vector<int> &vec)
{
    stack<int> idxStack;

    for (int i = 0; i < (int)vec.size(); i++)
    {
        while (!idxStack.empty() && vec[i] > vec[idxStack.top()])
        {
            vec[idxStack.top()] = i;
            idxStack.pop();
        }

        idxStack.push(i);
    }

    // remain indexes became -1
    while (!idxStack.empty())
    {
        vec[idxStack.top()] = -1;
        idxStack.pop();
    }

    return vec;
}

// * 4 - leetcode 739 medium problem
vector<int> dailyTemperatures(vector<int> &vec)
{
    stack<int> idxStack;

    for (int i = 0; i < (int)vec.size(); i++)
    {
        while (!idxStack.empty() && vec[i] > vec[idxStack.top()])
        {
            vec[idxStack.top()] = i - idxStack.top();
            idxStack.pop();
        }

        idxStack.push(i);
    }

    // remain indexes became -1
    while (!idxStack.empty())
    {
        vec[idxStack.top()] = 0;
        idxStack.pop();
    }

    return vec;
}
int main()
{
    LABEL(1, "sliding window maximum");
    vector<int> allArr{1, 3, -1, -3, 5, 3, 6, 7};
    int range = 3;

    vector<int> result = maxSlidingWindow(allArr, range);
    loop0(result.size())
            cout
        << result[i] << " ";

    cout << endl;

    BREAK; //-------------------------------------------------------------------------------

    LABEL(2, "create stack logic using queue");
    stackQue stk;

    stk.push(1);
    stk.push(2);
    stk.push(3);

    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }

    BREAK; //-------------------------------------------------------------------------------
    LABEL(3, "reverse number using stack");

    cout << 123 << " => " << reverseByStack(123) << endl;

    BREAK; //-------------------------------------------------------------------------------
    LABEL(4, "leetcode 739 medium problem");
    vector<int> vec{73, 74, 75, 71, 69, 72, 76, 73};
    result = dailyTemperatures(vec);
    for (int val : result)
        cout << val << " ";
    cout << endl;
    BREAK; //-------------------------------------------------------------------------------
    LABEL(5, "GET ALL STRINGS START WITH (STR)");
    map<string, vector<string>> nameMap;

    /* try this
mina
mirna
marko
mina
    */
    int size = 4;
    while (size--)
    {
        string name, subName = "";
        cin >> name;

        loop0(name.size())
        {
            subName += name[i];
            nameMap[subName].push_back(name);
        }
    }
    /* try
    m
    mi
    mir
    mina
    */
    size = 4;
    while (size--)
    {
        string str;
        cin >> str;

        for (string name : nameMap[str])
            cout << name << " ";

        cout << endl;
    }
}