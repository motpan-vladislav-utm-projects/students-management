//
// Created by VladPC on 19/01/2020.
//

#include <string>
#include <list>
#include <vector>

using namespace std;

class Student {

 public:
  int id;
  string firstName;
  string lastName;

  Student(string firstName, string lastName, int id = NULL);

  list<string> serialize();
  static Student deserialize(vector<string> data);
};
