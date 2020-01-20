
#include "StudentsStore.hpp"
#include "menu.hpp"

int main() {
  studentsStore.initStore("students.csv");
  initMenu();

  return EXIT_SUCCESS;
}
