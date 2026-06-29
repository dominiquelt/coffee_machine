#include "console.h"

#include <iostream>
#include <memory>

#include "EspressoDippoStrategy.h"
#include "EspressoStrategy.h"
#include "FilteredCoffeeStrategy.h"
#include "MilkDecorator.h"
#include "SugarDecorator.h"
#include "SyrupDecorator.h"

Console::Console(ICoffeeMachine* machine, IInput* input)
    : machine_(machine), input_(input) {}
Console::~Console() {}

void Console::PrintOptions() const {
  std::cout << "\n[1] Zrob kawe\n"
            << "[2] Pokaz stan ekspresu\n"
            << "[3] Dolej wody\n"
            << "[4] Wsyp ziarna\n"
            << "[0] Wylacz ekspres\n"
            << "Wybor: ";
}

std::unique_ptr<ICoffee> Console::SelectAddons(std::unique_ptr<ICoffee> coffee) {
  int choice = -1;
  while (choice != 4) {
    std::cout << "\n[1] Mleko\n"
              << "[2] Cukier\n"
              << "[3] Syrop\n"
              << "[4] Koniec\n"
              << "Wybor: ";
    choice = input_->getChoice();
    switch (choice) {
      case 1:
        coffee = std::make_unique<MilkDecorator>(std::move(coffee));
        break;
      case 2:
        coffee = std::make_unique<SugarDecorator>(std::move(coffee));
        break;
      case 3:
        coffee = std::make_unique<SyrupDecorator>(std::move(coffee));
        break;
      case 4:
        break;
      default:
        std::cout << "Nieznana opcja.\n";
        break;
    }
  }
  return coffee;
}

void Console::SelectCoffee() {
  std::cout << "\n[1] Espresso\n"
            << "[2] Filtered Coffee\n"
            << "[3] Espresso Dippo\n"
            << "Wybor: ";
  int choice = input_->getChoice();
  switch (choice) {
    case 1:
      machine_->SetStrategy(std::make_unique<Espresso>());
      break;
    case 2:
      machine_->SetStrategy(std::make_unique<Filtered>());
      break;
    case 3:
      machine_->SetStrategy(std::make_unique<EspressoDippo>());
      break;
    default:
      std::cout << "Nieznana opcja.\n";
      return;
  }

  auto coffee = machine_->MakeCoffee();
  if (!coffee) {
    std::cout << "Blad: Za malo zasobow!\n";
    return;
  }

  coffee = SelectAddons(std::move(coffee));
  std::cout << "Kawa gotowa: " << coffee->getIngredients() << "\n";
}

void Console::ProcessChoice(int choice) {
  switch (choice) {
    case 1:
      SelectCoffee();
      break;
    case 2:
      std::cout << machine_->getStatus() << "\n";
      break;
    case 3:
      machine_->RefillWater();
      std::cout << "Woda uzupelniona do " << machine_->GetWater() << " ml.\n";
      break;
    case 4:
      machine_->RefillBeans();
      std::cout << "Ziarna uzupelnione do " << machine_->GetBeans() << " g.\n";
      break;
    case 0:
      std::cout << "Wylaczam ekspres. Do widzenia!\n";
      break;
    default:
      std::cout << "Nieznana opcja. Sprobuj ponownie.\n";
      break;
  }
}

void Console::run() {
  int choice = -1;

  while (choice != 0) {
    PrintOptions();
    choice = input_->getChoice();
    ProcessChoice(choice);
  }
}
