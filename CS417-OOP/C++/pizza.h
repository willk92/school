#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

struct Pizza {
  // toppings: do with map, map each topping to it's price
  // - build a linked list of the toppings.
  // pizza type
  // figure out how to keep track of toppings being used and their prices
private:
  map<string, float> toppings;
  // Standard Pizza
  const static float std_reg = 7.99;
  // Specialty Pizzas
  float Margherita = 7.99;
  float Hawaiian = 8.99;
  float Meats = 9.99;
  // Upsize and Downsize Pricing for Pizzas
  float downsize = -3.99;
  float upsize = 5.99;

public:
  Pizza();
};

Pizza::Pizza()
{
  toppings.insert(pair<string, float>("chesse", 0.75));
  toppings.insert(pair<string, float>("ham", 0.99));
  toppings.insert(pair<string, float>("pepperoni", 0.99));
  toppings.insert(pair<string, float>("green pepper", 0.89));
  toppings.insert(pair<string, float>("onions", 0.89));
  toppings.insert(pair<string, float>("mushrooms", 0.89));
  toppings.insert(pair<string, float>("pineapple", 0.99));
}