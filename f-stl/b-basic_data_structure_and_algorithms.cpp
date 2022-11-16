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
#include <set>
#include <unordered_set>
using namespace std;
#define lol long long int
#define endl '\n'
// * 6 - push struc in set
struct Employee
{
    int age;
    string name;

    Employee(string name, int age) : age(age), name(name)
    {
    }

    bool operator<(const Employee &emp) const
    {
        //? 1-
        if (name != emp.name)
            return name < emp.name;
        if (age != emp.age)
            return age < emp.age;

        //? 2- we can use pair also
        // return make_pair(name, age) < make_pair(name, age);
        //? 2- we can use tir also
        // return tie(name, age) < tie(name, age);
    }

    void print()
    {
        cout << name << " " << age << endl;
    }
};
int main()
{
    // * 1 - vector
    cout << " 1 - vector :- " << endl;
    vector<int> vec(5, 8); // init 5 items with its values 8
    vec.push_back(3);
    for (auto val : vec)
        cout << val << " ";
    cout << endl;

    // we can use at() to avoid crush
    //? notice the assignment

    vec.at(5) = 10;
    cout << "at(5) => " << vec.at(5) << endl;

    // erase at looping
    // ?notice we increase itr in else scope and if scope because erase fun return the next itr
    for (auto itr = vec.begin(); itr != vec.end();)
    {
        if (*itr % 4 == 0)
        {
            // erase return the next itr
            itr = vec.erase(itr);
            // vec.erase(itr); //?we can also use it like this
        }
        else
        {
            itr++;
        }
    }

    cout << "looping after erase : ";
    for (auto val : vec)
        cout << val << " ";
    cout << endl;

    // find and insert
    vector<int> vec2{0, -1, 2, 3, 4, -3 - 6, 8};

    vector<int>::iterator itr = find(vec2.begin(), vec2.begin(), 0);

    cout << "itr : " << *itr << " vec2.end  " << *vec2.end() << endl;

    vector<int> vec3{3, 3, 3, 34, 4, 4, 4};
    vec2.insert(itr, vec3.begin(), vec3.end());

    cout << "looping after find and insert : ";
    for (auto val : vec2)
        cout << val << " ";
    cout << endl;
    cout << endl
         << "-----------------------------------------------------------" << endl
         << endl;
    // * 2 - string
    cout << " 2 - string" << endl;

    string str = "mina faried essa abc abc abc";
    cout << "sub 2 " << str.substr(2) << endl;      // start from  index 2
    cout << "sub 2,5 " << str.substr(2, 5) << endl; // start from index 2 and end in 5

    cout << "find fa : " << str.find("fa") << endl;              // return first index starts with it
    cout << "find ab at 14 : " << str.find("ab", 13) << endl;    // return first index starts with it after 14 index
    cout << "find gerges : " << (int)str.find("gerges") << endl; // return -1 if casting to int

    cout << "the last of cba : " << str.find_last_of("cba") << " size " << str.size() << endl; // print the most last index of (c,b,a)
    cout << "the firs of cbm : " << str.find_first_of("cbm") << endl;                          // print the most first index of (c,b,m)
    cout << "the firs of cfm , 5: " << str.find_first_of("cfm", 5) << endl;                    // print the most first index of (c,b,m) after 5 index
    cout << "the not firs of abc : " << str.find_first_not_of("abc") << endl;                  // print the most first index not start with (a,b,c) after 5 index

    // replace
    /*
     the first argument is index that from it we will start replacement
     the second is length of string that will be replaced
    */
    str.replace(1, 16, "m"); // replace start from index 1 until 1+16 remove it and put m
    cout << "replace 1 16 " << str << endl;

    cout << endl;
    cout << endl
         << "-----------------------------------------------------------" << endl
         << endl;
    cout << " 3 - algorithms :-" << endl;

    vector<int> sortedVec{2, 4, 6, 9, 8, 645, 34, 2, 4345, 56, 6, 87, 67456};
    // Descending sort
    sort(sortedVec.rbegin(), sortedVec.rend());

    for (auto val : sortedVec)
        cout << val << " ";
    cout << endl;

    cout << endl
         << "-----------------------------------------------------------" << endl
         << endl;

    cout << " 4 - set :-" << endl;
    set<int> set1;

    set1.insert(3);
    set1.insert(39);
    set1.insert(23);
    set1.insert(65);
    set1.insert(75);
    set1.insert(32);

    set<int>::iterator setItr = set1.find(39);

    // remove element from set
    if (setItr != set1.end())
        set1.erase(setItr);
    cout << endl
         << "-----------------------------------------------------------" << endl
         << endl;

    cout << " 5 - multi set :-" << endl;
    //? multi set is accept duplicates in order way
    multiset<string> multiset1;

    multiset1.insert("mina");
    multiset1.insert("mina");
    multiset1.insert("faried");
    multiset1.insert("faried");
    multiset1.insert("faried");
    multiset1.insert("essa");

    multiset<string>::iterator mSItr = multiset1.find("mina");

    // remove element from set
    if (mSItr != multiset1.end())
        multiset1.erase(mSItr);

    for (auto val : multiset1)
        cout << val << " ";
    cout << endl;

    cout << endl
         << "-----------------------------------------------------------" << endl
         << endl;

    cout << " 6 - push struc in set  :-" << endl;
    set<Employee> setEmp;
    setEmp.insert(Employee("mina", 21));
    setEmp.insert(Employee("faried", 55));
    setEmp.insert(Employee("essa", 90));
    setEmp.insert(Employee("mina", 29));

    for (auto val : setEmp)
        val.print();
    cout << endl;
    cout << endl
         << "-----------------------------------------------------------" << endl
         << endl;

    cout << " 7 - unordered set  :-" << endl;
    unordered_set<int> unorderedSet{2, 5, 6, 7, 8};
    //? notice the insert is in front with no duplicates
    //? unordered set is a very fast data structure because it use a hash function
    unorderedSet.insert(3);
    unorderedSet.insert(4);
    unorderedSet.insert(4);
    unorderedSet.insert(3);

    for (auto val : unorderedSet)
        cout << val << " ";
    cout << endl;

    // more in find function

    auto uOItr = unorderedSet.find(8); // FAST
    cout << "uOItr : " << *uOItr << endl;

    // this is generic way
    auto uOItr2 = find(unorderedSet.begin(), unorderedSet.end(), 8); // SLOW
    cout << "uOItr2 : " << *uOItr2 << endl;

    int arr[]{2, 5, 6, 7, 8};
    unordered_set<int> unorderedSet2(arr, arr + 4); // takes only 4 element from array
    cout << "create set from array" << endl;
    for (auto val : unorderedSet2)
        cout << val << " ";
    cout << endl;
}