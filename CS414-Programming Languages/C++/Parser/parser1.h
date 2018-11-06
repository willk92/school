#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>

class parser1
{
private:
	const char *lookAhead;
public:
	parser1(const char *expr);
	void S();
	void A();
	void APrime();
	void B();
	void error();
};

#include "parser1.hxx"
