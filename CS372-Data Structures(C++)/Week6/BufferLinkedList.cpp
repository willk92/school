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

ofstream outfile;
ifstream infile;

struct node
{
	string a;
	node *next;
};

node *head;

node *myNewNode()
{
	node *tp;
	tp = new node;
	tp->a = "";
	tp->next = NULL;
	return tp;
}

void insert(string x, int buffer_size, int &access)
{
	node *c, *p, *t;
	int counter = 1;
	if (head == NULL)
	{
		head = myNewNode();
		head->a = x;
		access++;
	}
	else
	{
		c = head;
		p = NULL;
		while (c != NULL && c->a != x)
		{
			p = c;
			c = c->next;
			counter++;
			if (counter == buffer_size)
				p->next = NULL;
		}
		if (c && c->a == x)
		{
			if (c != head)
			{
				if (p)
					p->next = c->next;
				c->next = head;
				head = c;
			}
		}
		else
		{
			t = myNewNode();
			t->a = x;
			t->next = head;
			head = t;
			access++;
		}
	}
	return;
}

void print_list()
{
	node *c;
	c = head;
	while (c != NULL)
	{
		outfile  << c->a << "|";
		c = c->next;
	}
	return;
}
void run_buffer(int buffer_size)
{
	string target;
	head = NULL;
	int access = 0;
	infile.open("LinkL Var Stream.txt");
	while (infile >> target)
	{
		insert(target, buffer_size, access);
	}
	outfile << "\nBuffer Size(" << buffer_size << ")\n";
	outfile << "Accesses to Memory: " << access << endl;
	print_list();
	outfile << endl;
	infile.close();
}

int main()
{
	outfile.open("BufferEx_LinkedList_results.txt");
	
	run_buffer(4);
	run_buffer(5);
	run_buffer(6);
	run_buffer(7);
	run_buffer(8);

	outfile.close();

	return 0;
}