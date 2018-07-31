//General List (Header)

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 65;

template<typename ElementType>
class list
{
  private:
    ElementType ary[SIZE];
    int used;
    int position;

  public:
    list()
    {
	used = 0;
	position = 0;
    }

    list(const list<ElementType> &a)
    {
	used = a.used;
	position = a.position;
    }

    bool empty() const
    {
	if (used == 0)
	    return true;
	else
	    return false;
    }

    bool full() const
    {
	if (used == SIZE)
	    return true;
	else
	    return false;
    }

    void first();
    {
	position = 0;
    }
    void last();
    {
	position = used - 1;
    }
    void prev();
    {
	position--;
    }
    void next();
    {
	position++;
    }
    int get_position() const;
    {
	return position;
    }
    void set_position(int a);
    {
	position = a;
    }
    void insert_before(ElementType a)
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
    void insert_after(ElementType a)
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
    ElementType get_element() const
    {
	if (used > 0)
	    return ary[position];
	else
	    return -1;
    }
    ElementType get_element(int pos) const
    {
	if (used > 0)
	    return ary[pos];
	else
	    return -1;
    }
    int get_size() const
    {
	return used;
    }
    void replace(ElementType a)
    {
	ary[position] = a;
    }
    void erase()
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
    void clear()
    {
	for (int i = 0; i < SIZE; i++)
	    ary[i] = NULL;
	position = 0;
	used = 0;
    }
    bool reverse()
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
    void operator=(const list<ElementType> &a);
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
    friend list operator+(const list<ElementType> &a, const list<ElementType> &b);
    {
	if ((a.get_size() + b.get_size()) > SIZE)
	{
	    cout << "Size of both lists exceed single list capacity...\n";
	    list temp;
	}
	else
	{
	    list temp(a);
	    temp.used = a.get_size() + b.get_size();
	    temp.position = temp.used - 1;
	    for (int i = 0; i < (a.get_size() + b.get_size()); i++)
		temp.ary[i] = b.get_element(i - a.get_size());
	    return temp;
	}
    }
};

ostream &operator<<(ostream &cout, const list<ElementType> &x)
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
bool operator==(const list<ElementType> &a, const list<ElementType> &b)
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