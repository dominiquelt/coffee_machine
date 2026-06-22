#pragma once

#include <gmock/gmock.h>

#include "IInput.h"
#include "icoffeemachine.h"

class CoffeeMachineMock : public ICoffeeMachine {
 public:
  MOCK_METHOD(bool, MakeCoffee, (), (override));
  MOCK_METHOD(void, RefillWater, (), (override));
  MOCK_METHOD(void, RefillBeans, (), (override));
  MOCK_METHOD(std::string, getStatus, (), (const, override));
  MOCK_METHOD(int, GetWater, (), (const, override));
  MOCK_METHOD(int, GetBeans, (), (const, override));
};

class InputMock : public IInput {
 public:
  MOCK_METHOD(int, getChoice, (), (override));
};
