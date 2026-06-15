#ifndef COFFEEMACHINE_H
#define COFFEEMACHINE_H

#include <string>

class CoffeeMachine {
 public:
  CoffeeMachine();
  ~CoffeeMachine();

  bool MakeCoffee();
  void RefillWater();
  void RefillBeans();

  std::string getStatus() const;

  int GetWater() const { return *CurrentWater; }
  int GetBeans() const { return *CurrentBeans; }

 private:
  const int MAX_WATER = 1000;
  const int MAX_BEANS = 250;
  const int WATER_PER_COFFEE = 200;
  const int BEANS_PER_COFFEE = 15;

  int* CurrentWater;
  int* CurrentBeans;
};

#endif
