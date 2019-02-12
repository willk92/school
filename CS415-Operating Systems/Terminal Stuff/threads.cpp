#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void fillWithRandoms(int *dataset1, int *dataset2, int size);
void averageArrays(int *dataset1, int *dataset2, int *resultset, int size);
void arrayAverage(int *dataset1, int *dataset2, int *resultset, int size);
void singleThreadAverage(int *dataset1, int *dataset2, int *resultset, int size);
void buildRange(int *ranges);

const int SIZE = 10000000;

int main(){
  int *ary = new int[SIZE];
  int *bry = new int[SIZE];
  int *results = new int[2];

  fillWithRandoms(ary, bry, SIZE);
  arrayAverage(ary, bry, results, SIZE);

  cout << results[0] / SIZE << endl << results[1]/SIZE << endl;

  singleThreadAverage(ary, bry, results, SIZE);



  return 0;
}

void fillWithRandoms(int *dataset1, int *dataset2, int size){
  int i = 0;
  while (i < size){
    *dataset1 = rand() % 31;
    *dataset2 = rand() % 65;
    ++dataset1;
    ++dataset2;
    ++i;
  }
}

void averageArrays(int *dataset1, int *dataset2, int *resultset, int size){
  int base = 0;
  if (size == (SIZE * (1.0 / 8.0)))
  {
    base = size - (SIZE * (1.0 / 8.0));
  }
  else {
    base = size - (SIZE * (1.0 / 8.0)) + 1;
  }
  while (base < size || base != SIZE){
     resultset[0] += dataset1[base];
     resultset[1] += dataset2[base];
     ++base;
  }
}

void arrayAverage(int *dataset1, int *dataset2, int *resultset, int size){
  auto start = high_resolution_clock::now();  //for determining length of time taken to run
  int i = (size * (1.0 / 8.0));
  int holder = i;
  const int num_threads = 8;
  thread t[num_threads];
  for (int i = 0; i < num_threads; ++i)
  {
    t[i] = thread(averageArrays, dataset1, dataset2, resultset, holder);
    holder += i;
  }

  for (int i = 0; i < num_threads; ++i){
    t[i].join();
  }

  auto stop = high_resolution_clock::now(); //for determining length of time taken to run
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Time to run threads: " << duration.count() << " microseconds" << endl;
}

void singleThreadAverage(int *dataset1, int *dataset2, int *resultset, int size){
  auto start = high_resolution_clock::now();

  thread th1 = thread(averageArrays, dataset1, dataset2, resultset, size);
  th1.join();

  auto stop = high_resolution_clock::now(); //for determining length of time taken to run
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Time to run single threaded: " << duration.count() << " microseconds" << endl;
}

/*
Time to run threads: 524123 microseconds
15
60
Time to run single threaded: 3714 microseconds
*/