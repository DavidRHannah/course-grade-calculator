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
    void setName(const string& name);
    void addQuarter(const Quarter& quarter);
    Quarter* getQuarter(const string& name);
    string toCSV();
    void fromCSV(const string& filename);
    Quarter* findOrCreateQuarter(const std::string& name);
    void display() const;
};
