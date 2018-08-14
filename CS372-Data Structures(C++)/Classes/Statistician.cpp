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
	int statistician::get_length() {return length; };
	double statistician::get_sum() {return sum; };
	double statistician::get_average() {return average; };
	double statistician::get_smallest() { return smallest; };
	double statistician::get_largest() { return largest; };
	double statistician::get_last() { return last; };
	void statistician::addition(statistician& a, statistician& b);
	statistician statistician::operator+(statistician &S);
	friend ostream &operator<<(ostream&, statistician &S);
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

ostream &operator<<(ostream&, statistician &S)
{
	outfile << "Length:   " << S.get_length() << endl;
	outfile << "Sum:      " << S.get_sum() << endl;
	outfile << "Average:  " << fixed << setprecision(1) << S.get_average() << endl;
	outfile << "Smallest: " << S.get_smallest() << endl;
	outfile << "Largest:  " << S.get_largest() << endl;
	outfile << "Last:     " << S.get_last() << endl;
	return outfile;
}

statistician statistician::operator+(statistician &S)
{
	statistician z;
	z.length = this->length + S.length;
	z.sum = this->sum + S.sum;
	z.average = z.sum / z.length;
	//smallest
	if (this->smallest < S.smallest)
		z.smallest = this->smallest;
	else
		z.smallest = S.smallest;
	//largest
	if (this->largest > S.largest)
		z.largest = this->largest;
	else
		z.largest = S.largest;
	z.last = S.last; //the 2nd instance should have the most recent entry
	return z;
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
	outfile.open("statistician-results.txt");
	outfile << "statistician-results.txt -- William Kelley\n";
	statistician s1;
	s1.next_number(5.5);
	s1.next_number(6.6);
	s1.next_number(8.8);
	s1.next_number(-3.4);
	s1.next_number(-0.5);
	s1.next_number(4.7);
	s1.next_number(9.1);

	outfile << "s1 statistician:\n";
	outfile << "Sum:     " << s1.get_sum();
	outfile << "\nLength:  " << s1.get_length();
	outfile << "\nAverage: " << s1.get_average();
	outfile << endl;

	s1.next_number(5.2);
	s1.next_number(-3.3);
	s1.next_number(-8.5);
	s1.next_number(3.2);
	s1.next_number(5.5);
	outfile << "\ns1 statistician:\n";
	outfile << s1;

	statistician s2(s1);
	outfile << "\ns1 statistician:\n";
	outfile << s1;
	outfile << "\ns2 statistician:\n";
	outfile << s2;

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

	outfile << "\ns2 statistician:\n";
	outfile << "Sum:     " << s2.get_sum();
	outfile << "\nLength:  " << s2.get_length();
	outfile << "\nAverage: " << s2.get_average();
	outfile << endl;

	outfile << "\ns1 statistician:\n";
	outfile << s1;
	outfile << "\ns2 statistician:\n";
	outfile << s2;

	statistician s3;
	s3 = s1 + s2;

	outfile << "\ns1 statistician:\n";
	outfile << s1;
	outfile << "\ns2 statistician:\n";
	outfile << s2;
	outfile << "\ns3 statistician:\n";
	outfile << s3;

	s2 = s1;
	outfile << "\nFinal Prints\n";
	outfile << "\ns1 statistician:\n";
	outfile << s1;
	outfile << "\ns2 statistician(erased):\n";
	outfile << s2;
	outfile << "\ns3 statistician:\n";
	outfile << s3;
	outfile.close();
	return EXIT_SUCCESS;
}