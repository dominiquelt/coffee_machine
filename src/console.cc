#include "console.h"

#include <iostream>

Console::Console(ICoffeeMachine* machine) : machine_(machine) {}
Console::~Console() {}

void Console::PrintOptions() const {
  std::cout << "\n[1] Zrob kawe\n"
            << "[2] Pokaz stan ekspresu\n"
            << "[3] Dolej wody\n"
            << "[4] Wsyp ziarna\n"
            << "[0] Wylacz ekspres\n"
            << "Wybor: ";
}

void Console::ProcessChoice(int choice) {
  switch (choice) {
    case 1:
      if (machine_->MakeCoffee()) {
        std::cout << "Kawa gotowa!\n";
      } else {
        std::cout << "Blad: Za malo wody lub ziaren!\n";
      }
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
  int choice;
  while (true) {
    PrintOptions();
    std::cin >> choice;
    ProcessChoice(choice);
    if (choice == 0) return;
  }
}
