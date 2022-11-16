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
#include <deque>
#include <iterator>
using namespace std;
#define lol long long int
#define endl '\n'
// * 3 - print sum of last n numbers in stream
struct StreamSum
{
    int size;
    queue<int> currentNums;
    int sum = 0;

    StreamSum(int size)
    {
        this->size = size;
    }

    int next(int newNum)
    {
        currentNums.push(newNum);
        sum += newNum;

        if (currentNums.size() > size)
        {
            sum -= currentNums.front();
            currentNums.pop();
        }

        return sum;
    }
};
int main()
{
    cout << "* 1 - priority queue " << endl;
    // makes the biggest element in the top
    priority_queue<int> priorityQueue;
    priorityQueue.push(2);
    priorityQueue.push(3);
    priorityQueue.push(1);
    priorityQueue.push(6);
    priorityQueue.push(9); //  => 9 6 3 2 1

    cout << "the top of queue => " << priorityQueue.top() << endl;
    cout << "/-------------------------------------------------------" << endl;

    cout << "* 2 - deque " << endl;
    // in deque we can push and pop from front and end(back)
    deque<int> dequeue;
    dequeue.push_back(1);
    dequeue.push_front(2);
    dequeue.push_front(4);
    dequeue.push_front(5);
    dequeue.push_front(6);
    dequeue.pop_front();
    dequeue.pop_back();

    // notice this create a deep copy in the memory
    deque<int> deepCopy = dequeue;

    cout << deepCopy[2] << endl;    // if was [10000] it will make the app crash
    cout << deepCopy.at(2) << endl; // if at(10000) it will throw exception out_of_range

    cout << "/-------------------------------------------------------" << endl;

    // * 3 - print sum of last n numbers in stream
    cout << " * 3 - print sum of last n numbers in stream" << endl;
    StreamSum streamSum(4);
    int numStream;
    // while (cin >> numStream)
    //     cout << streamSum.next(numStream) << endl;

    cout << "/-------------------------------------------------------" << endl;
    cout << "* 4 - pair" << endl;

    pair<int, string> pair1 = make_pair(1, "one");
    pair<int, string> pair2 = make_pair(2, "two");
    cout << "first and second of pair : " << pair1.first << " " << pair1.second << endl;
    // notice the pair support comparison

    if (pair2 >= pair1)
        cout << "pair2 is bigger than pair1" << endl;
    cout << "/-------------------------------------------------------" << endl;
    cout << "* 5 - tuple" << endl;

    tuple<int, string, double> tuple1 = make_tuple(1, "one", 1.0);
    tuple<int, string, double> tuple2 = make_tuple(2, "two", 2.0);

    // get tuple values
    cout << "first and second of tuple : " << get<0>(tuple1) << " " << get<1>(tuple1) << get<2>(tuple1) << endl;

    // notice the tuple support comparison
    if (tuple2 >= tuple1)
        cout << "tuple2 is bigger than tuple1" << endl;

    int intVal;
    string stringVal;
    double doubleVal;

    // we can unpack the tuples values into separate variables
    tie(intVal, stringVal, doubleVal) = tuple2;

    cout << "tie tuple 2  : " << intVal << " " << stringVal << " " << doubleVal << endl;

    // concatenate tuple
    auto tuple3 = tuple_cat(tuple2, make_tuple(20, "twenty"));

    cout << "first and second of tuple3 : "
         << get<0>(tuple3) << " " << get<1>(tuple3) << " " << get<2>(tuple3)
         << " " << get<3>(tuple3) << " " << get<4>(tuple3) << endl;

    cout << "/-------------------------------------------------------" << endl;
    cout << "* 6 - iterator" << endl;

    deque<int> itrQue;
    itrQue.push_back(2);
    itrQue.push_back(4);
    itrQue.push_back(25);
    itrQue.push_back(32);
    itrQue.push_back(6);
    itrQue.push_back(90);

    deque<int>::iterator itr;
    // itrQue.end is after the last element in the array
    cout << "iterator : ";
    for (itr = itrQue.begin(); itr != itrQue.end(); itr++)
    {
        // *itr = 3; // we can override values
        cout << *itr << " ";
    }
    cout << endl;

    // reverse iterator
    deque<int>::reverse_iterator rItr;
    cout << "reverse iterator : ";
    for (rItr = itrQue.rbegin(); rItr != itrQue.rend(); rItr++)
    {

        cout << *rItr << " ";
    }
    cout << endl;

    // arithmetic
    itr = itrQue.begin();
    cout << "*itr : " << *itr << endl;
    cout << "*(itr++) : " << *(itr++) << endl; // print first then ++
    cout << "*itr : " << *itr << endl;
    cout << "*(++itr) : " << *(++itr) << endl; // print ++
    cout << "*itr : " << *itr << endl;
    cout << "*(itr + 2) : " << *(itr + 2) << endl; // notice this not effect in value of itr
    cout << "*itr : " << *itr << endl;
    itr += 2;
    cout << "*itr : " << *itr << endl;

    /// const iterator
    deque<int>::const_iterator cItr;
    cout << "const iterator : ";
    // cbegin cend
    // in const itr we can't override values
    for (cItr = itrQue.cbegin(); cItr != itrQue.cend(); cItr++)
    {
        // *cItr = 3; // error
        cout << *cItr << " ";
    }
    cout << endl;

    cout << "/-------------------------------------------------------" << endl;
    cout << "* 7 - range based for loop " << endl;
    int arr[]{1, 2, 3, 4, 5, 6, 7};
    for (auto val : arr)
        cout << val << " ";
    cout << endl;

    for (const auto &val : itrQue)
        cout << val << " ";
    cout << endl;
}