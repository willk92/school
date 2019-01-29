#include <iostream>
#include <string>

using namespace std;

int main() {
  string s = "Hello world";
  cout << s << endl;
  s.substr(0, s.find(' '));
  cout << s.substr() << endl;
}