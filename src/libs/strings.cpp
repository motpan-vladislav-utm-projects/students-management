//
// Created by VladPC on 18/01/2020.
//

#include "strings.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>

std::string quote(const std::string &s) {
  std::stringstream ss;
  ss << std::quoted(s);
  return ss.str();
}

std::string unquote(const std::string &s) {
  std::string result;
  std::stringstream ss(s);
  ss >> std::quoted(result);
  return result;
}
