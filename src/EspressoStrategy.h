#ifndef ESPRESSOSTRATEGY_H
#define ESPRESSOSTRATEGY_H

#include "IBrewingStrategy.h"

class Espresso : public IBrewingStrategy {
 public:
  bool brew(int& water, int& beans, int& milk) override;

 private:
  const int WATER_NEEDED = 30;
  const int BEANS_NEEDED = 15;
  const int MILK_NEEDED = 0;
};

#endif
