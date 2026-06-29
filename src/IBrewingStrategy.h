#ifndef IBREWINGSTRATEGY_H
#define IBREWINGSTRATEGY_H

#include <memory>

#include "ICoffee.h"

class IBrewingStrategy {
 public:
  virtual ~IBrewingStrategy() = default;

  virtual std::unique_ptr<ICoffee> brew(int& water, int& beans, int& milk) = 0;
};

#endif
