//General List

#include "general_list_template.h”

template <class ElementType>
list<ElementType>list<ElementType>()
{
	used = 0;
	position = 0;
}

template <class ElementType>
list<ElementType>list<ElementType>(const list<ElementType> & a)
{
	used = a.used;
	position = a.position;
}

template <class ElementType>
bool list<ElementType>empty() const
{
	if (used == 0)
		return true;
	else
		return false;
}

template <class ElementType>
bool list<ElementType>full() const
{
	if (used == SIZE)
		return true;
	else
		return false;
}

template <class ElementType>
void list<ElementType>first()
{
	position = 0;
}

template <class ElementType>
void list<ElementType>last()
{
	position = used - 1;
}

template <class ElementType>
void list<ElementType>prev()
{
	position--;
}

template <class ElementType>
void list<ElementType>next()
{
	position++;
}

template <class ElementType>
int list<ElementType>get_position() const
{
	return position;
}

template <class ElementType>
void list<ElementType>set_position(int a)
{
	position = a;
}

template <class ElementType>
void list<ElementType>insert_before(ElementType a)

{
	if (used == 0)
	{
		ary[0] = a;
		used++;
		return;
	}
	else if (used < SIZE)
	{
		ElementType temp1 = ary[position], temp2 = ary[position + 1];
		for (int i = position; i < used; i++)
		{
			ary[i + 1] = temp1;
			temp1 = temp2;
			temp1 = ary[i + 2];
		}
		ary[position] = a;
		used++;
		return;
	}
	else
	{
		cout << "At capacity..." << endl;
		return;
	}
}

template <class ElementType>
void list<ElementType>insert_after(ElementType a)
{
	if (used == 0)
	{
		ary[0] = a;
		used++;
		return;
	}
	else if (used < SIZE)
	{
		position++;
		ElementType temp1 = ary[position], temp2 = ary[position + 1];
		for (int i = position; i < used; i++)
		{
			ary[i + 1] = temp1;
			temp1 = temp2;
			temp2 = ary[i + 2];
		}
		ary[position] = a;
		used++;
		return;
	}
	else
	{
		cout << "At capacity..." << endl;
		return;
	}
}

template <class ElementType>
ElementType list<ElementType>get_element() const
{
	if (used > 0)
		return ary[position];
	else
		return -1;
}

ElementType list<ElementType>get_element(int pos) const
{
	if (used > 0)
		return ary[pos];
	else
		return -1;
}

template <class ElementType>
int list<ElementType>get_size() const
{
	return used;
}

void list<ElementType>replace(ElementType a)
{
	ary[position] = a;
}

template <class ElementType>
void list<ElementType>erase()
{
	if (used > 0)
	{
		for (int i = position; i < used; i++)
			ary[i] = ary[i + 1];
		used--;
		if (position == used && position > 0)
			position--;
		ary[used] = 0;
	}
}

template <class ElementType>
void list<ElementType>clear()
{
	for (int i = 0; i < SIZE; i++)
		ary[i] = NULL;
	position = 0;
	used = 0;
}

template <class ElementType>
bool list<ElementType>::reverse()
{
	if (used > 0)
	{
		for (int i = 0; i < (SIZE / 2); i++)
		{
			int temp = ary[i];
			ary[i] = ary[(SIZE - 1) - i];
			ary[(SIZE - 1) - i] = temp;
		}
	}
	return true;
}

template <class ElementType>
void list<ElementType>::operator=(const list<ElementType> & a)
{
	if (a.empty())
		return;
	else
	{
		used = a.get_size();
		position = a.get_position();
		for (int i = 0; i < SIZE; i++)
			ary[i] = a.get_element(i);
		return;
	}
}

template <class ElementType>
list<ElementType> operator+(const list<ElementType> &a, const list<ElementType> &b)
{
	if ((a.get_size() + b.get_size()) > SIZE)
	{
		cout << "Size of both lists exceed single list capacity...\n";
		list<ElementType> temp;
	}
	else
	{
		list<ElementType> temp(a);
		temp.used = a.get_size() + b.get_size();
		temp.position = temp.used - 1;
		for (int i = 0; i < (a.get_size() + b.get_size()); i++)
			temp.ary[i] = b.get_element(i - a.get_size());
		return temp;
	}
}

template <class ElementType>
ostream & operator<<(ostream & cout, const list<ElementType> & x)
{
	if (x.empty())
		cout << "\n\n+_+_+_+_+\n\n";
	else
	{
		int temp = x.get_position();
		for (int i = 0; i < x.get_size(); i++)
			cout << setw(5) << x.get_element(i);
		cout << endl;
	}
	return cout;
}

template <class ElementType>
bool operator==(const list<ElementType> & a, const list<ElementType><ElementType> & b)
{
	bool temp(true);
	if (a.get_size() != b.get_size())
		return temp = false;
	if (a.get_position() != b.get_position())
		return temp = false;
	while (temp == true)
	{
		for (int i = 0; i < a.get_size(); i++)
			if (a.get_element(i) != b.get_element(i))
				return false;
	}
	// Only if it has passed the above tests could it make it this far.
	return true;
}
