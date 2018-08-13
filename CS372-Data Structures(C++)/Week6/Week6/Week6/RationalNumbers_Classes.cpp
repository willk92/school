/*
William Kelley
wkelley2@my.athens.edu
CS372 - Rational Class Assignment
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class rat
{
public:
	rat();
	rat(int a, int b);
	void clear_out();
	int get_n();
	int get_d();
	int set_n(int a);
	int set_d(int a);
	friend ostream &operator<<(ostream&, rat &r);
	rat rat::operator+(rat &t);
	rat rat::operator-(rat &r, rat &t);
	rat rat::operator*(rat &r, rat &t);
	rat rat::operator/(rat &r, rat &t);
	rat rat::operator!=(rat &r, rat &t);
	rat rat::operator==(rat &r, rat &t);

private:
	int n;
	int d;
};

rat::rat()
{
	n = d = 0;
}

rat::rat(int a, int b)
{
	n = a;                           //a is numerator
	d = b;                           //b is numerator
}

void rat::clear_out()
{
	n = d = 0;
}

int rat::get_n()
{
	return n;
}

int rat::get_d()
{
	return d;
}

void rat::set_n(int a)
{
	n = a;
}

void rat::set_d(int a)
{
	d = a;
}

ostream &operator<<(ostream&, rat &r)
{
	cout <<  << "/" << r->d << endl;
}

rat rat::operator+(rat &t)
{
	rat q;
	q.n = ((r.n*t.d) + (t.n*r.d));
	q.d = ((r.d*t.d) + (t.d*r.d));
	return q;
}
rat rat::operator -(rat &r, rat &t)
{
	rat q;
	int tn, td;
	tn = ((r.get_n()*t.get_d()) - (t.get_n()*r.get_d()));
	td = ((r.get_d()*t.get_d()) - (t.get_d()*r.get_d()));
	q.set_n(tn);
	q.set_d(td);
	return q;
}
rat rat::operator*(rat &r, rat &t)
{
	rat q;
	int tn, td;
	tn = r.get_n()*t.get_n();
	td = r.get_d()*t.get_d();
	q.set_d(td);
	q.set_n(tn);
	return q;
}
rat rat::operator/(rat &r, rat &t)
{
	rat q;
	q.n = r.n*t.d;
	q.d = r.d*t.n;
	return q;
}
