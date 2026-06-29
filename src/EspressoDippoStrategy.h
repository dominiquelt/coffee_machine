#ifndef ESPRESSODIPPOSTRATEGY_H
#define ESPRESSODIPPOSTRATEGY_H

#include "IBrewingStrategy.h"

class EspressoDippo : public IBrewingStrategy {
 public:
  std::unique_ptr<ICoffee> brew(int& water, int& beans, int& milk) override;

 private:
  const int WATER_NEEDED = 30;
  const int BEANS_NEEDED = 25;
};

#endif
