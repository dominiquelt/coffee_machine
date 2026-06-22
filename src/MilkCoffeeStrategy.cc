#include "MilkCoffeeStrategy.h"

#include <iostream>

bool MilkCoffee::brew(int& water, int& beans, int& milk) {
  if (water < WATER_NEEDED || beans < BEANS_NEEDED || milk < MILK_NEEDED) {
    return false;
  }
  std::cout << "Parzę MilkCoffee ...\n";
  water -= WATER_NEEDED;
  beans -= BEANS_NEEDED;
  milk -= MILK_NEEDED;
  return true;
}
