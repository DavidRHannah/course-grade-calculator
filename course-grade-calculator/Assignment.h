#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl; 
using std::ofstream; using std::ifstream;

class Assignment
{
private:
    string m_name;
    double m_pointsEarned;
    double m_pointTotal;
public:
    Assignment(const string& name, double score, double maxScore);
    Assignment(); 
    void setName(const string& name);
    void setPointsEarned(double pe);
    void setPointTotal(double pt);

    string toCSV() const;
    void fromCSV(const string& csvLine);
    void display() const;
};