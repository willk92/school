#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> parseCommandLine(string aCommandLine);
void printVector(vector<string> const &input);

struct arguments{
  int argc;
  char **argv;
};

int main(){
  vector<string> Parsed;
  string test = "cd < /Documents/GitHub/school/";
  Parsed = parseCommandLine(test);

  arguments tests;
  tests.argc = Parsed.size();
  cout << tests.argc << endl;
}

vector<string> parseCommandLine(string aCommandLine) {
  vector<string> parsed;

  string build;

  for (int pos = 0; pos <= aCommandLine.size(); ++pos) {
    if(aCommandLine[pos] == '|'){
      parsed.push_back(build);
      parsed.push_back("|");
      ++pos;
      build.clear();
    }
    else if(aCommandLine[pos] == '>'){
      parsed.push_back(build);
      parsed.push_back(">");
      ++pos;
      build.clear();
    }
    else if(aCommandLine[pos] == '<' && aCommandLine[pos+1] != '<'){
      parsed.push_back(build);
      parsed.push_back("<");
      ++pos;
      build.clear();
    }
    else if(aCommandLine[pos] == '<' && aCommandLine[pos+1] == '<')
    {
      parsed.push_back(build);
      parsed.push_back("<<");
      pos += 2;
      build.clear();
    }
    else if(aCommandLine[pos] == '\0'){
      parsed.push_back(build);
    }
    else {
      build += aCommandLine[pos];
    }
  }
  return parsed;
}

void printVector(vector<string> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		cout << input.at(i) << endl;
	}
}