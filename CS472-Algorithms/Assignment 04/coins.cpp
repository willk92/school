// Source: https://www.geeksforgeeks.org/coin-change-dp-7/

#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <fstream>

using namespace std;

int count( int S[], int size, int n )
{
    // If n is 0 then there is 1 solution
    // (do not include any coin)
    if (n == 0)
        return 1;

    // If n is less than 0 then no
    // solution exists
    if (n < 0)
        return 0;

    // If there are no coins and n
    // is greater than 0, then no
    // solution exist
    if (size <=0 && n >= 1)
        return 0;

    // count is sum of solutions (i)
    // including S[size-1] (ii) excluding S[size-1]
    return count( S, size - 1, n ) + count( S, size, n-S[size-1] );
}

int main()
{
  const int SIZE = 4;
  int num;
  int nums[SIZE] = {1, 3, 5, 9};

  cout << "Enter number desired to search number of solutions of(0 to exit): ";
  while(cin >> num && num != 0){
    cout << count(nums, SIZE, num) << endl;
    cout << "Enter number desired to search number of solutions of(0 to exit): ";
  }

  return 0;
}

/*
Williams-MacBook-Pro:Assignment 04 williamkelley$ ./coins
Enter number desired to search number of solutions of(0 to exit): 1
1
Enter number desired to search number of solutions of(0 to exit): 2
1
Enter number desired to search number of solutions of(0 to exit): 3
2
Enter number desired to search number of solutions of(0 to exit): 4
2
Enter number desired to search number of solutions of(0 to exit): 5
3
Enter number desired to search number of solutions of(0 to exit): 6
4
Enter number desired to search number of solutions of(0 to exit): 7
4
Enter number desired to search number of solutions of(0 to exit): 8
5
Enter number desired to search number of solutions of(0 to exit): 0
*/