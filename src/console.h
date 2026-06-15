#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

#include "coffeemachine.h"

class Console {
 public:
  Console();
  ~Console();
  void run();

 private:
  CoffeeMachine machine;
  void PrintOptions() const;
};

#endif
