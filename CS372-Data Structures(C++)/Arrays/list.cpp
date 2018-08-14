// Elizabeth Self
// FILE: list.cpp

#include "list.h"
using namespace std;
// ===========================================================
List::List()                              // default constructor
{
    used = pos = 0;
    for(int i = 0; i < CAPACITY; i++)
        ary[i] = 0;
}
List::List(const List &orig)     // copy constructor
{
    used = pos = 0;
    for(int i = 0; i < CAPACITY; i++)
        ary[i] = 0;
    if(orig.size() > 0)
    {
        used = orig.size();
        pos = orig.getPos();
        for(int i = 0; i < used; i++)
        {
            ary[i] = orig.getElement(i);
        }
        return;
    }
    else
    {
        cout << "Empty list, unable to copy." << endl;
        return;
    }
}
bool List::empty() const // if used = 0, returns true
{   return !used;   }
bool List::full() const
{
    if(used == CAPACITY)
        return true;
    else
        return false;
}
void List::first()
{   pos = 0;   }
void List::last()
{
    if(used > 0)
        pos = used - 1;
    return;
}
void List::prev()
{
    if(pos > 0)
        pos--;
}
void List::next()
{
    if(pos < used - 1)
        pos++;
    /*else if(used > 0)
        pos = used - 1;*/
    return;
}
int List::getPos() const
{   return pos;   }
void List::setPos(int num)
{
    if(num < used && num > -1)
        pos = num;
    return;
}
void List::insertBefore(ElementType elem)
{
    if(used == 0)
    {
        ary[0] = elem;
        used++;
        return;
    }
    else if(used < CAPACITY)
    {
        ElementType cpy1 = ary[pos], cpy2 = ary[pos+1];
        for(int i = pos; i < used; i++)
        {
            ary[i+1] = cpy1;
            cpy1 = cpy2;
            cpy2 = ary[i+2];
        }
        ary[pos] = elem;
        used++;
        return;
    }
    else
    {
        cout << "List is full." << endl;
        return;
    }
}
void List::insertAfter(ElementType elem)
{
    if(used == 0)
    {
        ary[0] = elem;
        used++;
        return;
    }
    else if(used < CAPACITY)
    {
        pos++;
        ElementType cpy1 = ary[pos], cpy2 = ary[pos+1];
        for(int i = pos; i < used; i++)
        {
            ary[i+1] = cpy1;
            cpy1 = cpy2;
            cpy2 = ary[i+2];
        }
        ary[pos] = elem;
        used++;
        return;
    }
    else
    {
        cout << "List is full." << endl;
        return;
    }
}
ElementType List::getElement() const
{
    if(used > 0)
        return ary[pos];
    else
    {
        cout << "Empty List." << endl;
        return -1;
    }
}
ElementType List::getElement(int get) const
{
    if(get < used && get >= 0)
        return ary[get];
    else
    {
        cout << "Invalid position get." << endl;
        return -1;
    }
}
int List::size() const
{   return used;   }
void List::replace(ElementType elem)
{
    if(used > 0)
    {
        ary[pos] = elem;
        return;
    }
    else
    {
        cout << "Empty list, unable to replace element." << endl;
        return;
    }
}
void List::erase()
{
    if(used > 0)
    {
        for(int i = pos; i < used; i++)
        {
            ary[i] = ary[i+1];
        }
        used--;
        if(pos == used && pos > 0)
            pos--;
        ary[used] = 0;
    }
    else
    {
        cout << "Empty list, nothing to erase." << endl;
        return;
    }
}
void List::clear()
{
    for(int i = 0; i < CAPACITY; i++)
        ary[i] = 0;
    used = pos = 0;
}
void List::reverse()
{
    if(used > 0)
    {
        ElementType temp[CAPACITY];
        for(int i = 0; i < used; i++)
        {
            temp[used-1-i] = ary[i];
        }
        for(int i = 0; i < used; i++)
        {
            ary[i] = temp[i];
        }
    }
    else
    {
        cout << "Empty list; nothing to reverse." << endl;
        return;
    }
}
ostream &operator << (ostream &out, const List &data)
{
    if(data.empty())
    {
        //out << "Empty list, nothing to print." << endl;
    }
    else
    {
        int temp = data.getPos();
        for(int i = 0; i < data.size(); i++)
        {
            out << setw(3) << data.getElement(i);
        }
        out << endl;
    }
    return out;
}
bool operator == (const List &one, const List &two)
{
    if(one.size() == two.size() && one.getPos() == two.getPos())
    {
        for(int i = 0; i < one.size(); i++)
        {
            if(one.getElement(i) != two.getElement(i))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
void List::operator = (const List &orig)
{
    if(orig.empty())
        return;
    used = orig.size();
    pos = orig.getPos();
    for(int i = 0; i < orig.size(); i++)
    {
        ary[i] = orig.getElement(i);
    }
    return;
}
List operator + (const List &one, const List &two)
{   // friend
    if(one.size() + two.size() > CAPACITY)
    {
        cout << "Exceeded list capacity; unable to add lists." << endl;
        List temp;
        return temp;
    }
    else
    {
        List temp(one);
        for(int i = one.size(); i < (one.size()+two.size()); i++)
        {
            temp.ary[i] = two.getElement(i-one.size());
        }
        temp.used = one.size() + two.size();
        temp.pos = temp.used - 1;
        return temp;
    }
}
// ===========================================================
