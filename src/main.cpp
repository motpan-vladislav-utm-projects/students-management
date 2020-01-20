
#include "StudentsStore.hpp"
#include "menu.hpp"

int main() {
  studentsStore.initStore("students.csv");

  Menu::ActionType exitAction{"Quit", []() {}};

  Menu::CallbacksType callbacks{};

  Console console(GetStdHandle(STD_OUTPUT_HANDLE));
  Menu{"Students Management", console, exitAction, callbacks}.init();

  return EXIT_SUCCESS;
}
