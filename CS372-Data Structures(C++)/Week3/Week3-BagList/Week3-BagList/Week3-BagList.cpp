/*
William Kelley(70391)
wkelley2@my.athens.edu
CS372-ASU
Week 3 - List Program(Classes)
*/
#include <iomanip>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

ifstream infile;
ofstream outfile;

typedef int ElementType;
static const size_t CAPACITY = 20;

class List
{
private:
	ElementType mydata[CAPACITY];
	size_t pos, used;
public:
	List::List();
	List::List(ElementType ary[], size_t p, size_t u);
	bool List::empty() { return !used; };
	void List::first() { pos = 0; };
	void List::last() 
	{
		if (used < 20)
			pos = used;
		else if (used == 20)
			pos = (used - 1);
	}
	void List::prev() { pos--; };
	void List::next()
	{
		if (used <= 1)
			pos = used - 1;
		else if (pos >= 19 && used == 20)
			pos = 19;
		else
			pos++;
	}
	size_t List::getPos() { return pos; };
	size_t List::getUsed() { return used; };
	void List::setPos(int a) { pos = a; };
	void List::insertBefore(int x);
	void List::insertAfter(int x);
	size_t List::getElement() { return mydata[pos]; };
	size_t List::getElement(int a) { return mydata[a]; };
	size_t List::size() { return used; };
	void List::replace(int a) { mydata[pos] = a; };
	void List::erase();
	void List::clear();
	void List::reverse();
	//OVERLOADS
	friend ostream& operator << (ostream&, List &L);
	bool List::operator = (List& L);
	bool List::operator == (List& L);
};

List::List()
{
	for (int i = 0; i < CAPACITY; i++)
		mydata[i] = NULL;
	pos = 0;
	used = 0;
}
List::List(ElementType ary[], size_t p, size_t u)
{
	for (int i = 0; i < CAPACITY; i++)
		mydata[i] = ary[i];
	pos = p;
	used = u;
}

void List::insertBefore(int x)
{
	int u = used;
	if (u == 0)
	{
		mydata[pos] = x;
		used++;
	}
	else if (u > 0 && u < 20)
	{
		for (int i = u; i > 0; i--)
			mydata[i] = mydata[i - 1];
		mydata[pos] = x;
		used++;
	}
	else if (u == 20 && pos == 0)
		mydata[pos] = x;
	else if (u == 20 && pos == 19)
		mydata[pos - 1] = x;
}

void List::insertAfter(int x)
{
	if (used == 0)
	{
		mydata[pos] = x;
		used++;
	}
	else if (used > 0 && used < 20)
	{
		mydata[pos + 1] = x;
		pos++;
		used++;
	}
	else if (used == 20 && pos == 19)
		mydata[pos] = x;
}


void List::erase()
{
	mydata[pos] = 0;
	if (pos > 0 && used > 0)
		used--;
	
}

void List::clear()
{
	for (int i = 0; i < CAPACITY; i++)
		mydata[i] = NULL;
	pos = 0;
	used = 0;
}

void List::reverse()
{
	size_t temp;
	for ( int i = 0; i < CAPACITY / 2; ++i) 
	{
		temp = mydata[CAPACITY - i - 1];
		mydata[CAPACITY - i - 1] = mydata[i];
		mydata[i] = temp;
	}
}

ostream &operator<<(ostream&, List &L)
{
	for (int i = 0; i < CAPACITY; i++)
	{
		if (L.getElement(i)!=NULL)
			outfile << L.getElement(i) << " ";
	}
	return outfile;
}

bool List::operator = (List& L)
{
	for (int i = 0; i < CAPACITY; i++)
		this->mydata[i] = L.mydata[i];
	this->pos = L.pos;
	this->used = L.used;
	return true;
}

