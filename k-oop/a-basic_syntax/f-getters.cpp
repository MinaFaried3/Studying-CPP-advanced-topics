#include <set>
#include <map>
#include <array>
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
class Answer
{
private:
    string answer_text;

public:
    string GetAnswerText()
    {
        // - Correct
        // - But the return calls copy constructor which takes memory & time
        // - As we don't change data members, C++ OO encourages using const!

        return answer_text;
    }

    string GetAnswerText1() const
    {
        // - Same as above, but now doesn't violate OO
        return answer_text;
    }

    // string &GetAnswerText2() const
    // {
    //     // - Good side: No copy constructor. The reference saves time & memory
    //     // - Bad. A user can make use of the returned string to reset it externally
    //     return answer_text;
    // }

    const string &GetAnswerText3() const
    {
        
    // - Perfect
    // - Return by reference, but prevent him from signing to a different value + const function also
        return answer_text;
    }

};

int main()
{

}