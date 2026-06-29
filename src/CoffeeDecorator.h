#ifndef COFFEEDECORATOR_H
#define COFFEEDECORATOR_H

#include <memory>

#include "ICoffee.h"

class CoffeeDecorator : public ICoffee {
 public:
  explicit CoffeeDecorator(std::unique_ptr<ICoffee> coffee)
      : coffee_(std::move(coffee)) {}

  std::string getName() const override { return coffee_->getName(); }
  std::string getIngredients() const override {
    return coffee_->getIngredients();
  }

 protected:
  std::unique_ptr<ICoffee> coffee_;
};

#endif
