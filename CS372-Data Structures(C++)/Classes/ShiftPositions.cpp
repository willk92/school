/*
William Kelley
wkelley2@my.athens.edu
CS372-ASU
ID#: 70391
Week1-Shift Positions
*/

#include <cmath>
#include <fstream>
#include <cassert>
#include <iostream>

using namespace std;

ifstream infile;
ofstream outfile;

class throttle
{
private:
	int top_position;
	int position;
public:
	throttle();
	throttle(int size);
	void shut_off() { position = 0; }
	void shift_throttle(int amount);
	double flow() const { return position / double(top_position); }
	bool is_on() const { return (position > 0); }
};

throttle::throttle()
{
	top_position = 6;
	position = 0;
}

throttle::throttle(int size)
{
	assert(size > 0);
	top_position = size;
	position = 0;
}
void throttle::shift_throttle(int amount)
{
	position += amount;

	if (position < 0)
		position = 0;
	else if (position > top_position)
	{
		cout << "You blew up the engine!!\n";
		position = 0;
	}

}

const int DEMO_SIZE = 10;

int main()
{
	throttle sample(DEMO_SIZE);
	int user_input;

	cout << "I have a throttle with " << DEMO_SIZE << " positions." << endl;
	cout << "Where would you like to set the throttle?" << endl;
	cout << "Please type a number from 0 to " << DEMO_SIZE << ": ";
	cin >> user_input;
	sample.shift_throttle(user_input);

	outfile.open("shiftpositions_results.txt");
	outfile << "shiftpositions_results.txt\n";
	outfile << "# of Throttle Positions: " << DEMO_SIZE << endl;
	outfile << "Position Shifted: " << user_input << endl;
	while (sample.is_on())
	{
		outfile << "The flow is now " << sample.flow() << endl;
		sample.shift_throttle(-1);
	}
	outfile << "The flow is now off\n";
	return EXIT_SUCCESS;
}