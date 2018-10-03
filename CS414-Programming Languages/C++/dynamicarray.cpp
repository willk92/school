// William Kelley
// Investigation - Can we build an array passing a value through a function(NO)
// CS414-Programming Languages
// dynamicarray.cpp

#include <iostream>
#include <string>

using namespace std;

bool BuildArray(int n);

int main()
{
	const static int SIZE = 10;
	BuildArray(SIZE);
}

bool BuildArray(int n)
{
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = n + 1;
	}
	return true;
}

// Returns a compiler error complaining about a lack of constant.
// I was unable to get it to run using variations of pass-by-reference constant or just a regular constant.
// Program would not run.