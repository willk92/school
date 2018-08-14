//Stack

#include "general_list.h"
#include "stacky.h"

using namespace std;

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

ElementType stack::get_element(i);
{
	return stack_list.get_element(i);
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