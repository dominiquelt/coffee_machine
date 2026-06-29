#include "MilkCoffeeStrategy.h"

#include <iostream>

#include "CoffeeCups.h"

std::unique_ptr<ICoffee> MilkCoffee::brew(int& water, int& beans, int& milk) {
  if (water < WATER_NEEDED || beans < BEANS_NEEDED || milk < MILK_NEEDED) {
    return nullptr;
  }
  std::cout << "Parzę MilkCoffee ...\n";
  water -= WATER_NEEDED;
  beans -= BEANS_NEEDED;
  milk -= MILK_NEEDED;
  return std::make_unique<MilkCoffeeCup>();
}
