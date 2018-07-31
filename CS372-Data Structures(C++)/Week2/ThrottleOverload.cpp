/*
William Kelley
wkelley2@my.athens.edu
CS372-ASU
ID#: 70391
Week2-Shift Positions(Contd)
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
	throttle(int size, int cur_pos);
	void shut_off() { position = 0; }
	void shift_throttle(int amount);
	int throttle::get_cur_position();
	int throttle::get_top_position();
	double flow() const { return position / double(top_position); }
	bool is_on() const { return (position > 0); }
	friend ostream &operator<<(ostream&, throttle &t);
	void throttle::display();
	bool throttle::operator!=(throttle &t);
	bool throttle::operator==(throttle &t)
	{
		if (this->position == t.position)
			return true;
		else
			return false;
	}
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

throttle::throttle(int size, int cur_pos)
{
	assert(size > 0);
	top_position = size;
	position = cur_pos;
}

void throttle::shift_throttle(int amount)
{
	position += amount;

	if (position < 0)
		position = 0;
	else if (position > top_position)
	{
		outfile << "You blew up the engine!!\n";
		position = 0;
	}

}

int throttle::get_cur_position()
{
	return position;
}

int throttle::get_top_position()
{
	return top_position;
}

ostream &operator<<(ostream&, throttle &t)
{
	outfile << "Max Position:     " << t.top_position << endl;
	outfile << "Current Position: " << t.position << endl;
	return outfile;
}

bool throttle::operator!=(throttle &t)
{
	if (this->position != t.position)
		return true;
	else
		return false;
}

int main()
{
	outfile.open("throttle-results.txt");
	outfile << "throttle-results.txt -- William Kelley\n";
	throttle car;
	throttle truck(30);
	throttle shuttle(20, 6);
	throttle mythrottle(truck);
	//EXPLICIT CALL(operator ==)
	outfile << "Explicit call(==):\n";
	if (shuttle.operator==(truck))
		outfile << "Shuttle and Truck throttles equal...\n";
	else
		outfile << "Shuttle and Truck throttles not equal...\n";
	//IMPLICIT CALL(Nice Version)(operator ==)
	outfile << "Implicit call(==):\n";
	if (shuttle == truck)
		outfile << "Shuttle and Truck throttles equal...\n";
	else
		outfile << "Shuttle and Truck throttles not equal...\n";


	//EXPLICIT CALL(operator !=)
	outfile << "Explicit call(!=):\n";
	if (mythrottle.operator!=(truck))
		outfile << "mythrottle and Truck throttles not equal...\n";
	else
		outfile << "mythrottle and Truck throttles equal...\n";
	//IMPLICIT CALL(Nice Version)(operator !=)
	outfile << "Implicit call(!=):\n";
	if (mythrottle != truck)
		outfile << "mythrottle and Truck throttles not equal...\n";
	else
		outfile << "mythrottle and Truck throttles equal...\n";


	outfile << "Car\n";
	outfile << car;
	outfile << "Truck\n";
	outfile << truck;
	outfile << "Shuttle\n";
	outfile << shuttle;
	outfile << "mythrottle(truck)\n";
	outfile << mythrottle;

	return EXIT_SUCCESS;
}