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

const int buffer_size = 4;

struct linky
{
	string a;
	linky *next;
};

linky *head, *c;

linky *myNewNode()
{
	linky *tp;
	tp->a = "";
	tp->next = NULL;
	return tp;
}

void insert(string x)
{
	linky *c, *p, *t;
	int counter = 0;
	if (head == NULL)
	{
		head = myNewNode();
		head->a = x;
		head->next = NULL;
	}
	else
	{
		c = head;
		p = NULL;
		while ((c != NULL && c->a < x))// || counter < buffer_size)
		{
			p = c;
			c = c->next;
			//counter++;
		}
		t = myNewNode();
		t->next = c;
		if (p != NULL)
			p->next = t;
		else
			head = t;
	}
	return;
}

void print_list()
{
	linky *c;
	c = head;
	while (c != NULL)
	{
		cout << c->a << endl;
		c = c->next;
	}
	return;
}
