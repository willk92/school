/*
William Kelley
wkelley2@my.athens.edu
CS372-ASU
ID#: 70391
Week1-Rotate around an Axis
*/

#include <cmath>
#include <fstream>
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace std;

ifstream infile;
ofstream outfile;

class grid
{
private:
	double x, y, z;
public:
	grid();
	void grid_set(double a, double b, double c);
	int grid::grid_get_x();
	int grid::grid_get_y();
	int grid::grid_get_z();
	void grid::rotate_x(int degree);
	void grid::rotate_y(int degree);
	void grid::rotate_z(int degree);
	void display();
};
//Constructor
grid::grid() { x = y = z = 0; }
//Setter
void grid::grid_set(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
}
//Getters
int grid::grid_get_x()
{
	return x;
}

int grid::grid_get_y()
{
	return y;
}

int grid::grid_get_z()
{
	return z;
}
//Rotators
void grid::rotate_x(int degree)
{
	double nx, ny, nz;
	nx = x;
	ny = (y * cos(degree)) - (z * sin(degree));
	nz = (z * sin(degree)) + (y * cos(degree));
	x = nx, y = ny; z = nz;
}

void grid::rotate_y(int degree)
{
	double nx, ny, nz;
	nx = (x * cos(degree)) - (z * sin(degree));
	ny = y;
	nz = (z * sin(degree)) + (x * cos(degree));
	x = nx, y = ny; z = nz;
}

void grid::rotate_z(int degree)
{
	double nx, ny, nz;
	nx = (x * cos(degree)) - (y * sin(degree));
	ny = (x * sin(degree)) + (y * cos(degree));
	nz = z;
	x = nx, y = ny; z = nz;
}
//Display
void grid::display()
{
	outfile << "x:" << fixed << setprecision(2) << x << endl;
	outfile << "y:" << fixed << setprecision(2) << y << endl;
	outfile << "z:" << fixed << setprecision(2) << z << endl;
}

int main()
{
	outfile.open("gridrotation_results.txt");
	outfile << "gridrotation_results.txt\n";
	grid test;
	test.grid_set(2.5, 0, 2.0);
	outfile << "Initial Setup...\n";
	test.display();
	outfile << "X-Axis Roation...\n";
	test.rotate_x(84);
	test.display();
	outfile << "Y-Axis Rotation...\n";
	test.rotate_y(121);
	test.display();
	outfile << "Z-Axis Rotation...\n";
	test.rotate_z(360);
	test.display();
	outfile.close();

	return EXIT_SUCCESS;
}