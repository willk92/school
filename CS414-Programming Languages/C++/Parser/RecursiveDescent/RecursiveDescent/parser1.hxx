/*
William Kelley
Recursive Decent Parser
CS414-Programming Languages
parser1.hxx
*/

#pragma once

parser1::parser1(const char *expr)
{
	lookAhead = expr;
	S();
	std::cout << "Yes\n";
}

void parser1::S()
{
	std::cout << "S( " << lookAhead << " )\n";
	if (lookAhead[0] == '[') {
		lookAhead++;
		A();
		S();
		if (lookAhead[0] != ']')
			error();
		lookAhead++;
	}
	else if (lookAhead[0] == '(') {
		lookAhead++;
		B();
		if (lookAhead[0] != ')')
			error();
		lookAhead++;
		S();
	}
	else {
		return;
	}
}

void parser1::A()
{
	std::cout << "A( " << lookAhead << " )\n";
	if (lookAhead[0] == 'a') {
		lookAhead++;
		APrime();
	}
	else
		error();
}

void parser1::APrime()
{
	std::cout << "APrime( " << lookAhead << " )\n";
	if (lookAhead[0] == '#') {
		lookAhead++;
		A();
		APrime();
	}
	else
		return;
}

void parser1::B()
{
	std::cout << "B( " << lookAhead << " )\n";
	if (lookAhead[0] == 'b') {
		lookAhead++;
		return;
	}
	else if (lookAhead[0] == '?') {
		lookAhead++;
		S();
		if (lookAhead[0] != ',')
			error();
		lookAhead++;
	}
	else if (lookAhead[0] == '.') {
		lookAhead++;
		S();
	}
	else
		error();
}

void parser1::error()
{
	throw("Error");
}

