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
	void List::display();
	bool List::empty() { return !used; };
	void List::first() { pos = 0; };
	void List::last() { pos = used; };
	void List::prev() { pos--; };
	void List::next() { pos++; };
	size_t List::getPos() { return pos; };
	void List::setPos(int a) { pos = a; };
	void List::insertBefore(int i);
	void List::insertAfter(int i);
	void List::shakedown();
};

List::List()
{
	for (int i = 0; i < CAPACITY; i++)
		mydata[i] = NULL;
	pos = NULL;
	used = NULL;
}
List::List(ElementType ary[], size_t p, size_t u)
{
	for (int i = 0; i < CAPACITY; i++)
		mydata[i] = ary[i];
	pos = p;
	used = u;
}
void List::display()
{
	for (int i = 0; i < CAPACITY; i++)
	{
		if(mydata[i] != NULL)
			cout << mydata[i] << " ";
	}
	cout << endl;
	cout << pos << endl;
	cout << used << endl;
}

void List::insertBefore(int i)
{
	if (pos == 0)
	{
		cout << "Attempt to insert item before possible position, position incremented for next element...\n";
		pos++;
	}
	else if (pos == 19)
	{ 
		mydata[pos - 1] = i;
		used++;
	}
	else
	{
		mydata[pos - 1] = i;
		pos++;
		used++;
	}
	shakedown();
}

void List::insertAfter(int i)
{
	if (pos > 19)
	{
		cout << "Exceeded List Capacity...\n";
	}
	else if (pos == 19)
	{ 
		cout << "Exceeded List Capacity...pos19+1\n";
	}
	else
	{
		mydata[pos + 1] = i;
		pos++;
		used++;
	}
	shakedown();
}

void List::shakedown()
{
	int temp = 0;
	while(temp <= used)
	{
		if (mydata[temp] == NULL)
		{
			for (int i = temp; i < 19; i++)
			{
				mydata[i] = mydata[i + 1];
			}
			temp++;
		}
		else
			temp++;
	}
	mydata[used] = 0;
}



int main()
{
	List a, b;
	for (int i = 1; i <= 20; i++)
		a.insertAfter(i);
	a.getPos();
	for (int i = 1; i <= 20; i++)
		b.insertBefore(i);
	a.display();
	b.display();
}