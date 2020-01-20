//
// Created by VladPC on 19/01/2020.
//

#include "StudentsStore.hpp"
#include <csv.hpp>
#include <utility>

using namespace std;

StudentsStore studentsStore; // NOLINT(cert-err58-cpp)

void StudentsStore::initStore(string filePath) {
  storeFilePath = std::move(filePath);
  students.clear();
}

StudentsStore::StudentsType StudentsStore::getStudents() {
  updateStore();
  return students;
}

void StudentsStore::insertStudents(StudentsStore::StudentsType studentsData, bool append) {
  ofstream file;

  if (append) {
    updateStore();
    file.open(storeFilePath, ios_base::app);
  } else {
    students.clear();
    file.open(storeFilePath);
  }

  for (Student &student: studentsData) {
    saveAsCSV(student.serialize(), file);
    students.push_back(student);
  }

  file.close();
}

void StudentsStore::addStudents(StudentsStore::StudentsType studentsData) {
  insertStudents(std::move(studentsData), true);
}

void StudentsStore::setStudents(StudentsStore::StudentsType studentsData) {
  insertStudents(std::move(studentsData), false);
}

void StudentsStore::updateStore(bool force) {
  if (!force && !students.empty()) {
    return;
  }

  ifstream file(storeFilePath);
  CSVDataType studentsData = readFromCSV(file);
  file.close();

  for (CSVLineType const &studentData: studentsData) {
    students.push_back(Student::deserialize(studentData));
  }
}
