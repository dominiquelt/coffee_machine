#include "FilteredCoffeeStrategy.h"

#include <iostream>

bool Filtered::brew(int& water, int& beans, int& milk) {
  if (water < WATER_NEEDED || beans < BEANS_NEEDED) {
    return false;
  }
  std::cout << "Parzę Filtered Coffee ...\n";
  water -= WATER_NEEDED;
  beans -= BEANS_NEEDED;
  return true;
}
