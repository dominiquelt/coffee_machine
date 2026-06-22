#include "ConsoleInput.h"
#include "coffeemachine.h"
#include "console.h"

int main() {
  CoffeeMachine machine;
  ConsoleInput input;
  Console console(&machine, &input);
  console.run();
  return 0;
}
