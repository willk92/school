/*
William Kelley
wkelley2@my.athens.edu
StId: 70391
MultiLinkedList.cpp
*/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

ifstream infile;
ofstream outfile;

void table_print(float *array, float size)
{
	for (int i = 0; i < size; i++)
	{
		outfile << *array << " ";
		array++;
	}
	outfile << endl;
}

void table_add1(float *array, float size)
{
	for (int i = 0; i < size; i++)
	{
		*array += 1;
		array++;
	}
}

void table_fill(float *array, float size, float num)
{
	for (int i = 0; i < size; i++)
	{					//(first array value is the address value of the arrays first location in memory)
		*array = num;	//pointing to the memory address of array and inserting 20.
		array++;		//incrementing array by 1 memory location of its data type
	}
}

void table_print_rev(float *array, float size)
{
	const int s = size;
	array = array + (s - 1);			//(size - 1) because array's address is already at [0]
	for (int i = 0; i < size; i++)		//if you add 20 to address 0, you arrive at [20] which isn't
	{									//part of the array
		outfile << *array << " ";
		array--;
	}
	outfile << endl;
}

void table_copy(float *array2, float *array1, float size)
{
	for (int i = 0; i < size; i++)
		*array2 = *array1; array1++; array2++;
}

float table_sum(float *array, float size)
{
	float sum = 0.0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + *array;
		array++;
	}
	return sum;
}

float table_max(float *array, float size)
{
	float largest = *array;
	for (int i = 0; i < size; i++)
	{
		if (*array > largest)
			largest = *array;
		array++;
	}
	return largest;
}
float table_min(float *array, float size)
{
	float smallest = *array;
	for (int i = 0; i < size; i++)
	{
		if (*array < smallest)
			smallest = *array;
		array++;
	}
	return smallest;
}

float table_avg(float *array, float size)
{
	float avg = 0;
	for (int i = 0; i < size; i++)
	{
		avg = *array + avg;
		array++;
	}
	avg = avg / size;
	return avg;
}

float* table_contain(float *array, float size, float val)
{
	for (int i = 0; i < size; i++)
	{
		if (*array == val)
			return array;
		else
			return NULL;
	}
}


int main()
{
	//You're assignment requested floats, so I changed the arrays to floats to correspond.
	const int Max = 20;
	float ary[Max];// ............  replace these two statements with dynamically allocated arrays.
	float bry[Max];
	float *p, *s, *tp;
	float avgValue, cnt;

	p = &ary[0];// ............   change &ary[0] to above used stements.
	s = &bry[0];// ............   change &bry[0] to above used stements.

	table_fill(p, Max, 10);
	cout << endl << "Fill array with 10 " << endl;
	table_print(p, Max);  cout << endl << endl;


	cout << endl << "Add 1 to first 10 elements " << endl;
	table_add1(p, 10);
	table_print(p, Max);  cout << endl << endl;

	tp = s;   // save pointer
	for (int i = 1; i <= Max; i++)
	{
		table_fill(s, 1, i);
		s++;
	}
	cout << endl << "Fill array with 1 to 20 " << endl;
	s = tp;   // restore pointer
	table_print(s, Max);  cout << endl << endl;

	cout << endl << "Print reverse order " << endl;
	table_print_rev(s, Max);  cout << endl << endl;

	table_fill(p, Max, 0);
	cout << endl << "Zero out array " << endl;
	table_print(p, Max);  cout << endl << endl;

	s = p;        // What's happening here?
	for (int i = Max; i >= 0; i--)
	{
		table_add1(p, i);
		p++;
	}
	p = s;  //restore p and s
	s = tp;
	cout << endl << "Fill array with ???? " << endl;
	table_print(p, Max);  cout << endl << endl;

	cout << endl << "Print reverse order " << endl;
	table_print_rev(p, Max);  cout << endl << endl;

	cout << endl << "Copy p to s and print p and s" << endl;
	table_copy(s, p, Max);
	table_print(p, Max);  cout << endl << endl;
	table_print(s, Max);  cout << endl << endl;

	for (int i = 0; i<Max / 2 + 1; i++)
	{
		s = p + 10 + i;
		table_fill(s, 1, i * 2);
		s = p + 10 - i;
		table_fill(s, 1, i * 3);
	}
	s = tp;
	cout << endl << "Fill array with <-> " << endl;
	table_print(s, Max);  cout << endl << endl;

	cout << endl << "Min for previous table " << table_min(s, 15);
	cout << endl << "Max for previous table " << table_max(s + 10, 9);
	cout << endl << "Sum for previous table " << table_sum(s + 5, 12);
	cout << endl << "Average for previous table " << table_avg(s + 5, 12);

	avgValue = table_avg(s, Max);
	for (int i = 1; i <= Max; i++)
	{
		if (table_contain(s, 1, avgValue)!=NULL)
		{
			cnt++;
		}
		s++;
	};
	cout << endl << "How many array values are equal to the average?" << endl;
	//cout << "         cnt = " << cnt << endl << endl;

	//cout << "Values smaller than average: " << table_contain(s, Max, table_avg(s, Max));

	//..........You add code here for the two other tasks I have in the specs

	//system("pause");    // code for VS only. * For some reason I still don't need this for VS
	return 0;
}
