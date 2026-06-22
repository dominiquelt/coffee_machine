#include <gmock/gmock.h>
#include <gtest/gtest.h>

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
  EXPECT_CALL(input_mock_, getChoice()).WillOnce(Return(1)).WillOnce(Return(0));
  EXPECT_CALL(machine_mock_, MakeCoffee()).WillOnce(Return(true));
  console_->run();
}

TEST_F(ConsoleTests, MakeCoffeeCalledOnFailurePath) {
  EXPECT_CALL(input_mock_, getChoice()).WillOnce(Return(1)).WillOnce(Return(0));
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
