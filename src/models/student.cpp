//
// Created by VladPC on 19/01/2020.
//

#include "student.hpp"
#include <utility>

#include "strings.hpp"
#include "csv.hpp"

static int lastId = 0;

Student::Student(string firstName, string lastName, int id) {
  this->firstName = std::move(firstName);
  this->lastName = std::move(lastName);

  this->id = id ? id : ++lastId;
}

list<string> Student::serialize() {
  return list<string>{to_string(id), firstName, lastName};
}

Student Student::deserialize(vector<string> data) {
  return Student(data.at(1), data.at(2), stoi(data.at(0)));
}
