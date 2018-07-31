//// CS 372               Week 5          Due: February 14, 2017
// Elizabeth Self       00067741          eself1@my.athens.edu
// ===========================================================
// Stack Circular Queue - STACK

#include <fstream>
#include <string.h>
#include "list.h"

using namespace std;
ofstream out;
ifstream file1, file2, file3, file4;
// ===========================================================
class Stack
{
private:
    List myS;
public:
    //void push(ElementType);
    //ElementType pop();
    //ElementType top() const;
    //bool full() const;
    //bool empty() const;
    //int size() const;
    //bool matching(ElementType, ElementType) const;
    //bool balanced(string boolexp);
    //void clear();
};
void Stack::push(ElementType elem)
{   myS.last();   myS.insertAfter(elem);   }
ElementType Stack::pop()
{
    ElementType t = top();
    myS.last();   myS.erase();
    return t;
}
ElementType Stack::top() const
{   return myS.getElement();   }
bool Stack::full() const
{   return myS.full();   }
bool Stack::empty() const
{   return myS.empty();   }
int Stack::size() const
{   return myS.size();   }
bool Stack::matching(ElementType t, ElementType c) const     // FOR CHARACTERS
{
    if(t == '(' && c == ')')
        return true;
    else if(t == '[' && c == ']')
        return true;
    else if(t == '{' && c == '}')
        return true;
    else if(t == '<' && c == '>')
        return true;
    else
        return false;
}
bool Stack::balanced(string exp)
{
    int i = 0;
    while(exp[i])
    {
        if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[' || exp[i] == '<')
            push(exp[i]);   // if starting bracket, push
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']' || exp[i] == '>')
        {   // if ending bracket, check to see if matching
            if(empty())
                return false;
            else if(!matching(pop(), exp[i]))
                return false;
        }
        i++;
    }
    if(empty())
        return true;
    else
        return false;
}
void Stack::clear()
{   myS.clear();   }
// ===========================================================
class Queue
{
private:
    List myQ;
public:
    void inqueue(ElementType);
    void dequeue();
    void dequeue(int);
    bool full() const;
    bool empty() const;
    int size() const;
    void print() const;
};
void Queue::inqueue(ElementType elem)
{   myQ.last();   myQ.insertAfter(elem);   }
void Queue::dequeue()
{   myQ.last();   myQ.erase();   }
void Queue::dequeue(int pos)
{   myQ.setPos(pos);   myQ.erase();   }
bool Queue::full() const
{   return myQ.full();   }
bool Queue::empty() const
{   return myQ.empty();   }
int Queue::size() const
{   return myQ.size();   }
void Queue::print() const
{   cout << myQ;   }
// ===========================================================
int main()
{
    file1.open("input.txt");
    file2.open("Stack3.dat");
    file3.open("LispClassData.txt");
    file4.open("LispClassData2.txt");

    Stack input;

    string mystring;
    while(getline(file1, mystring))
    {
        cout << mystring;
        if(input.balanced(mystring))
            {   cout << " - Balanced." << endl; input.clear();   }
        else
            {   cout << " - Mismatched." << endl; input.clear();   }
    }

    cout << endl << "Stack3.dat parsed results: ";
    while(getline(file2, mystring))
    {
        //cout << mystring << endl;
        input.balanced(mystring);
    }
    if(input.balanced(mystring))
        cout << "File Balanced." << endl;
    else
        cout << "File Mismatched." << endl;

    cout << endl << "LispClassData parsed results: " << endl;
    while(getline(file3, mystring))
    {
        if(mystring != "")
        {
            cout << mystring;
            if(input.balanced(mystring))
                {   cout << " - Balanced." << endl; input.clear();   }
            else
                {   cout << " - Mismatched." << endl; input.clear();   }
        }
    }

    cout << endl << "LispClassData2 parsed results: " << endl;
    while(getline(file4, mystring))
    {
        if(mystring != "")
        {
            cout << mystring;
            if(input.balanced(mystring))
                {   cout << " - Balanced." << endl; input.clear();   }
            else
                {   cout << " - Mismatched." << endl; input.clear();   }
        }
    }

    Queue suitors;
    char khar = 'A';
    for(int i = 0; i < 65; i++)
    {
        suitors.inqueue(khar);
        khar++;
    }
    int i = 3;
    while(suitors.size() > 1)
    {
        suitors.dequeue(i);
        i += 3;
        i = i % suitors.size();
    }
    cout << endl << endl << "Circular Queue -- Final suitor: ";
    suitors.print();

    return 0;
}
