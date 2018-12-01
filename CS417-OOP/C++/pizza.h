#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <list>

using namespace std;

struct Pizza {
  // toppings: do with map, map each topping to it's price
  // - build a linked list of the toppings.
  // pizza type
  // figure out how to keep track of toppings being used and their prices
private:
  map<string, float> onpizza;
  map<string, float> toppings;
  double pizza_price;
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
  void set_pizza_type(string);
  void set_pizza_size(string);
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

  pizza_price = 0.00;
}

//return pizza if it's a signature after determining size, else add toppings for custom(can be done within order.h)
void Pizza::set_pizza_type(string pizzatype)
{
  if(pizzatype == "Margherita" || pizzatype == "margherita")
  {
    pizza_price += Margherita;
  }
  else if(pizzatype == "Hawaiian" || pizzatype == "hawaiian")
  {
    pizza_price += Hawaiian;
  }
  else if(pizzatype == "Meats" || pizzatype == "meats")
  {
    pizza_price += Meats;
  }
  else if(pizzatype == "Custom" || pizzatype == "custom")
  {
    pizza_price += std_reg;
  }
  else
    cout << "Pizza unknown" << endl;
}

void Pizza::set_pizza_size(string size)
{
  if(size == "Family" || size == "family")
  {
    pizza_price += upsize;
  }
  else if(size == "Individual" || size == "individual")
  {
    pizza_price += downsize;
  }
  else
  {
    cout << "Pizza is regular size" << endl;
  }
}