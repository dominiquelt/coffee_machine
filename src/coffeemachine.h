#ifndef COFFEEMACHINE_H
#define COFFEEMACHINE_H

#include <string>

#include "icoffeemachine.h"

class CoffeeMachine : public ICoffeeMachine {
 public:
  CoffeeMachine();
  ~CoffeeMachine();

  bool MakeCoffee() override;
  void RefillWater() override;
  void RefillBeans() override;

  std::string getStatus() const override;

  int GetWater() const override { return *CurrentWater; }
  int GetBeans() const override { return *CurrentBeans; }

 private:
  const int MAX_WATER = 1000;
  const int MAX_BEANS = 250;
  const int WATER_PER_COFFEE = 200;
  const int BEANS_PER_COFFEE = 15;

  int* CurrentWater;
  int* CurrentBeans;
};

#endif
