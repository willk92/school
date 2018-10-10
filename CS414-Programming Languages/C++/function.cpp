// William Kelley
// Investigation - Setting up function like Algol does
// CS414-Programming Languages
// function.cpp

#include <iostream>
#include <string>

using namespace std;

int Foo();

int main()
{
	int a, b, c;
	Foo();
}

int Foo(x, y, z)
int x, y, z;
{
	x = 1;
	y = 1;
	z = 1;
	return (x + y + z);
}

// Compiler will not allow it to run, not even sure how to try to hack at it to try to get it to run.
// Program will not compile.
// If the function didn't receive any arguments pass to it, it could return a value as desired but as is, unable to run program