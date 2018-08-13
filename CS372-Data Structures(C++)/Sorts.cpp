#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void swap_elements(int *ary, int a, int b);
int split(int *ary, int left, int right);
void quick_sort(int *ary, int left, int right);
int interpolation_search(int *ary, int target, int size);

int main()
{
	int test[] = { 55, 12, 54, 22, 65, 89, 12, 45, 11, 34, 5, 18 };
	int array_size = (sizeof(test) / sizeof(test[0]));
	quick_sort(test, 0, array_size - 1);
	int val = interpolation_search(test, 65, array_size);
	cout << "pos in test = " << val << endl;
	for (int i = 0; i < array_size; i++)
	{
		cout << test[i] << endl;
	}
}

void swap_elements(int *ary, int a, int b)
{
	int temp = ary[a];
	ary[a] = ary[b];
	ary[b] = temp;
}

int split(int *ary, const int left, const int right)
{
	int mid = ((left + (right - left)) / 2);
	int pivot = ary[mid];
	swap_elements(ary, mid, left);
	int a = left + 1;
	int b = right;
	
	while (a <= b)
	{
		while (a <= b && ary[a] <= pivot)
			a++;

		while (a <= b && ary[b] > pivot)
			b--;

		if (a < b)
			swap_elements(ary, a, b);
	}
	swap_elements(ary, a - 1, left);
	return a - 1;
}

void quick_sort(int *ary, const int left, const int right)
{
	if (left >= right)
		return;

	int s = split(ary, left, right);
	//cout << "QS:" << left << "|" << right << "| split: " << s << endl;

	quick_sort(ary, left, s - 1);
	quick_sort(ary, s + 1, right);
}

int interpolation_search(int *ary, int target, int size)
{
	int low = 0;
	int mid = NULL;
	int high = size - 1;

	while (ary[low] <= target && ary[high] >= target)
	{
		mid = low + ((target - ary[low]) * (high - low)) / (ary[high] - ary[low]);
		if (ary[mid] < target)
		{
			low = mid + 1;
		}
		else if (ary[mid] > target)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}

	if (ary[low] == target)
	{
		return low;
	}
	else
	{
		return -1;
	}
}