#ifndef COFFEEMACHINE_H
#define COFFEEMACHINE_H

#include <memory>
#include <string>

#include "IBrewingStrategy.h"
#include "icoffeemachine.h"

class CoffeeMachine : public ICoffeeMachine {
 public:
  CoffeeMachine();
  ~CoffeeMachine();

  std::unique_ptr<ICoffee> MakeCoffee() override;
  void RefillWater() override;
  void RefillBeans() override;
  void RefillMilk() override;
  void SetStrategy(std::unique_ptr<IBrewingStrategy> strategy) override;

  std::string getStatus() const override;

  int GetWater() const override { return CurrentWater; }
  int GetBeans() const override { return CurrentBeans; }
  int GetMilk() const override { return CurrentMilk; }

 private:
  const int MAX_WATER = 1000;
  const int MAX_BEANS = 250;
  const int MAX_MILK = 1000;

  int CurrentWater;
  int CurrentBeans;
  int CurrentMilk;

  std::unique_ptr<IBrewingStrategy> strategy_;
};

#endif
