#ifndef MILKDECORATOR_H
#define MILKDECORATOR_H

#include "CoffeeDecorator.h"

class MilkDecorator : public CoffeeDecorator {
 public:
  using CoffeeDecorator::CoffeeDecorator;

  std::string getIngredients() const override {
    return coffee_->getIngredients() + ", Mleko";
  }
};

#endif
