/*
William Kelley
CS372 - Data Structures
Interpolation Search
Quick Sort
2017/04/16
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void swap_elements(int *ary, int a, int b);
void quick_sort(int *ary, int left, int right);

int main()
{
    const int array_size = 12;
    int test[array_size] = { 55, 12, 54, 22, 65, 89, 12, 45, 11, 34, 5, 18 };
    quick_sort(test, array_size - 1, array_size);
    for (int i = 0; i < array_size; i++)
    {
        cout << *test << endl;
        test++;
    }
}

void swap_elements(int *ary, int a, int b);
{
    int temp = ary[a];
    ary[a] = ary[b];
    ary[b] = temp;
}

void quick_sort(int *ary, int left, int right);
{
    cout << "QuickSort indexes:" << left << "|" << right << endl;
    int a = left;
    int b = right;
    int mid = (left + (right - left)) / 2;
    int pivot = ary[mid];

    while (left < b || a < right)
    {
        while(ary[a] < pivot)
            a++;
        while(ary[b] > pivot)
            b++

        if( a <= b)
        {
            swap(ary, a, b);
            a++;
            b--;
        }
        else
        {
            if(left < b)
                quick_sort(ary, left, b);
            if(right > a)
                quick_sort(ary, a, right);
            return;
        }
    }
}