bool List::operator == (List& L)
{
	bool ary(true), position(true),report(true);
	for (int i = 0; i < CAPACITY; i++)
		if (this->mydata[i] != L.mydata[i])
			ary = false;
	if (this->pos != L.pos)
		position = false;
	if (position == false || ary == false)
		report = false;
	return report;
}

	int main()
	{
		outfile.open("BagList-Results.txt");
		List a, b;  int endit;

		for (int i = 1; i <= 20; i++)
			a.insertAfter(i);
		outfile << "List a : " << endl;
		outfile << "  " << a << endl;
		outfile << "Number of elements in a - " << a.size() << endl;

		for (int i = 1; i <= 20; i++)
			b.insertBefore(i);
		outfile << "List b : " << endl;
		outfile << "  " << b << endl;
		outfile << "Number of elements in b - " << b.size() << endl;
		
		if (a == b)
			outfile << "List a & b are equal" << endl;
		else
			outfile << "List a & b are Not equal" << endl;

		a.first();
		b.first();
		outfile << "First elmenet in list a & b: " << a.getElement() << ", "
			<< b.getElement() << endl;
		for (int i = 0; i < a.size(); a.next(), i++);
		for (int i = 0; i < b.size(); b.next(), i++);
		outfile << "Last elmenet in list a & b: " << a.getElement() << ", "
			<< b.getElement() << endl;
		outfile << endl << endl << " Start of new stuff" << endl;

		outfile << "a = " << a << endl;
		outfile << "b = " << b << endl;

		a.first();
		b.first();
		endit = a.size() / 2;
		for (int i = 1; i<endit; i++)
		{
			a.next();
			b.next();
		}

		a.last();
		b.last();
		a.insertAfter(100);
		a.insertBefore(99);
		outfile << " Test last " << endl;
		outfile << "a = " << a << endl;
		outfile << "b = " << b << endl;

		outfile << "New position in Obj 'a' position = " << a.size() / 2 << endl;

		for (int i = 1; i<8; i++)
		{
			a.erase();
			b.replace(i);
		}

		outfile << "Modified Object 'a' " << endl;
		outfile << "List a: " << a << endl;

		List c(b);
		outfile << "Copy Constructor c(b)" << endl;
		outfile << "List b : " << b << endl;
		outfile << "List c : " << c << endl;

		if (c == b)
			outfile << "List c & b are equal" << endl;
		else
			outfile << "List c & b are Not equal" << endl;


		List e;
		e = c;
		outfile << "Object 'c' assigned to Object 'e':" << endl;
		outfile << "List c : " << c << endl;
		outfile << "List e : " << e << endl;

		List d;
		d = a;
		d.first();
		endit = d.size() / 2;
		for (int i = 1; i <= endit; i++)
		{
			d.next();
			d.erase();
		}
		outfile << "Results after some erases: Object d  " << endl;
		outfile << "List d : " << d << endl;

		d.first();
		endit = d.size();
		for (int i = 1; i < endit; d.next(), i++)
		{
			d.insertBefore(d.getElement() * 2);
			d.next();
		}
		outfile << "Results after some Replaces on d " << endl;
		outfile << "List d : " << d << endl;

		a.first();
		endit = a.size();
		for (int i = 1; i < endit; a.next(), i++)
		{
			a.insertBefore(a.getPos() + a.getElement());
			a.next();
			a.erase();
		}
		outfile << "Results after some weird stuff on list a" << endl;
		outfile << "List a : " << a << endl;

		List alist(b);
		alist.clear();
		for (int i = 1; i <= 10; i++)
			alist.insertAfter(i);
		alist.first();
		outfile << "New List alist with positions above: " << endl;
		for (int i = 1; i <= 10; i++) {
			outfile << setw(5) << alist.getPos();
			alist.next();
		}
		outfile << endl;
		alist.first();
		for (int i = 1; i <= 10; i++) {
			outfile << setw(5) << alist.getElement();
			alist.next();
		}
		outfile << endl;

		alist.reverse();
		outfile << "Reverse New List alist : " << endl;
		outfile << "  " << alist << endl;

		List newa;
		for (int i = 1; i <= 20; i++)
			newa.insertAfter(i * 3);
		outfile << "List alist and newa before swap " << endl;
		outfile << " " << alist << endl;
		outfile << " " << newa << endl;

		outfile << endl << "  check out boundary conditions" << endl;
		List sq;
		outfile << "number of elements in empty sq list = " << sq.size() << endl;
		sq.first();
		sq.erase();
		outfile << "empty sq values " << sq << endl;
		sq.insertBefore(999);
		outfile << "sq values " << sq << endl;
		sq.next(); sq.next();
		outfile << "sq.getElement() = " << sq.getElement() << endl;
		outfile << "sq values " << sq << endl;
		outfile.close();
		return 0;
	}