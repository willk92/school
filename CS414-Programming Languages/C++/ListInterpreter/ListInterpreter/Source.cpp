/*
William Kelley
LISP Interpreter
CS414-Programming Languages
Source.cpp
*/
#include "Cell.h"
#include <cmath>

using namespace std;

int main()
{
	ifstream input;
	input.open("input.txt");
	int j = 0;
	while (!input.eof())
	{
		cell *head = nullptr;
		string text;
		int i = 0;
		getline(input, text);
		cout << "Before Build: " << text << "\n";
		head = build(text, i);
		cout << "After Build:  ";
		print(head);
		cout << "\nAfter Eval:   ";
		print(eval(head));
		cout << "\n\n";
	}
}

