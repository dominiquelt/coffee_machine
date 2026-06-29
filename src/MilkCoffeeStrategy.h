#ifndef MILKCOFFEE_H
#define MILKCOFFEE_H

#include "IBrewingStrategy.h"

class MilkCoffee : public IBrewingStrategy {
 public:
  ~MilkCoffee() = default;

  std::unique_ptr<ICoffee> brew(int& water, int& beans, int& milk) override;

 private:
  const int WATER_NEEDED = 30;
  const int BEANS_NEEDED = 15;
  const int MILK_NEEDED = 100;
};

#endif
