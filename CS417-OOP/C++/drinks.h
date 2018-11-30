#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Drinks {
private:
  int dietdrink;
  int regdrink;
  int water;
  int beer;
  const static float price_diet   = 1.29;
  const static float price_reg    = 1.29;
  const static float price_water  = 0.00;
  const static float price_beer   = 4.99;

public:
  Drinks();
  Drinks(int num_diet, int num_reg, int num_water, int num_beer);
  void set_diet_drink(int num_diet);
  void set_reg_drink(int num_reg);
  void set_water(int num_water);
  void set_beer(int num_beer);
  int get_diet_drink();
  int get_reg_drink();
  int get_water();
  int get_beer();
};

Drinks::Drinks()
{
  dietdrink = 0;
  regdrink = 0;
  water = 0;
  beer = 0;
}
Drinks::Drinks(int num_diet, int num_reg, int num_water, int num_beer)
{
  dietdrink = num_diet;
  regdrink = num_reg;
  water = num_water;
  beer = num_beer;
}
void Drinks::set_diet_drink(int num_diet)
{
  dietdrink = num_diet;
}
void Drinks::set_reg_drink(int num_reg)
{
  regdrink = num_reg;
}
void Drinks::set_water(int num_water)
{
  water = num_water;
}
void Drinks::set_beer(int num_beer)
{
  beer = num_beer;
}
int Drinks::get_diet_drink()
{
  return dietdrink;
}
int Drinks::get_reg_drink()
{
  return regdrink;
}
int Drinks::get_water()
{
  return water;
}
int Drinks::get_beer()
{
  return beer;
}
