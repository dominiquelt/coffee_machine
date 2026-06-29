#ifndef SUGARDECORATOR_H
#define SUGARDECORATOR_H

#include "CoffeeDecorator.h"

class SugarDecorator : public CoffeeDecorator {
 public:
  using CoffeeDecorator::CoffeeDecorator;

  std::string getIngredients() const override {
    return coffee_->getIngredients() + ", Cukier";
  }
};

#endif
