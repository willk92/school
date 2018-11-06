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
			parser1 parse(next);
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