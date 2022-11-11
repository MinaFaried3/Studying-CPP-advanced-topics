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

// * 1 unary right fold
template <typename... Args>
auto sumUnaryRight(Args... args)
{
    return (args + ...);
    /*
    (1+ ... )
    (1+(2+ ...) )
    (1+(2+ (3+...) )
    */

    //? notice if sumUnaryRight(num) => num
    //! notice if sumUnaryRight() => CE
}
//-----------------------------------------------------
// * 2 unary left fold
template <typename... Args>
auto sumUnaryLeft(Args... args)
{
    return (... + args);
    /*
    ... + 4
    (... + 3)+4
    ((... +2)+ 3)+4
    */

    //? notice if sumUnaryLeft(num) => num
    //! notice if sumUnaryLeft() => CE
}
//-----------------------------------------------------
// * 4 Binary right fold
template <typename... Args>
auto sumBinaryRight(Args... args)
{
    return (args + ... + 0);
    /*
    (1+ ... )
    (1+(2+ ...) )
    (1+(2+ (3+...+0) )
    */

    //? notice if sumUnaryRight(num) => num
    //! notice if sumUnaryRight() => 0
}
// * 4 Binary Left fold
template <typename... Args>
auto sumBinaryLeft(Args... args)
{
    return (0 + ... + args);
    /*
    0+... + 4
    (0+... + 3)+4
    ((0+... +2)+ 3)+4
    */

    //? notice if sumUnaryLeft(num) => num
    //! notice if sumUnaryLeft() => 0
}
//-----------------------------------------------------

// * 5 Binary right fold multiply
template <typename... Args>
auto multiplyBinaryRight(Args... args)
{
    return (args * ... * 1);
    /*
    (1 *  ... )
    (1 * (2 *  ...) )
    (1 * (2 *  (3 * ... * 1) )
    */

    //? notice if sumUnaryRight(num) => num
    //! notice if sumUnaryRight() => 0
}

//-----------------------------------------------------
// * 6 div right and left
template <typename... Args>
auto divRight(Args... args)
{
    return (args / ...);
}
template <typename... Args>
auto divLeft(Args... args)
{
    return (... / args);
}
//-----------------------------------------------------
// * 7 applying function
template <typename... Args, typename Function>
auto multiplySquares(Function operation, Args... args)
{
    return (operation(args) * ... * 1);
}
int square(int x)
{
    return x * x;
}

//-----------------------------------------------------
// * 8 logical  operators || &&
template <typename... Args>
bool And(Args... args)
{
    return (... && args);
    //! notice all() => 1
}
template <typename... Args>
bool Or(Args... args)
{
    return (... || args);
    //! notice all() => 0
}

// -----------------------------------------------------
// * 9 comma operator
template <typename T>
void pushBackVec(vector<T> &v, auto... args)
{
    (v.push_back(args), ...);

    // Expansion to right

    // (v.push_back(16), );

    // (v.push_back(10), (v.push_back(20), ...));

    // (v.push_back(10), (v.push_back(20), (v.push_back(30))));

    // SO overall: v.push_back(10), v.push_back(20), v.push_back(30)
}

int main()
{
    cout << "* 1 unary right folds " << endl;
    cout << sumUnaryRight(1, 2, 3, 4, 5, 6) << endl;
    cout << "----------------------------------------------------" << endl;

    cout << "* 2 unary left fold " << endl;
    cout << sumUnaryLeft(1, 2, 3, 4, 5, 6) << endl;
    cout << "----------------------------------------------------" << endl;

    cout << "* 3 Binary right fold" << endl;
    cout << sumBinaryRight() << endl;
    cout << "----------------------------------------------------" << endl;

    cout << " * 6 div right and left" << endl;
    cout << "div right 100,10,2: " << divRight(100, 10, 2) << endl;
    cout << "div Left 100,10,2: " << divLeft(100, 10, 2) << endl;
    cout << "----------------------------------------------------" << endl;

    cout << " * 7 applying function" << endl;
    cout << multiplySquares(square, 5, 10) << endl;

    cout << "----------------------------------------------------" << endl;

    cout << " * 8 logical  operators || &&" << endl;
    cout << "and (): " << And() << endl;
    cout << "or (): " << Or() << endl;
    cout << "and (1,1,1): " << And(1, 1, 1) << endl;
    cout << "or (1,0,0): " << Or(1, 0, 0) << endl;
    cout << "----------------------------------------------------" << endl;
}