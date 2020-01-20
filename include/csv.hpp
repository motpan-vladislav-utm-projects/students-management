//
// Created by VladPC on 19/01/2020.
//

#include <list>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

using CSVWriteData = list<string>;
using CSVLineType = vector<string>;
using CSVDataType = list<CSVLineType>;

void saveAsCSV(list<string> data, ofstream &file);
CSVDataType readFromCSV(ifstream &file);
