//
// Created by VladPC on 19/01/2020.
//

#include "StudentsStore.hpp"
#include <csv.hpp>
#include <utility>

using namespace std;

StudentsStore studentsStore; // NOLINT(cert-err58-cpp)


void swap(Student *xStudent, Student *yStudent) {
  Student temp = *xStudent;
  *xStudent = *yStudent;
  *yStudent = temp;
}

// An optimized version of Bubble Sort
void sortStudents(StudentsStore::StudentsType &students) {
  int i, j;
  bool swapped;

  int n = students.size();

  for (i = 0; i < n - 1; i++) {
    swapped = false;

    for (j = 0; j < n - i - 1; j++) {
      if (students.at(j).firstName > students.at(j + 1).firstName) {
        swap(&students.at(j), &students.at(j + 1));
        swapped = true;
      }
    }

    // IF no two elements were swapped by inner loop, then break
    if (!swapped) {
      break;
    }
  }
}

void StudentsStore::initStore(string filePath) {
  storeFilePath = std::move(filePath);
  students.clear();
}

StudentsStore::StudentsType StudentsStore::getStudents(bool const &sort) {
  updateStore();

  if (sort) {
    StudentsStore::StudentsType sortedStudents = students;
    sortStudents(sortedStudents);
    return sortedStudents;
  }

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
  students.clear();

  for (CSVLineType const &studentData: studentsData) {
    students.push_back(Student::deserialize(studentData));
  }
}

void StudentsStore::syncData() {
  ofstream file(storeFilePath);
  file.clear();

  for (Student &student: students) {
    saveAsCSV(student.serialize(), file);
  }

  file.close();
}
