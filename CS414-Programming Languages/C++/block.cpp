// William Kelley
// Investigation-Print out value out of scope(Doesn't work)
// CS414-Programming Languages
// block.cpp

#include <iostream>
#include <string>

using namespace std;

int main()
{
	{
		int sum = 0;
		for (int i = 1; i <= 10; ++i) {
			sum = sum + i;
		}
	}
	cout << sum;
}

// Will not compile. States the identifier "sum" is undefined and is an undeclared identifier.
// This is due to the value being out of scope.