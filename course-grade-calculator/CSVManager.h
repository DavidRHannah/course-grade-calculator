#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
using std::stringstream;
using std::getline;
using std::cerr;
using std::cout;
using std::endl;

class CSVManager
{
public:
    static vector<vector<string>> readCSV(const string& filename);
    static void modifyData(vector<vector<string>>& csvData, unsigned int row, unsigned int col, string data);
    static void writeCSV(const string& filename, const vector<vector<string>>& data);
    static void displayCSV(const vector<vector<string>>& data);
};
