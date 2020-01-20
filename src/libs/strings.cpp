//
// Created by VladPC on 18/01/2020.
//

#include "strings.hpp"

#include <iostream>

using namespace std;

void replaceAll(std::string &data, const std::string &toSearch, const std::string &replaceStr) {
  size_t pos = data.find(toSearch);

  while (pos != std::string::npos) {
    data.replace(pos, toSearch.size(), replaceStr);
    pos = data.find(toSearch, pos + replaceStr.size());
  }
}
