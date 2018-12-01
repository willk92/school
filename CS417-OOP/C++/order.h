#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <list>
#include "pizza.h"
#include "drinks.h"

using namespace std;

struct Order {
private:
  list<Pizza> pizzas;
  list<Drinks> drinks;
  list<string> items;
  map<string, float> souvenirs;
  float orderPrice;

public:
  Order();
  void add_toppings();
  void add_specialty_pizza(string pizzaName, string size);
  void add_souvenirs(string souvenirName)
};

Order::Order()
{
  souvenirs.insert(pair<string, float>("shirt", 21.99));
  souvenirs.insert(pair<string, float>("mug", 4.99));

  orderPrice = 0.00;
}

void Order::add_specialty_pizza(string pizzaName, string size)
{
  Pizza p;
  p.set_pizza_type(pizzaName);
  p.set_pizza_size(size);
  // Not a custom pizza, therefore no customizations accepted
  if(pizzaName != "Custom" || pizzaName != "custom")
  {
    pizzas.push_back(p);
  }
  // Pizza is a custom, therefore we need to accept customizations
  else if(pizzaName == "Custom" || pizzaName == "custom")
  {

  }
}

void Order::add_souvenirs(string souvenirName)
{
  items.push_back(souvenirs.find(souvenirName)->first);
  orderPrice += souvenirs.find(souvenirName)->second;
}