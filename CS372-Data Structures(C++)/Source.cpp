#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
ofstream out;
int j = 0;
void qsort(int ary[], int sz);
void partition(int ary[], int n, int & pindex);
void print(int ary[], int n);
void genrand(int n, int ary []);
int interpolation(int ary[], int val, int sz);

int main()
{
	out.open("results2.txt");
	const int sz = 15000;
	int ary[sz]; 
	genrand(sz, ary); 
	qsort(ary, sz);
	srand((unsigned)time(0));
	int v, w=0, x;
	for (int i = 0; i < 5000; i++)
	{
		 v = rand() % sz;
		 x = ary[v];
		 w += interpolation(ary, x, sz);
	}
	out << "The avg number of probes is " << (float)w / 5000;

	
	//print(ary, sz);

	//out << endl << "The position of "<<ary[v]<<" in the array is " << w << "." << endl;
	


	out.close();
	return 0;
}

void qsort(int ary[], int n)
{
	int pindex, n1, n2;
	if (n > 1)
	{
		partition(ary, n, pindex);
		n1 = pindex;
		n2 = n - n1 - 1;
		qsort(ary, n1);
		qsort((ary + pindex + 1), n2);
	}

}

void partition(int ary[], int n, int & pindex)
{
	
	int pivot = ary[n/2];
	ary[n / 2] = ary[0];
	ary[0] = pivot;
	int tobig = 1, tosmall=n-1;

	while (tobig <= tosmall)
	{
		while (tobig < n&&ary[tobig] <= pivot)
		{
			tobig++;
		}
		while (ary[tosmall] > pivot)
		{
			tosmall--;
		}
		if (tobig < tosmall)
		{
			int tp;
			tp = ary[tobig];
			ary[tobig] = ary[tosmall];
			ary[tosmall] = tp;
		}

	}
	pindex = tosmall;
	ary[0] = ary[pindex];
	ary[pindex] = pivot;

}

void print(int ary[], int n)
{
	for (int i = 0; i < n; i++)
	{
		out << ary[i] << "  ";
		if (i % 10 == 0)
		{
			out << endl;
		}
	}
}

void genrand(int n,int ary[])
{
	srand((unsigned)time(0));
	signed int x= 32;
	for (int i = 0; i < n; i++)
	{
		ary[i] = rand();
	}
}

int interpolation(int ary[], int val, int sz)
{
	int l = 0, m, h=sz-1, probe=0;
	
	while (ary[h]!=ary[l]&&ary[l] <= val&&ary[h] >= val)
	{
		m = ceil((((val - ary[l])*(h - l)) / (ary[h] - ary[l])) + l);
		probe += 1;
		if (ary[m] < val)
		{
			l = m + 1;
		}
		else if (val < ary[m])
		{
			h = m - 1;
		}
		else 
		{
			return probe;
		}
		
	}
	if (ary[l] == val)
	{
		return probe;
	}
	else
	{
		out << " oops " << j++ << endl;
		return 0;
	}
}
