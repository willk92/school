//General List (Header)

#ifndef GENERAL_LIST_H
#define GENERAL_LIST_H

#include <iostream>
#include <iomanip>

using namespace std;

typedef char ElementType;

const int SIZE = 65;

class list
{
private:
	ElementType ary[SIZE];
	int used;
	int position;
public:
	list();
	list(const list &a);
	bool empty() const;
	bool full() const;
	void first();
	void last();
	void prev();
	void next();
	int get_position() const;
	void set_position(int a);
	void insert_before(ElementType a);
	void insert_after(ElementType a);
	ElementType get_element() const;
	ElementType get_element(int pos) const;
	int get_size() const;
	void replace(ElementType a);
	void erase();
	void clear();
	bool reverse();
	void operator = (const list &a);
	friend list operator + (const list &a, const list &b);
};

ostream &operator << (ostream &cout, const list &x);
bool operator == (const list& a, const list& b);

#endif