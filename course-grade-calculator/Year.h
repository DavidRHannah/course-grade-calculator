#pragma once
#include <vector>
#include <string>
#include "Quarter.h"

using std::string;
using std::vector;

class Year
{
private:
    string m_name;
    vector<Quarter> m_quarters;
public:
    Year(const string& yearName, const vector<Quarter>& quarters = {});
    Year();
    void addQuarter(const Quarter& quarter);
    Quarter* getQuarter(const string& name);
    string toCSV() const;
    void fromCSV(const string& filename);
    void display() const;
};
