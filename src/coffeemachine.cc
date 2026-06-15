#include "coffeemachine.h"

#include <string>

CoffeeMachine::CoffeeMachine()
    : CurrentWater(new int(MAX_WATER)), CurrentBeans(new int(MAX_BEANS)) {}

CoffeeMachine::~CoffeeMachine() {
  delete CurrentWater;
  delete CurrentBeans;
}

bool CoffeeMachine::MakeCoffee() {
  if (*CurrentWater < WATER_PER_COFFEE || *CurrentBeans < BEANS_PER_COFFEE) {
    return false;
  }
  *CurrentWater -= WATER_PER_COFFEE;
  *CurrentBeans -= BEANS_PER_COFFEE;
  return true;
}

void CoffeeMachine::RefillWater() {
  *CurrentWater = MAX_WATER;
}

void CoffeeMachine::RefillBeans() {
  *CurrentBeans = MAX_BEANS;
}

std::string CoffeeMachine::getStatus() const {
  return "Water: " + std::to_string(*CurrentWater) + " ml\n" +
         "Beans: " + std::to_string(*CurrentBeans) + " g";
}
