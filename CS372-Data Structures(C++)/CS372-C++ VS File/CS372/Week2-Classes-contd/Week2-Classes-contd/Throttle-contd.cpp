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
	void throttle::display();
	void throttle::compare(throttle& t2);
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
		cout << "You blew up the engine!!\n";
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
void throttle::display()
{
	cout << "Max Position: " << top_position << endl;
	cout << "Current Position: " << position << endl;
}

void throttle::compare(throttle& t2)
{
	if (position == t2.position)
		cout << "Throttles equal...\n";
	else
		cout << "Throttles not equal...\n";
}

int main()
{
	throttle car;
	throttle truck(30);
	throttle shuttle(20, 6);
	throttle mythrottle(truck);

	car.compare(truck);
	mythrottle.compare(shuttle);
	
	cout << "Car\n";
	car.display();
	cout << "Truck\n";
	truck.display();
	cout << "Shuttle\n";
	shuttle.display();
	cout << "mythrottle(truck)\n";
	mythrottle.display();
	
	return EXIT_SUCCESS;
}