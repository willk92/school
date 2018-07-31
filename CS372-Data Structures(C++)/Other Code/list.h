// Elizabeth Self
// FILE: List.h

#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <iomanip>

using namespace std;

typedef char ElementType;
const int CAPACITY = 65;

class List
{
private:
    //static const int CAPACITY = 20;     // array size
    ElementType ary[CAPACITY];          // array size 20 for ElementType type
    int used, pos;
public:
    List();
    List(const List &orig);     // copy constructor
    bool empty() const;                // if used = 0, returns true
    bool full() const;
    void first();                // add check
    void last();
    void prev();
    void next();
    int getPos() const;
    void setPos(int num);
    void insertBefore(ElementType elem);
    void insertAfter(ElementType elem);
    ElementType getElement() const;
    ElementType getElement(int get) const;
    int size() const;
    void replace(ElementType elem);
    void erase();
    void clear();
    void reverse();
    void operator = (const List &orig);
    friend List operator + (const List &one, const List &two);
};

ostream &operator << (ostream &out, const List &data);
bool operator == (const List &one, const List &two);

#endif
