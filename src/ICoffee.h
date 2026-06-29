#ifndef ICOFFEE_H
#define ICOFFEE_H

#include <string>

class ICoffee {
 public:
  virtual ~ICoffee() = default;

  virtual std::string getName() const = 0;
  virtual std::string getIngredients() const = 0;
};

#endif
