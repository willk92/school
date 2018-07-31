// CS 372               Week 6          Due: February 21, 2017
// Elizabeth Self       00067741          eself1@my.athens.edu
// ===========================================================
// Locality of Reference

#include <iostream>
#include <fstream>

using namespace std;
ifstream in;
ofstream out;
// ===========================================================
struct LList
{
    string var;
    LList *linky;
};
typedef LList * Node;
Node head;
LList * newnode()
{
    LList *t;
    t = new LList();
    t->var = "";
    t->linky = NULL;
    return t;
}
void insertvar(string name, int LIMIT, int &READS)
{
    Node c, p, t;
    int cnt = 1;
    if(head == NULL)
    {                       // establish head if not there
        head = newnode();
        head->var = name;
        READS++;
    }
    else
    {
        c = head;
        p = NULL;
        while(c != NULL && c->var != name)
        {
            p = c;
            c = c->linky;
            cnt++;
            if(cnt == LIMIT)
                p->linky = NULL;
        }
        if(c && c->var == name)
        {
            if(c != head)
            {
                if(p)
                    p->linky = c->linky;
                c->linky = head;
                head = c;
            }
        }
        else
        {
            t = newnode();
            t->var = name;
            t->linky = head;
            head = t;
            READS++;
        }
    }
    return;
}
void printList()
{
    Node c;
    c = head;
    while (c)      // stops when c is null (not pointing to anything)
    {
        out << c->var << "   ";
        c = c->linky;   // sends c to next node
    }
    return;
}
void testbuffer(int buffer)
{
    string temp;
    int reads = 0;
    head = NULL;
    in.open("LinkL Var Stream.txt");
    while(in >> temp)
    {   insertvar(temp, buffer, reads);     }
    out << "Buffer size = " << buffer << endl << "# of Mem Accesses = " << reads << endl;
    printList();
    out << endl;
    in.close();
}
// ===========================================================
int main()
{
    out.open("Week 6 - Locality of Reference RESULTS.txt");
    testbuffer(4);
    testbuffer(5);
    testbuffer(6);
    testbuffer(7);
    testbuffer(8);
    out.close();
    return 0;
}
