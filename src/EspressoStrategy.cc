#include "EspressoStrategy.h"

#include <iostream>

bool Espresso::brew(int& water, int& beans, int& milk) {
  if (water < WATER_NEEDED || beans < BEANS_NEEDED) {
    return false;
  }
  std::cout << "Parzę Espresso ...\n";
  water -= WATER_NEEDED;
  beans -= BEANS_NEEDED;
  return true;
}
