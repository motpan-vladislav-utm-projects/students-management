
#include "StudentsStore.hpp"
#include "menu.hpp"
#include "crud.hpp"

int main() {
  studentsStore.initStore("students.csv");

  Menu::ActionType exitAction{"Quit", []() { return ""; }};

  Menu::CallbacksType callbacks{
      Menu::ActionType{"Show students", showStudents},
      Menu::ActionType{"Insert new students", addStudents},
      Menu::ActionType{"Add new students", addNewStudents},
      Menu::ActionType{"Change student", updateStudent},
      Menu::ActionType{"Order students by name", showSortedStudents},
      Menu::ActionType{"Update from file", updateFromFile},
  };

  Menu{"Students Management", Console{}, exitAction, callbacks}.init();

  return EXIT_SUCCESS;
}
