//
// Created by VladPC on 19/01/2020.
//

#include <strings.hpp>
#include <iostream>
#include <csv.hpp>
#include <regex.hpp>

using namespace std;

void saveAsCSV(list<string> data, ofstream &file) {
  list<string>::iterator currentData;
  for (currentData = data.begin(); currentData != data.end(); ++currentData) {
    file << currentData->c_str();

    if ((currentData != data.end()) && (currentData != --data.end())) {
      file << ",";
    }
  }

  file << "\n";
}

CSVDataType readFromCSV(ifstream &file) {
  string const CSV_DATA_MATCH = R"(((?:\".+?\")|(?:[^,]))(?:\,|$))";
  CSVDataType data{};
  string line;

  while (getline(file, line)) {
    list<string> matches = getRegexMatch(line, CSV_DATA_MATCH);
    CSVLineType lineData{};

    for (string match: matches) {
      if (match[0] == '"' && match[match.size() - 1] == '"') {
        match = unquote(match);
      }

      lineData.push_back(match);
    }

    data.push_back(lineData);
  }

  return data;
}
