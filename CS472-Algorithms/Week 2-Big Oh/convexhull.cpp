#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

std::ofstream outfile;
std::ifstream infile;

const int SIZE = 1000;

void seedRandomsFile();
void fillArray(int ary[][1000]);

int main() {
  int conv[SIZE][SIZE];

  seedRandomsFile();
  fillArray(conv);

  return 0;
}

void seedRandomsFile(){
  const int maximum_number = 0;
  const int minimum_number = 999;
  outfile.open("input.txt");
  for (int i = 0; i <= 505; i++)
  {
    int number1 = (rand() % (maximum_number + 1 - minimum_number)) - maximum_number;
    int number2 = (rand() % (maximum_number + 1 - minimum_number)) - maximum_number;
    outfile << number1 << " " << number2 << endl;
  }
  outfile.close();
}

void fillArray(int ary[][1000]){
  int x, y;
  infile.open("input.txt");
  while(infile >> x >> y){
    ary[x][y] = 1;
  }
}