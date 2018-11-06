/*
William Kelley
LISP Interpreter
CS414-Programming Languages
Cell.hxx
*/

#pragma once

#include <stdio.h>
#include <ctype.h>

using namespace std;

cell::cell()
{
	down = nullptr;
	right = nullptr;
	value = NULL;
}

cell::cell(char val)
{
	down = nullptr;
	right = nullptr;
	value = val;
}

cell::~cell()
{
	down = nullptr;
	right = nullptr;
	value = NULL;
}

cell * build(std::string str, int &cntr){
	if (cntr >= str.length())
		return nullptr;
	char next = str[cntr];
	cell *tp;
	if (next == 39)
		next = str[++cntr];
	if (next == '(')
	{
		tp = new cell(next);
		if (str[cntr + 1] == ' ')
			++cntr;
		tp->down = build(str, ++cntr);
		if (++cntr >= str.length())
		{
			tp->right = nullptr;
			return tp;
		}
		if (str[cntr + 1] == ' ')
			++cntr;
		tp->right = build(str, ++cntr);
		return tp;
	}
	else if (next == ')')
		return nullptr;
	else if (next == '\n')
		return nullptr;
	else if (isalpha(next) && isalpha(str[cntr+1]) && isalpha(str[cntr+2]))
	{
		if (tolower(next) == 'c')
		{
			if (tolower(str[cntr+1]) == 'a')
			{
				tp = new cell('$');
				cntr += 3;
			}
			else if(tolower(str[cntr+1]) == 'd')
			{
				tp = new cell('&');
				cntr += 3;
			}
			else
			{
				tp = new cell('^');
				cntr += 4;
			}
		}
		if (str[cntr+1] == ' ')
			++cntr;
		tp->right = build(str, ++cntr);
		return tp;
	}
	else
	{
		if (next == ' ')
			next = str[++cntr];
		tp = new cell(next);
		if (str[cntr+1] == ' ')
			++cntr;
		tp->right = build(str, ++cntr);
		return tp;
	}
}

void print(cell *ptr)
{
	if (ptr == nullptr)
		return;
	else if (ptr->value == '(')
	{
		std::cout << '(';
		print(ptr->down);
		std::cout << ')';
		print(ptr->right);
	}
	else if (ptr->down == nullptr)
	{
		char com = ptr->value;
		if (com == '$')
			std::cout << "car ";
		else if (com == '&')
			std::cout << "cdr ";
		else if (com == '^')
			std::cout << "cons ";
		else
			std::cout << ptr->value << " ";
		print(ptr->right);
	}
	else
	{
		print(ptr->down);
		print(ptr->right);
	}
}

//$ -> car	& -> cdr  ^ -> cons
cell * eval(cell *ptr)
{
	cell *tp = new cell();
	if (ptr->value == '(')
		tp = eval(ptr->down);
	else if (ptr->value == '$')
		tp = car(ptr->right);
	else if (ptr->value == '&')
		tp = cdr(ptr->right);
	else if (ptr->value == '^')
		tp = cons(ptr->right);
	else
		tp = eval(ptr->right);
	return tp;
}

cell * car(cell *ptr)
{
	cell *tp = new cell('(');
	char a;
	a = ptr->down->value;
	if (a == '$' || a == '&' || a == '^')
		ptr = eval(ptr->down);
	tp->down = ptr->down;
	tp->down->right = nullptr;
	if (tp->down->value == '(')
		tp->down = tp->down->down;
	tp->value = tp->down->value;
	return tp;
}

cell * cdr(cell *ptr)
{
	cell *tp = new cell('(');
	char a = ptr->down->value;
	if (a == '$' || a == '&' || a == '^')
		ptr = eval(ptr->down);
	tp->down = ptr->down->right;
	return tp;
}

cell * cons(cell *ptr)
{
	cell *tp = new cell('(');
	char a;
	if (ptr->down)
	{
		a = ptr->down->value;
		if (a == '$' || a == '&' || a == '^')
			tp->down = eval(ptr->down);
		else
		{
			tp->down = deepCopy(ptr);
			tp->down->right = nullptr;
		}
	}
	else
		tp->down = new cell(ptr->value);
	if (ptr->right->down)
	{
		a = ptr->right->down->value;
		if (a == '$' || a == '&' || a == '^')
		{
			ptr = eval(ptr->right->down);
			cell *temp = tp->down;
			temp->right = ptr->down;
		}
		else
		{
			cell *temp = tp->down;
			temp->right = ptr->right->down;
		}
	}
	else
	{
		cell *temp = tp->down;
		while (temp->right)
			temp = temp->right;
		temp->right = new cell(ptr->right->value);
	}
	return tp;
}

cell * deepCopy(cell *ptr)
{
	if (ptr == nullptr)
		return nullptr;
	cell *node = new cell(ptr->value);
	node->down = deepCopy(ptr->down);
	node->right = deepCopy(ptr->right);
	return node;
}