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

class rat
{
public:
    rat();
    rat(int a, int b);
    void clear_out();
    int get_n();
    int get_d();
    void set_n(int a);
    void set_d(int a);
    friend ostream &operator<<(ostream&, rat &r);
    rat operator+(const rat &r);
    rat operator-(rat &r);
    rat operator*(rat &r);
    rat operator/(rat &r);
    rat operator!=(rat &r);
    rat operator==(rat &r);
    
private:
    int n;
    int d;
};

rat::rat()
{
    n = d = 0;
}

rat::rat(int a, int b)
{
    n = a;                           //a is numerator
    d = b;                           //b is numerator
}

void rat::clear_out()
{
    n = d = 0;
}

int rat::get_n()
{
    return n;
}

int rat::get_d()
{
    return d;
}

void rat::set_n(int a)
{
    n = a;
}

void rat::set_d(int a)
{
    d = a;
}

ostream &operator<<(ostream& cout, rat &r)
{
    cout << r.n  << "/" << r.d << endl;
    return cout;
}

rat rat::operator+(const rat &r)
{
    rat q;
    q.n = (((*this).n*r.d) + (r.n*(*this).d));
    q.d = (((*this).d*r.d) + (r.d*(*this).d));
    return q;
}
rat rat::operator-(rat &r)
{
    rat q;
    int tn, td;
    tn = ((r.get_n()*(*this).get_d()) - ((*this).get_n()*r.get_d()));
    td = ((r.get_d()*(*this).get_d()) - ((*this).get_d()*r.get_d()));
    q.set_n(tn);
    q.set_d(td);
    return q;
}
rat rat::operator*(rat &r)
{
    rat q;
    int tn, td;
    tn = r.get_n()*(*this).get_n();
    td = r.get_d()*(*this).get_d();
    q.set_d(td);
    q.set_n(tn);
    return q;
}
rat rat::operator/(rat &r)
{
    rat q;
    q.n = r.n*(*this).d;
    q.d = r.d*(*this).n;
    return q;
}
