#ifndef FILTEREDCOFFEESTRATEGY_H
#define FILTEREDCOFFEESTRATEGY_H

#include "IBrewingStrategy.h"

class Filtered : public IBrewingStrategy {
 public:
  ~Filtered() = default;

  bool brew(int& water, int& beans, int& milk) override;

 private:
  const int WATER_NEEDED = 200;
  const int BEANS_NEEDED = 10;
  const int MILK_NEEDED = 0;
};

#endif
