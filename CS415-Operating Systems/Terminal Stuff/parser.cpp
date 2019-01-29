#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function prototypes

vector<string> parseCommandLine(string);
void printVector(vector<string> const &input);

// Run functions for program

int main() {
  string parseMe = "asf, hhbb > iijjkk < asbbbbb*&*()(*<<burlktjy asdfalsdj nnb   asdf | asbbbbbbbz";

  printVector(parseCommandLine(parseMe));
}

// Parsing string
vector<string> parseCommandLine(string aCommandLine) {
  vector<string> parsed;

  string build;

  for (int pos = 0; pos < aCommandLine.size(); ++pos) {
    if(aCommandLine[pos] == '|'){
      parsed.push_back(build);
      ++pos;
      build.clear();
    }
    else if(aCommandLine[pos] == '>'){
      parsed.push_back(build);
      ++pos;
      build.clear();
    }
    else if(aCommandLine[pos] == '<'){
      parsed.push_back(build);
      ++pos;
      build.clear();
    }
    else if(aCommandLine[pos] == '<' && aCommandLine[pos+1] == '<')
    {
      parsed.push_back(build);
      pos += 2;
      build.clear();
    }
    else {
      build += aCommandLine[pos];
    }
  }
  return parsed;
}

//Just to print out the vector to show it's working
void printVector(vector<string> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		cout << input.at(i) << endl;
	}
}