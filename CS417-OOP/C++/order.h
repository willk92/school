#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include "pizza.h"
#include "drinks.h"

using namespace std;

struct Order {
private:
  Pizza pizzas[10];
  Drinks drinks[20];
  map<string, float> souvenirs;
public:
  Order();
};