/*
William Kelley
LISP Interpreter
CS414-Programming Languages
Cell.h
*/

#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

struct cell
{
	char value;
	cell *down = nullptr;
	cell *right = nullptr;
	cell();
	cell(char val);
	~cell();
};

void print(cell *ptr);
cell * eval(cell *ptr);
cell * car(cell *ptr);
cell * cdr(cell *ptr);
cell * cons(cell *ptr);
cell * deepCopy(cell *ptr);

#include "Cell.hxx"