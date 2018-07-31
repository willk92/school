/*
 William Kelley
 wkelley2@my.athens.edu
 CS372 - Rational Class Assignment
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

ofstream outfile;
ifstream infile;

int access;

struct node
{
    string a;
    node *next;
};

node *head;

node *myNewNode()
{
    node *tp;
    tp->a = "";
    tp->next = NULL;
    return tp;
}

void insert(string x, int buffer_size, int &access)
{
    node *c, *p, *t;
    int counter = 1;
    if (head == NULL)
    {
        head = myNewNode();
        head->a = x;
        access++;
    }
    else
    {
        c = head;
        p = NULL;
        while (c != NULL && c->a != x)
        {
            p = c;
            c = c->next;
            counter++;
            if(counter == buffer_size)
                p->next = NULL;
        }
        if(c && c->a == x)
        {
            if(c != head)
            {
                if(p)
                    p->next = c->next;
                c->next = head;
                head = c;
            }
        }
        else
        {
            t = myNewNode();
            t->a = x;
            t->next = head;
            head = t;
            access++;
        }
    }
    return;
}

void print_list()
{
    node *c;
    c = head;
    while (c != NULL)
    {
        cout << c->a << "|";
        c = c->next;
    }
    return;
}
void run_buffer(int buffer_size)
{
    string target;
    head = NULL;
    access = 0;
    infile.open("LinkL Var Stream.txt");
    infile >> target;
    while(infile >> target)
    {
        cout << target << endl;
        insert(target, buffer_size, access);
    }
    infile.close();
    outfile.open("HereIam.txt");
    outfile << "HereIam.txt" << endl;
    outfile.close();
}

int main()
{
    run_buffer(4);
    print_list();
    infile.open("LinkL Var Stream.txt");
    string x;
    while(infile>>x)
        cout << x << endl;
    infile.close();
    return 0;
}
