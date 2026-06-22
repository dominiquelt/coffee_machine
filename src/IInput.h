#ifndef IINPUT_H
#define IINPUT_H

class IInput {
 public:
  virtual ~IInput() = default;

  virtual int getChoice() = 0;
};

#endif
