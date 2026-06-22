#include "coffeemachine.h"

#include <string>

CoffeeMachine::CoffeeMachine()
    : CurrentWater(MAX_WATER), CurrentBeans(MAX_BEANS), CurrentMilk(MAX_MILK) {}

CoffeeMachine::~CoffeeMachine() {}

void CoffeeMachine::SetStrategy(std::unique_ptr<IBrewingStrategy> strategy) {
  strategy_ = std::move(strategy);
}

bool CoffeeMachine::MakeCoffee() {
  if (!strategy_) {
    return false;
  }
  return strategy_->brew(CurrentWater, CurrentBeans, CurrentMilk);
}

void CoffeeMachine::RefillWater() {
  CurrentWater = MAX_WATER;
}
void CoffeeMachine::RefillMilk() {
  CurrentMilk = MAX_MILK;
}

void CoffeeMachine::RefillBeans() {
  CurrentBeans = MAX_BEANS;
}

std::string CoffeeMachine::getStatus() const {
  return "Water: " + std::to_string(CurrentWater) + " ml\n" +
         "Beans: " + std::to_string(CurrentBeans) + " g\n" +
         "Milk: " + std::to_string(CurrentMilk) + "ml";
}
