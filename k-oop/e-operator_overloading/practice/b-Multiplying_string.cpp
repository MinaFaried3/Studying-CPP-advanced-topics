#include<iostream>
#include<vector>
using namespace std;


/*
Extend the functionality of string to
allow multiplying with a number
○ A.g. “hi” * 2 ⇒ “hihi”
*/
string operator *(const string &c1, int num) {
	if(num <= 0)
		return "";

	string ret;
	while(num--)
		ret += c1;
	return ret;
}

int main() {
	string a = "bad";
	string b = "I am " + a * 3 + ", right?";

	cout<<b;	// I am badbadbad, right?


	return 0;
}

