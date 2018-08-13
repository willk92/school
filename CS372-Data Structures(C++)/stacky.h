//Stack(Header)

#ifndef STACKY_H
#define STACKY_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

class stack
{
private:
	list stack_list;
public:
	bool full() const;
	bool empty() const;
	void clear();
	int get_size() const;
	ElementType stack::get_element(i);
	void push(ElementType a);
	ElementType pop();
	ElementType top();
};

#endif