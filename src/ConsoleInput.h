#ifndef CONSOLEINPUT_H
#define CONSOLEINPUT_H

#include "IInput.h"

class ConsoleInput : public IInput {
 public:
  ConsoleInput();
  ~ConsoleInput();
  int getChoice() override;
};

#endif
