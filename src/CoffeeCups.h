#ifndef COFFEECUPS_H
#define COFFEECUPS_H

#include "ICoffee.h"

class EspressoCup : public ICoffee {
 public:
  std::string getName() const override { return "Espresso"; }
  std::string getIngredients() const override { return "Espresso"; }
};

class FilterCoffeeCup : public ICoffee {
 public:
  std::string getName() const override { return "Filtered Coffee"; }
  std::string getIngredients() const override { return "Filtered Coffee"; }
};

class EspressoDippoCup : public ICoffee {
 public:
  std::string getName() const override { return "Espresso Dippo"; }
  std::string getIngredients() const override { return "Espresso Dippo"; }
};

class MilkCoffeeCup : public ICoffee {
 public:
  std::string getName() const override { return "Milk Coffee"; }
  std::string getIngredients() const override { return "Milk Coffee"; }
};

#endif
