#ifndef IBREWINGSTRATEGY_H
#define IBREWINGSTRATEGY_H

class IBrewingStrategy {
 public:
  virtual ~IBrewingStrategy() = default;

  virtual bool brew(int& water, int& beans, int& milk) = 0;
};

#endif
