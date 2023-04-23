#include<iostream>
#include<utility>
#include<vector>
using namespace std;

// Supports copy & move semantics
class MyPair {
private:
	int *firstPtr = nullptr;
	int *secondPtr = nullptr;
public:
	MyPair(int first = 0, int second = 0) {
		cout << "Constructor\n";
		SetFirst(first), SetSecond(second);
	}

	MyPair(const MyPair& other) {		// not changed
		cout << "Copy Constructor\n";
		SetFirst(*other.firstPtr);
		SetSecond(*other.secondPtr);
	}

	MyPair& operator=(MyPair &other) {	// not changed
		cout << "Assignment lvalue\n";
		if (this == &other)			return *this;
		if (other.firstPtr != nullptr)			SetFirst(*other.firstPtr);
		if (other.secondPtr != nullptr)			SetSecond(*other.secondPtr);
		return *this;
		// Sometimes we better create and swap
			// E.g. implement your owne vector
			// then arrays of different length
		// MyPair(other).swap(*this);
	}
	MyPair(MyPair&& other) {
		// delegate to move assignment =
		cout<<"Delegate to operator=(MyPair&&\n";
		*this = std::move(other);
	}
	MyPair& operator=(MyPair&& other) {
		cout << "Assignment rvalue\n";
		if (this == &other)			return *this;
		// No delete or nulltpr
		other.swap(*this);
		// other will be freed in its destructor after call return
		return *this;
	}
	void swap(MyPair& other) {
		std::swap(firstPtr, other.firstPtr);
		std::swap(secondPtr, other.secondPtr);
	}

	~MyPair() {
		cout << "~MyPair()\n";

		if (firstPtr == nullptr && secondPtr == nullptr)
			cout << "\tFreed already by a move!\n";

		if (firstPtr != nullptr)
			delete firstPtr;

		if (secondPtr != nullptr)
			delete secondPtr;
	}
	void SetFirst(int first) {
		if (firstPtr == nullptr)
			firstPtr = new int;
		*firstPtr = first;
	}

	void print() {
		cout << "("  << *firstPtr << "," << *secondPtr << ")\n";
	}
	int GetFirst() const {
		return *firstPtr;
	}

	int GetSecond() const {
		return *secondPtr;
	}
	void SetSecond(int second) {
		if (secondPtr == nullptr)	secondPtr = new int;
		*secondPtr = second;
	}
};

int main() {

	MyPair p1 = move(MyPair(2, 5));
	p1.print();


	return 0;
}
