/*
William Kelley
wkelley2@my.athens.edu
StId: 70391
MultiLinkedList.cpp
*/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

ifstream infile;
ofstream outfile;

struct student
{
	string name_string;
	double grade_value;
	student *next_exempt_in_order;
	student *next_grade_in_order;
	student *next_name_in_order;
};

student *head, *grades_head, *exempt_head; //grades_head holds the pointer to the highest grade, same with exempt

student* myNewStudent()
{
	student *tp;
	tp = new student;
	tp->name_string = "";
	tp->grade_value = 0;
	tp->next_exempt_in_order = NULL;
	tp->next_grade_in_order = NULL;
	tp->next_name_in_order = NULL;
	return tp;
}

void insert_link_grade(student *s, string snx, double gvx)
{
	student *c, *p, *t;
	if (grades_head == NULL)
	{
		s->name_string = snx;
		s->grade_value = gvx;
		grades_head = head;
	}
	else
	{
		c = grades_head;
		p = NULL;
		while (c != NULL && (c->grade_value >= gvx))
		{
			p = c;
			c = c->next_grade_in_order;
		}
		s->name_string = snx;
		s->grade_value = gvx;
		if (p != NULL)
		{
			p->next_grade_in_order = s;
			s->next_grade_in_order = c;
		}
		else
		{
			grades_head = s;
			s->next_grade_in_order = c;
		}
	}
	return;
}

void insert_link_exempt(student *s, double gv)
{
	if (gv > 90)
	{
		outfile << "gv: " << gv << endl;
		student *c, *p, *t;
		if (exempt_head == NULL)
		{
			exempt_head = head;
		}
		else
		{
			c = exempt_head;
			p = NULL;
			while (c != NULL && (c->name_string < s->name_string))
			{
				p = c;
				c = c->next_exempt_in_order;
			}
			if (p != NULL)
			{
				p->next_exempt_in_order = s;
				s->next_exempt_in_order = c;
			}
			else
			{
				exempt_head = s;
				s->next_exempt_in_order = c;
			}
		}
	}
	return;
}

void insert(string sn, double gv)
{
	student *c, *p, *t;
	if (head == NULL)
	{
		head = myNewStudent();
		insert_link_grade(head, sn, gv); //insert data into structure(i dont like it, but it breaks otherwise)
		insert_link_exempt(head, gv);
	}
	else
	{
		c = head;
		p = NULL;
		while (c != NULL && c->name_string < sn)
		{
			p = c;
			c = c->next_name_in_order;
		}
		t = myNewStudent();
		t->next_name_in_order = c;

		if (p != NULL)
		{
			p->next_name_in_order = t;
		}
		else
		{
			head = t;
		}
		insert_link_grade(t, sn, gv);
		insert_link_exempt(t, gv);
	}
	return;
}

void print_names_list()
{
	student *c;
	c = head;
	while (c != NULL)
	{
		outfile << left << setw(15) << c->name_string << fixed << setprecision(0) << c->grade_value << endl;
		c = c->next_name_in_order;
	}
}

void print_grades_list()
{
	student *c;
	c = grades_head;
	while (c != NULL)
	{
		outfile << left << setw(15) << c->name_string << fixed << setprecision(0) << c->grade_value << endl;
		c = c->next_grade_in_order;
	}
}

void print_exempt_list()
{
	student *c;
	c = exempt_head;
	while (c != NULL)
	{
		outfile << left << setw(15) << c->name_string << fixed << setprecision(0) << c->grade_value << endl;
		c = c->next_exempt_in_order;
	}
}

int main()
{
	infile.open("LinkLnamesAndGrades.txt");

	double points_possible(0), sum(0), student_grade(0);
	int counter(0);
	string student_string(" ");

	infile >> points_possible;

	while (infile >> student_string)
	{
		counter++;
		infile >> student_grade;
		student_grade = (student_grade / points_possible) * 100;
		sum = sum + student_grade;
		insert(student_string, student_grade);
	}

	infile.close();

	outfile.open("LinkedListResults.txt");
	outfile << "Linked List(Multi) Results.txt - William Kelley\n";
	outfile << "Names Priority:\n";
	print_names_list();
	outfile << "------------------------------------------------------------------\n";
	outfile << "Grades Priority:\n";
	print_grades_list();
	outfile << "------------------------------------------------------------------\n";
	outfile << "Exempt List:\n";
	print_exempt_list();
	outfile << "------------------------------------------------------------------\n";
	outfile << "Extra Info:" << endl;
	outfile << setw(20) << "Number of Students: " << counter << endl;
	outfile << setw(20) << "Class Average: " << fixed << setprecision(0) << (sum / counter) << endl;
	outfile.close();
}