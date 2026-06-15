#include "coffeemachine.h"
#include "console.h"

int main() {
  CoffeeMachine machine;
  Console console(&machine);
  console.run();
  return 0;
}
