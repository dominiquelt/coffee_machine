#ifndef IINPUT_H
#define IINPUT_H

#include <string>

class IInput {
 public:
  virtual ~IInput() = default;

  virtual int getChoice() = 0;
};

#endif
