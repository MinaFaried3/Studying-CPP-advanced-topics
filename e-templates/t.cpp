#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
void fun(T a)
{
    cout << "[" << a << "]";
}

template <>
int fun(string str)
{
    cout << "{{" << str << "}}";

    return str.size();
}

int main()
{
    fun(10.5), fun("mostafa");

    return 0;
}


#include <iostream>
#include <algorithm>
using namespace std;
 
template<class T>
void fun(T a) {
	cout << "[" << a << "]";
}
 
template<>
void fun(string str) {
	cout << "{{" << str << "}}";
}
 
int main() {
	fun(10.5), fun("mostafa");
 
	return 0;
}