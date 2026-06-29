#include "FilteredCoffeeStrategy.h"

#include <iostream>

#include "CoffeeCups.h"

std::unique_ptr<ICoffee> Filtered::brew(int& water, int& beans, int& milk) {
  if (water < WATER_NEEDED || beans < BEANS_NEEDED) {
    return nullptr;
  }
  std::cout << "Parzę Filtered Coffee ...\n";
  water -= WATER_NEEDED;
  beans -= BEANS_NEEDED;
  return std::make_unique<FilterCoffeeCup>();
}
