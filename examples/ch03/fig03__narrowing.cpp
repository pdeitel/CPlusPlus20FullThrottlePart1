// narrowing conversions
#include <iostream>
using namespace std;

int main() {
	int studentCounter1{1};
	int studentCounter2 = 1;

	int x1 = 12.7;
	//int x2{12.7};

	// int arithmetic yields int result
	int total{867};
   int average{total / 10}; // not narrowing
	cout << average << "\n";
}