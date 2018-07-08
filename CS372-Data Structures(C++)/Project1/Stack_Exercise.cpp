/*
William Kelley
CS 372 - ASU
St ID: 70391
wkelley2@my.athens.edu

STACK PROGRAM
including files(general_list.h, general_list.cpp)
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "general_list.h"

ifstream infile;
ofstream outfile;

using namespace std;

class stack
{
private:
	list stack_list;
public:
	bool full() const;
	bool empty() const;
	void clear();
	int get_size() const;
	void push(ElementType a);
	ElementType pop();
	ElementType top();
	bool compare(ElementType a, ElementType b);
	bool balanced(string s);
};

bool stack::full() const
{
	return stack_list.full();
}

bool stack::empty() const
{
	return stack_list.empty();
}

void stack::clear()
{
	stack_list.clear();
}

int stack::get_size() const
{
	return stack_list.get_size();
}

void stack::push(ElementType a)
{
	stack_list.last();
	stack_list.insert_after(a);
}

ElementType stack::pop()
{
	ElementType temp = top();
	stack_list.last();
	stack_list.erase();
	return temp;
}

ElementType stack::top()
{
	stack_list.last();
	return stack_list.get_element();
}

bool stack::compare(ElementType a, ElementType b)
{
	const int size = 8;
	ElementType check[size] = { '(' , ')', '[', ']', '{', '}', '<', '>' };
	int i = 0;
	bool temp(false);
	//Checking beginning and end notation
	while (i < size && temp == false)
	{
		if (a == check[i] && b == check[i + 1])
			temp = true;
		i += 2;
	}
	return temp;
}

bool stack::balanced(string s)
{
	int i = 0;
	while (s[i])
	{
		//Push if beginning notation
		if (s[i] == '{' || s[i] == '(' || s[i] == '[' || s[i] == '<')
			push(s[i]);
		//Comparing if ending notation
		if (s[i] == '}' || s[i] == ')' || s[i] == ']' || s[i] == '>')
		{
			if (empty())
				return false;
			else if (!compare(pop(), s[i]))
				return false;
		}
		i++;
	}
	if (empty())
		return true;
	else
		return false;
}

int main()
{
	stack stacky;

	string data;

	outfile.open("Stack_4File_results.txt");

	//Input Data from Handout ----------------------------------

	infile.open("input_from_sheet.txt");
	outfile << "Stack Results from Sheet Input\n";	
	while (getline(infile, data))
	{
		outfile << data;
		if (stacky.balanced(data))
		{
			outfile << " - Balanced." << endl;
			stacky.clear();
		}
		else
		{
			outfile << " - Mismatched." << endl;
			stacky.clear();
		}
	}
	infile.close();

	//Stack3.dat file -------------------------------------------

	infile.open("Stack3.dat");
	outfile << endl << "Stack Results of Stack3.dat\n";
	while (getline(infile, data))
	{
		if (data != "")
		{
			outfile << data;
			if (stacky.balanced(data))
			{
				outfile << " - Balanced." << endl;
				stacky.clear();
			}
			else
			{
				outfile << " - Mismatched." << endl; 
				stacky.clear();
			}
		}
	}
	infile.close();

	//Lisp Class Data file --------------------------------------

	infile.open("LispClassData.txt");
	outfile << endl << "Stack Results of LispClassData\n" << endl;
	while (getline(infile, data))
	{
		if (data != "")
		{
			outfile << data;
			if (stacky.balanced(data))
			{
				outfile << " - Balanced." << endl; 
				stacky.clear();
			}
			else
			{
				outfile << " - Mismatched." << endl;
				stacky.clear();
			}
		}
	}
	infile.close();

	//Lisp Class Data2 file -------------------------------------

	infile.open("LispClassData2.txt");
	outfile << endl << "Stack Results of LispClassData2\n" << endl;
	while (getline(infile, data))
	{
		if (data != "")
		{
			outfile << data;
			if (stacky.balanced(data))
			{
				outfile << " - Balanced." << endl;
				stacky.clear();
			}
			else
			{
				outfile << " - Mismatched." << endl;
				stacky.clear();
			}
		}
	}
	
	outfile.close();

	return 0;
}

