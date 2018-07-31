/*
William Kelley
wkelley2@my.athens.edu
CS372-ASU
ID#: 70391
Week2-Stastician
*/

#include <cmath>
#include <fstream>
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace std;

ifstream infile;
ofstream outfile;

class statistician
{
public:
	statistician::statistician();
	statistician::statistician(int len, double s, double avg, double small, double large, double la);
	void statistician::next_number(double x);
	void statistician::display();
	void statistician::addition(statistician& a, statistician& b);
private:
	int length;
	double sum;
	double average;
	double smallest;
	double largest;
	double last;
};

statistician::statistician()
{
	length = 0;
	sum = 0;
	average = 0;
	smallest = NULL;
	largest = NULL;
	last = NULL;
}

statistician::statistician(int len, double s, double avg, double small, double large, double la)
{
	length = len;
	sum = s;
	average = avg;
	smallest = small;
	largest = large;
	last = la;
}

void statistician::next_number(double x)
{
	if (length == 0)
	{
		smallest = x;
		largest = x;
		last = x;
	}
	last = x;
	length += 1;
	sum += x;
	if (x < smallest)
		smallest = x;
	if (x > largest)
		largest = x;
	average = sum / length;
}

void statistician::display()
{
	cout << "Length:   " << length << endl;
	cout << "Sum:      " << sum << endl;
	cout << "Average:  " << fixed << setprecision(1) << average << endl;
	cout << "Smallest: " << smallest << endl;
	cout << "Largest:  " << largest << endl;
	cout << "Last:     " << last << endl;
}

void statistician::addition(statistician& a, statistician& b)
{
	length = a.length + b.length;
	sum = a.sum + b.sum;
	average = sum / length;
	//smallest
	if (a.smallest < b.smallest)
		smallest = a.smallest;
	else
		smallest = b.smallest;
	//largest
	if (a.largest > b.largest)
		largest = a.largest;
	else
		largest = b.largest;
	last = b.last; //the 2nd instance should have the most recent entry
}

int main()
{
	statistician s1;
	s1.next_number(5.5);
	s1.next_number(6.6);
	s1.next_number(8.8);
	s1.next_number(-3.4);
	s1.next_number(-0.5);
	s1.next_number(4.7);
	s1.next_number(9.1);
	cout << "s1 statistician:\n";
	s1.display();

	s1.next_number(5.2);
	s1.next_number(-3.3);
	s1.next_number(-8.5);
	s1.next_number(3.2);
	s1.next_number(5.5);
	cout << "\ns1 statistician:\n";
	s1.display();

	statistician s2(s1);
	cout << "\ns1 statistician:\n";
	s1.display(); 
	cout << "\ns2 statistician:\n";
	s2.display();

	s2.next_number(13);
	s2.next_number(21);
	s2.next_number(71);
	s2.next_number(47);
	s2.next_number(12);
	s2.next_number(25);
	s2.next_number(24);
	s2.next_number(23);
	s2.next_number(24);
	s2.next_number(32);

	cout << "\ns2 statistician:\n";
	s2.display();

	statistician s3;
	s3.addition(s1, s2);

	cout << "\ns3 statistician:\n";
	s3.display();

	return EXIT_SUCCESS;
}