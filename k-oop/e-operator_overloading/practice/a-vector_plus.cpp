#include <iostream>
#include <vector>
using namespace std;

/*
Extend the functionality of
vector<int> to allows adding 2
vectors.
● The smaller vector in length is added
to the large vector
○ Large[i] += small[i]
*/

vector<int> operator+(const vector<int> &a, const vector<int> &b)
{
    if (a.size() > b.size())
    {
        cout << "recursive call" << endl;
        return b + a;
    }

    vector<int> c = b;
    for (int i = 0; i < (int)a.size(); ++i)
    {
        cout << c[i] << endl;
        c[i] += a[i];
    }
    return c;
}

int main()
{
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {10, 20};

    vector<int> c = a + b;

    for (int i = 0; i < (int)c.size(); ++i)
        cout << c[i] << " "; // 11 22 3 4

    return 0;
}
