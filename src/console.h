#ifndef CONSOLE_H
#define CONSOLE_H

#include "icoffeemachine.h"

class Console {
 public:
  explicit Console(ICoffeeMachine* machine);
  ~Console();
  void run();
  void ProcessChoice(int choice);

 private:
  ICoffeeMachine* machine_;
  void PrintOptions() const;
};

#endif
