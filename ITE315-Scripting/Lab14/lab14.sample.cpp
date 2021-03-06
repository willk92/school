//
// File: lab12.sample.cpp
// Author: wkelley2@my.athens.edu
// Purpose:
// Experiment with variables in C++
//
#include <iostream>
using namespace std;
const double PI = 3.14159267;
int main()
{
  double radius = 0;
  cout << "Enter a radius: " << endl;
  cin >> radius;
  double area = 2 * PI * radius * radius;
  double circumference = 2 * PI * radius;
  cout << "Radius: " << radius;
  cout << "Circumference: " << circumference;
  cout << "Area: " << area << endl;
  return 0;
}
