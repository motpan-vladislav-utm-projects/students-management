//
// Created by VladPC on 19/01/2020.
//

#include <string>
#include "student.hpp"

using namespace std;

class StudentsStore {
 public:
  using StudentsType = list<Student>;
  string storeFilePath;

  StudentsType getStudents();
  void setStudents(StudentsType studentsData);
  void addStudents(StudentsType studentsData);
  void updateStore(bool force = false);
  void initStore(string filePath);

 private:
  StudentsType students;

  void insertStudents(StudentsType studentsData, bool append);
};

extern StudentsStore studentsStore;
