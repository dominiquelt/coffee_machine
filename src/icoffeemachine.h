#ifndef ICOFFEEMACHINE_H
#define ICOFFEEMACHINE_H

#include <string>

class ICoffeeMachine {
 public:
  virtual ~ICoffeeMachine() = default;

  virtual bool MakeCoffee() = 0;
  virtual void RefillWater() = 0;
  virtual void RefillBeans() = 0;
  virtual std::string getStatus() const = 0;
  virtual int GetWater() const = 0;
  virtual int GetBeans() const = 0;
};

#endif
