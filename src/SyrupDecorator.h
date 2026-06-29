#ifndef SYRUPDECORATOR_H
#define SYRUPDECORATOR_H

#include "CoffeeDecorator.h"

class SyrupDecorator : public CoffeeDecorator {
 public:
  using CoffeeDecorator::CoffeeDecorator;

  std::string getIngredients() const override {
    return coffee_->getIngredients() + ", Syrop";
  }
};

#endif
