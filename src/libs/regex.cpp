//
// Created by VladPC on 20/01/2020.
//

#include "regex.hpp"
#include <regex>

list<string> getRegexMatch(string text, const string &reg) {
  regex re(reg);
  smatch match{};
  list<string> matches{};

  while (regex_search(text, match, re)) {
    matches.push_back(match.str(1));
    text = match.suffix().str();
  }

  return matches;
}
