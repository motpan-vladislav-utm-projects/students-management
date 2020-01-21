//
// Created by VladPC on 19/01/2020.
//

#include <string>
#include "student.hpp"

using namespace std;

class StudentsStore {
 public:
  using StudentsType = vector<Student>;
  string storeFilePath;

  StudentsType getStudents(bool const &sort = false);
  void setStudents(StudentsType studentsData);
  void addStudents(StudentsType studentsData);
  void updateStore(bool force = false);
  void initStore(string filePath);
  void syncData();

 private:
  StudentsType students;

  void insertStudents(StudentsType studentsData, bool append);
};

extern StudentsStore studentsStore;
