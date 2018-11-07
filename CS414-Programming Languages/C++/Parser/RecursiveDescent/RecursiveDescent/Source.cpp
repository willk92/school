/*
William Kelley
Recursive Decent Parser
CS414-Programming Languages
Source.cpp
*/

#include "parser1.h"

using namespace std;

int main()
{
	ifstream input;
	input.open("input1.txt");
	while (!input.eof())
	{
		string line;
		const char *next;
		getline(input, line);
		line.erase(remove(line.begin(), line.end(), ' '), line.end());
		//^gets rid of whitespace 
		next = &line[0];
		try {
			parser1 parser1(next);
		}
		catch (...) {
			cout << "Not syntatically correct\n";
		}
		cout << "\n";
	}
	input.close();

	// Build out parser2
	system("PAUSE");
}