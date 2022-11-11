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
    //! notice if sumUnaryRight() => CEs
}
//-----------------------------------------------------
// * 1 unary left fold
template <typename... Args>
auto sumUnaryLeft(Args... args)
{
    return (... + args);
    /*
    (1+ ... )
    (1+(2+ ...) )
    (1+(2+ (3+...) )
    */

    //? notice if sumUnaryLeft(num) => num
    //! notice if sumUnaryLeft() => CE
}
//-----------------------------------------------------
int main()
{
    cout << "1 unary right folds " << endl;
    cout << sumUnaryRight(1, 2, 3, 4, 5, 6) << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "* 1 unary left fold " << endl;
    cout << sumUnaryLeft(1, 2, 3, 4, 5, 6) << endl;
}