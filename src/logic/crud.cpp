//
// Created by VladPC on 21/01/2020.
//

#include "crud.hpp"
#include "StudentsStore.hpp"
#include "console.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

string __showStudents(bool const &sort) {
  StudentsStore::StudentsType students = studentsStore.getStudents(sort);

  if (students.empty()) {
    return "No students in " + studentsStore.storeFilePath + ". Please add students.";
  }

  const int id_width = 7;
  const int name_width = 15;
  const int num_fields = 3;

  const std::string sep = " |";
  const int total_width = id_width + name_width * 2 + sep.size() * num_fields;
  const std::string line = sep + std::string(total_width - 1, '-') + '|';

  std::cout << line << '\n'
            << sep << std::setw(id_width) << "id"
            << sep << std::setw(name_width) << "first name"
            << sep << std::setw(name_width) << "last name"
            << sep << '\n' << line << endl;

  for (Student const &student: students) {
    std::cout << sep << std::setw(id_width) << student.id
              << sep << std::setw(name_width) << student.firstName
              << sep << std::setw(name_width) << student.lastName
              << sep << endl;
  }

  std::cout << line << endl;

  return "";
}

string __addStudents(bool const &add) {
  bool running = true;
  StudentsStore::StudentsType toAddStudents;

  string want;
  int studentNr = 0;

  while (running) {
    Student student;

    printf("Student Nr. %d:\n", ++studentNr);
    printf("First name: ");
    getline(cin, student.firstName);

    printf("Last name: ");
    getline(cin, student.lastName);

    toAddStudents.push_back(student);

    printf("Do you want continue? [Y/n] ");
    getline(cin, want);
    printf("\n");

    if (want == "n") {
      running = false;
    }
  }

  if (add) {
    studentsStore.addStudents(toAddStudents);
  } else {
    studentsStore.setStudents(toAddStudents);
  }

  return "Students saved success.";
}

string showStudents() {
  return __showStudents(false);
}

string showSortedStudents() {
  return __showStudents(true);
}

string addStudents() {
  return __addStudents(false);
}

string addNewStudents() {
  return __addStudents(true);
}

string updateFromFile() {
  studentsStore.updateStore(true);
  return "Updated successful.";
}

string updateStudent() {
  string __studentID;
  printf("Student ID: ");
  getline(cin, __studentID);

  int studentID = stoi(__studentID);
  StudentsStore::StudentsType students = studentsStore.getStudents();

  for (Student &student: students) {
    if (student.id == studentID) {
      printf("First name [%s]: ", student.firstName.c_str());
      getline(cin, student.firstName);

      printf("Last name [%s]: ", student.lastName.c_str());
      getline(cin, student.lastName);

      studentsStore.setStudents(students);
      return "Student with ID \"" + to_string(studentID) + "\" successfully updated.";
    }
  }

  return "Student with ID \"" + to_string(studentID) + "\" not found.";
}
