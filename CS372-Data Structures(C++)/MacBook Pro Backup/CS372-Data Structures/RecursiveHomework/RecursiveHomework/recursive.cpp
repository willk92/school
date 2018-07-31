;//
//  main.cpp
//  RecursiveHomework
//
//  Created by William Kelley on 3/2/17.
//  Copyright © 2017 William Kelley. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

unsigned digit_count(int);
void print_digits_reverse(int);
void reverseArray(int*, int, int);
void array_fill(int*, int, int);
void array_fill_rev(int*, int);
void array_print(int*, int);
int array_sum(int*, int, int);
int array_search(int*, int, int, int);
int GCD(int, int);
int hailstone(int, int);

const unsigned arraySize = 20;

//Global Arrays to work with
int a[arraySize];
int b[arraySize];
int c[arraySize];
int d[arraySize];

////////////////////////////////////////////////////
int main(int argc, const char * argv[])
{
    cout << "21) Digit Count: \n";
    cout << digit_count(536) << endl;
    cout << "23) Reverse Digits: \n";
    print_digits_reverse(3456);
    cout << endl;
    cout << "Array Fill(1-20): \n";
    array_fill(a, arraySize, 1);
    array_print(a, arraySize);
    cout << endl;
    cout << "27) Array Reverse(1-20): \n";
    reverseArray(a, 0 , arraySize);
    array_print(a, arraySize);
    cout << endl;
    cout <<"28) Sum Array(1-20): \n";
    cout << array_sum(a, 0, arraySize);
    cout << endl;
    cout << "29) Array Search(Target = 5): \n";
    cout << array_search(a, 0, arraySize, 5);
    cout << endl;
    cout << "33) Greatest Common Denominator for 1260 and 198: \n";
    cout << GCD(1260, 198);
    cout << endl;
    cout << "Hailstone(129030): \n";
    cout << hailstone(129030, 0);
    cout << endl;
    cout << "Hailstone(1579): \n";
    cout << hailstone(1579, 0);
    cout << endl;
    cout << "4) Array Fill(1-20): \n";
    array_fill(c, arraySize, 1);
    array_print(c, arraySize);
    cout << endl;
    cout << "5) Array Reverse Fill(20-1): \n";
    array_fill_rev(d, arraySize);
    array_print(d, arraySize);
    cout << endl;
    
    return 0;
}
////////////////////////////////////////////////////

//Number 21
unsigned digit_count(int x)
{
    if (x < 0)
        return digit_count(-x);
    else if (x < 10)
        return 1;
    else
        return 1 + digit_count(x/10);
}
//Number 23
void print_digits_reverse(int x)
{
    if(x == 0)
        return;
    else
        cout << x%10;
        return print_digits_reverse(x/10);
}
//Number 27
void reverseArray(int *a, int first, int last)
{
    int temp;
    if (first == last)
        return;
    else
    {
        temp = a[first];
        a[first] = a[last-1];
        a[last-1] = temp;
        reverseArray(a, ++first, --last);
        return;
    }
}
//Number 28
int array_sum(int *a, int sum, int size)
{
    if (size <= 0)
        return sum;
    else
    {
        sum = sum + *a;
        return array_sum(++a, sum, --size);
    }
}
//Number 29
int array_search(int *a, int first, int last, int target)
{
    if (last == 0 && (a[first] != target))
        return 0;
    else if (last == 0 && (a[first] == target))
        return a[first];
    else
    {
        if (a[first] == target)
            return first;
        else
            return array_search(a, ++first, --last, target);
    }
}
//Number 33
int GCD(int a, int b)
{
    if(a%b == 0)
        return b;
    else
    {
        int x;
        x = a % b;
        return GCD(b, x);
    }
}
//Hailstone
int hailstone(int n, int counter)
{
    if (n == 1)
        return counter;
    else if (n%2 == 0)
        return hailstone((n/2), ++counter);
    else
        return hailstone((n*3)+1, ++counter);
}
//Array Fill
void array_fill(int *a, int size, int start_with_one)
{
    if(size<= 0)
        return;
    else
    {
        *a = start_with_one;
        array_fill(++a, (size-1), (++start_with_one));
        return;
    }
}
//Reverse Array Fill
void array_fill_rev(int *a, int size)
{
    if (size <= 0)
        return;
    else
    {
        *a = size;
        array_fill_rev(++a, (size-1));
        return;
    }
}
//Array Print
void array_print(int *a, int size)
{
    if (size <= 0)
        return;
    else
    {
        cout << *a << "||";
        array_print(++a, --size);
        return;
    }
}
//Reverse Linked List Print
//FUNCTION ONLY, WILL PRINT WITH DIFFERENT MAIN AND STAPLE RESULT WITH THE REST
//void rev_linked_list_print(/*struct* c*/)
//{
//   if(*c = NULL)
//        return;
//    else
//    {
//        rev_linked_list_print(c->linky)
//        cout << c->value << "|";
//        return;
//   }
//}
