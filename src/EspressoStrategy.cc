#include "EspressoStrategy.h"

#include <iostream>

#include "CoffeeCups.h"

std::unique_ptr<ICoffee> Espresso::brew(int& water, int& beans, int& milk) {
  if (water < WATER_NEEDED || beans < BEANS_NEEDED) {
    return nullptr;
  }
  std::cout << "Parzę Espresso ...\n";
  water -= WATER_NEEDED;
  beans -= BEANS_NEEDED;
  return std::make_unique<EspressoCup>();
}
