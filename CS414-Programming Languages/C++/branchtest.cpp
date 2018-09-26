/*
William Kelley
CS414-Programming Languages
Investigation
Can you branch into a while loop?
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int counter = 1;
	if (counter == 1)
		goto jumpto;

	while (counter <= 5)
	{
		cout << counter << endl;
	jumpto: cout << "Jumped to middle of while loop\n";
		++counter;
	}

	system("PAUSE");
	return 0;
}

/*
Jumped to middle of while loop(only 1st print out is legitimate
2
Jumped to middle of while loop(only 1st print out is legitimate
3
Jumped to middle of while loop(only 1st print out is legitimate
4
Jumped to middle of while loop(only 1st print out is legitimate
5
*/

/*
Due to the simplicity of my example, I was able to jump to the middle of my while loop.
It passed through compiler
Worked during run-time
Program ran without issues(aside from skipping first print out of initial counter value)
*/