/*
William Kelley
wkelley2@my.athens.edu
CS372-ASU
ID#: 70391
Week1-Widget Program
*/

#include <string>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

ifstream infile;
ofstream outfile;

class widget
{
public:
	widget();
	void widget::set_widg(int num_toys);
	void widget::set_dm();
	void widget::display();
private:
	int num_widg;
	int mins_per_widg;
	float days_manufacturing;
};
//Constructor
widget::widget()
{
	num_widg = 0;
	mins_per_widg = 6;
	days_manufacturing = 0.0;
}
//Setter
void widget::set_widg(int a)
{
	num_widg = a;
}
void widget::set_dm()
{
	days_manufacturing = ((mins_per_widg * num_widg) / 480.0);
}
//Display
void widget::display()
{
	outfile << "Days to Manufacture " << num_widg << " Toys: " << fixed << setprecision(1) << days_manufacturing << endl;
}

int main()
{
	int x;
	widget car;
	cout << "How many widgets are desired to be manufactured?\n";
	cin >> x;
	car.set_widg(x);
	car.set_dm();
	outfile.open("widgetfactory_results.txt");
	outfile << "widgetfactory_results.txt)\n";
	car.display();
	outfile.close();

	return 0;
}