#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "EspressoStrategy.h"
#include "coffeemachine.h"
#include "console.h"
#include "mocks.h"

using namespace ::testing;

class ConsoleTests : public ::testing::Test {
 protected:
  void SetUp() override {
    console_ = std::make_unique<Console>(&machine_mock_, &input_mock_);
  }

  NiceMock<CoffeeMachineMock> machine_mock_;
  NiceMock<InputMock> input_mock_;
  std::unique_ptr<Console> console_;
};

TEST_F(ConsoleTests, MakeCoffeeCalledOnSuccessPath) {
  EXPECT_CALL(input_mock_, getChoice())
      .WillOnce(Return(1))   //  make coffee
      .WillOnce(Return(1))   // Espresso
      .WillOnce(Return(0));  // exit
  EXPECT_CALL(machine_mock_, SetStrategy(_));
  EXPECT_CALL(machine_mock_, MakeCoffee()).WillOnce(Return(true));
  console_->run();
}

TEST_F(ConsoleTests, MakeCoffeeCalledOnFailurePath) {
  EXPECT_CALL(input_mock_, getChoice())
      .WillOnce(Return(1))   //  make coffee
      .WillOnce(Return(1))   //  Espresso
      .WillOnce(Return(0));  // exit
  EXPECT_CALL(machine_mock_, SetStrategy(_));
  EXPECT_CALL(machine_mock_, MakeCoffee()).WillOnce(Return(false));
  console_->run();
}

TEST_F(ConsoleTests, GetStatusCalledOnChoice2) {
  EXPECT_CALL(input_mock_, getChoice()).WillOnce(Return(2)).WillOnce(Return(0));
  EXPECT_CALL(machine_mock_, getStatus())
      .WillOnce(Return("Water: 1000 ml\nBeans: 250 g"));
  console_->run();
}

TEST_F(ConsoleTests, RefillWaterCalledOnChoice3) {
  EXPECT_CALL(input_mock_, getChoice()).WillOnce(Return(3)).WillOnce(Return(0));
  EXPECT_CALL(machine_mock_, RefillWater()).Times(1);
  console_->run();
}

TEST_F(ConsoleTests, RefillBeansCalledOnChoice4) {
  EXPECT_CALL(input_mock_, getChoice()).WillOnce(Return(4)).WillOnce(Return(0));
  EXPECT_CALL(machine_mock_, RefillBeans()).Times(1);
  console_->run();
}

class CoffeeMachineTests : public ::testing::Test {
 protected:
  CoffeeMachine machine_;
};

TEST_F(CoffeeMachineTests, MakeCoffeeReturnsFalseWithNoStrategy) {
  EXPECT_FALSE(machine_.MakeCoffee());
}

TEST_F(CoffeeMachineTests, EspressoReducesWaterAndBeans) {
  machine_.SetStrategy(std::make_unique<Espresso>());
  int waterBefore = machine_.GetWater();
  int beansBefore = machine_.GetBeans();
  machine_.MakeCoffee();
  EXPECT_EQ(machine_.GetWater(), waterBefore - 30);
  EXPECT_EQ(machine_.GetBeans(), beansBefore - 15);
}
