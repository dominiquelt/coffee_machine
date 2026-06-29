#include "EspressoDippoStrategy.h"

#include <iostream>

#include "CoffeeCups.h"

std::unique_ptr<ICoffee> EspressoDippo::brew(int& water, int& beans,
                                              int& milk) {
  if (water < WATER_NEEDED || beans < BEANS_NEEDED) {
    return nullptr;
  }
  std::cout << "Parzę Espresso Dippo ...\n";
  water -= WATER_NEEDED;
  beans -= BEANS_NEEDED;
  return std::make_unique<EspressoDippoCup>();
}
