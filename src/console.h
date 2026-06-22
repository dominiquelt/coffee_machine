#ifndef CONSOLE_H
#define CONSOLE_H

#include "IInput.h"
#include "icoffeemachine.h"

class Console {
 public:
  explicit Console(ICoffeeMachine* machine, IInput* input);
  ~Console();
  void run();

 private:
  void ProcessChoice(int choice);
  void SelectCoffee();
  ICoffeeMachine* machine_;
  IInput* input_;
  void PrintOptions() const;
};

#endif
