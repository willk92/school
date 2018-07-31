/*
William Kelley(70391)
wkelley2@my.athens.edu
CS372-ASU
Week 5 - Suitors Program - Queue (using GeneralList program)
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

typedef char ElementType;
static const size_t CAPACITY = 65;

class List
{
private:
	ElementType mydata[(CAPACITY+1)];
	size_t pos, used;
public:
	List::List();
	List::List(ElementType ary[], size_t p, size_t u);
	bool List::empty() { return !used; };
	void List::first() { pos = 0; };
	void List::last()
	{
		if (used < CAPACITY)
			pos = used;
		else if (used == CAPACITY)
			pos = (used - 1);
	}
	void List::prev() { pos--; };
	void List::next()
	{
		if (used <= 1)
			pos = used - 1;
		else if (pos >= (CAPACITY-1) && used == CAPACITY)
			pos = (CAPACITY-1);
		else
			pos++;
	}
	size_t List::getPos() { return pos; };
	size_t List::getUsed() { return used; };
	void List::setPos(int a) { pos = a; };
	void List::insertBefore(ElementType x);
	void List::insertAfter(ElementType x);
	ElementType List::getElement() { return mydata[pos]; };
	ElementType List::getElement(int a) { return mydata[a]; };
	size_t List::size() { return used; };
	void List::replace(int a) { mydata[pos] = a; };
	void List::erase();
	void List::clear();
	void List::reverse();
	//OVERLOADS
	friend ostream& operator << (ostream&, List &L);
	bool List::operator = (List& L);
	bool List::operator == (List& L);
	//EXTRAS
	void List::shakedown();
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

void List::insertBefore(ElementType x)
{
	int u = used;
	if (u == 0)
	{
		mydata[pos] = x;
		used++;
	}
	else if (u > 0 && u < CAPACITY)
	{
		for (int i = u; i > 0; i--)
			mydata[i] = mydata[i - 1];
		mydata[pos] = x;
		used++;
	}
	else if (u == CAPACITY && pos == 0)
		mydata[pos] = x;
	else if (u == CAPACITY && pos == (CAPACITY-1))
		mydata[pos - 1] = x;
}

void List::insertAfter(ElementType x)
{
	if (used == 0)
	{
		mydata[0] = x;
		used++;
	}

	else if (used > 0 && used < CAPACITY)
	{
		ElementType temp1, temp2;
		temp1 = mydata[pos];
		temp2 = mydata[pos + 1];
		for (int i = pos; i < used; i++)
		{
			mydata[i + 1] = temp1;
			temp1 = temp2;
			temp2 = mydata[i + 2];
		}
		mydata[pos] = x;
		used++;
		pos++;
	}
	else
		cout << "List full\n";
}


void List::erase()
{
		mydata[pos] = 0;
		if (pos >= 0 && used > 0)
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
	ElementType temp;
	for (int i = 0; i < CAPACITY / 2; ++i)
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
		if (L.getElement(i) != NULL)
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
	bool ary(true), position(true), report(true);
	for (int i = 0; i < CAPACITY; i++)
		if (this->mydata[i] != L.mydata[i])
			ary = false;
	if (this->pos != L.pos)
		position = false;
	if (position == false || ary == false)
		report = false;
	return report;
}

void List::shakedown()
{
	int temp = 0;
	while (temp <= used)
	{
		if (mydata[temp] == NULL)
		{
			for (int i = temp; i < CAPACITY; i++)
			{
				mydata[i] = mydata[i + 1];
			}
			temp++;
		}
		else
			temp++;
	}
	mydata[temp] = 0;
}

/*
Class for Suitor Section(still procrastinating on .h files...)
*/

class queue
{
private:
	List myQ;
public:
	bool queue::full();
	bool queue::empty();
	void queue::enqueue(ElementType v);
	void queue::dequeue();
	void queue::dequeue(int spot);
	void queue::front();
	ElementType queue::current_value(int spot);
	size_t queue::size();
	void queue::shuffle();
	void queue::print();
}; queue suitor;
bool queue::empty()
{
	if (myQ.getUsed() == 0)
		return true;
	else
		return false;
}

bool queue::full()
{
	if (myQ.getUsed() == CAPACITY)
		return true;
	else
		return false;
}

void queue::enqueue(ElementType v)
{
	if (!full())
	{
		myQ.last();
		myQ.insertAfter(v);
	}
}

void queue::dequeue()
{
	if (!empty())
	{
		myQ.erase();
	}
}

void queue::dequeue(int spot)
{
	if (!empty())
	{
		myQ.setPos(spot);
		myQ.erase();
	}
}

void queue::front()
{
	myQ.first();
}

ElementType queue::current_value(int spot)
{
	return myQ.getElement(spot);
}

size_t queue::size()
{
	return myQ.getUsed();
}

void queue::shuffle()
{
	myQ.shakedown();
}

void queue::print()
{
	int i = 0;
	while (i < CAPACITY)
	{
		outfile << right << setw(3) << myQ.getElement(i);
		i++;
	}
	outfile << endl;
}


//==========================================================================================================


int main(int argc, char *argv[])
{
	outfile.open("Suitors-Results.txt");
	size_t priority = 4;

	ElementType khar = 'A';
	for (int i = 0; i < CAPACITY; i++)
	{
		suitor.enqueue(khar);
		khar++;
	}
										// Delete unlucky suitors
	suitor.front();
	int j = priority-1;					//set original priority to start at the 4th element
	int count = 0;
	while(suitor.size() > 1)
	{
		suitor.dequeue(j);

		j=j+4;
		if (j > suitor.size())
		{
			j = (j % (suitor.size()));
			suitor.shuffle();
			count++;
			suitor.print();
		}
	}
	outfile << "Star's lucky suitor is: ";
	suitor.print();

	return 0;
}