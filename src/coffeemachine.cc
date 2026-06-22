#include "coffeemachine.h"

#include <string>

CoffeeMachine::CoffeeMachine()
    : CurrentWater(MAX_WATER), CurrentBeans(MAX_BEANS) {}

CoffeeMachine::~CoffeeMachine() {}

bool CoffeeMachine::MakeCoffee() {
  if (CurrentWater < WATER_PER_COFFEE || CurrentBeans < BEANS_PER_COFFEE) {
    return false;
  }
  CurrentWater -= WATER_PER_COFFEE;
  CurrentBeans -= BEANS_PER_COFFEE;
  return true;
}

void CoffeeMachine::RefillWater() {
  CurrentWater = MAX_WATER;
}

void CoffeeMachine::RefillBeans() {
  CurrentBeans = MAX_BEANS;
}

std::string CoffeeMachine::getStatus() const {
  return "Water: " + std::to_string(CurrentWater) + " ml\n" +
         "Beans: " + std::to_string(CurrentBeans) + " g";
}
