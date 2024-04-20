// narrowing conversions
#include <iostream>

int main() {
	int studentCounter1{1};
	int studentCounter2 = 1;

	int x1 = 12.7; // allowed; truncates to 12
	//int x2{12.7}; // compilation error

	// int arithmetic yields int result
	int total{867};
   int average{total / 10}; // not narrowing
	std::cout << total << " / 10 is " << average << "\n";
}