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
	void set_n(int a);
	void set_d(int a);
	friend ostream &operator<<(ostream&, rat &r);
	rat operator+(const rat &r);
	rat operator-(rat &r);
	rat operator*(rat &r);
	rat operator/(rat &r);
	bool operator==(rat &r);
	bool operator!=(rat &r);

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

ostream &operator<<(ostream& cout, rat &r)
{
	cout << r.n << "/" << r.d << endl;
	return cout;
}

rat rat::operator+(const rat &r)
{
	rat q;
	q.n = (((*this).n*r.d) + (r.n*(*this).d));
	q.d = (((*this).d*r.d) + (r.d*(*this).d));
	return q;
}
rat rat::operator-(rat &r)
{
	rat q;
	int tn, td;
	tn = ((r.get_n()*(*this).get_d()) - ((*this).get_n()*r.get_d()));
	td = ((r.get_d()*(*this).get_d()) - ((*this).get_d()*r.get_d()));
	q.set_n(tn);
	q.set_d(td);
	return q;
}
rat rat::operator*(rat &r)
{
	rat q;
	int tn, td;
	tn = r.get_n()*(*this).get_n();
	td = r.get_d()*(*this).get_d();
	q.set_d(td);
	q.set_n(tn);
	return q;
}
rat rat::operator/(rat &r)
{
	rat q;
	q.n = r.n*(*this).d;
	q.d = r.d*(*this).n;
	return q;
}

bool rat::operator==(rat &r)
{
	bool equal(1);
	if ((this->n == r.n) && (this->d == r.d))
		equal = 1;
	else
		equal = 0;
	return equal;
}

bool rat::operator!=(rat &r)
{
	bool nequal(1);
	if ((this->n != r.n) || (this->d != r.d))
		nequal = 1;
	else
		nequal = 0;
	return nequal;
}

int main()
{
	rat a(3, 8);
	rat b(4, 7);
	rat c(1, 5);
	rat d(4, 12);
	rat e(3, 5);
	rat f(4, 1);
	rat g(3, 0);
	rat x, y, z;

	bool temp_bool;

	//Display All Object Values

	cout << "a: " << a
		 << "b: " << b
		 << "c: " << c
		 << "d: " << d
		 << "e: " <<e
		 << "f: " << f
		 << "g: " << g;

	//Mathematical Operations

	cout << "(a + b)           :" << (a + b);

	cout << "(c * d)           :" << (c * d);

	cout << "(d / e)           :" << (d / e);

	cout << "(c - a)           :" << (c - a);

	cout << "((a + b)*(f - d)) :" << ((a + b)*(f - d));

	cout << "((d / a) + c)     :" << ((d / a) + c);
	
	//True and False
	cout << "1 = True, 2 = False...\n";

	temp_bool = (d == b);
	cout << "(d==b)            :" << temp_bool << endl;

	temp_bool = (e != a);
	cout << "(e!=a)            :" << temp_bool << endl;

	return 0;
}