#include "ConsoleInput.h"

#include <iostream>

#include "console.h"

ConsoleInput::ConsoleInput() {}
ConsoleInput::~ConsoleInput() {}

int ConsoleInput::getChoice() {
  int choice;
  std::cin >> choice;
  return choice;
}
