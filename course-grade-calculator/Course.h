#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Group.h"
#include "CSVManager.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ostringstream;
using std::getline;

class Course
{
private:
    string m_name;
    vector<Group> m_groups;
public:
    Course(const string& name, const vector<Group>& groups = {});
    Course();
    vector<Group>* getGroups();
    void addGroup(const Group& group);
    string getName() const;
    void setName(const string& name);
    string toCSV() const;
    void fromCSV(std::istream& stream);
    void display() const;
    /*bool isGroup(const string& groupName) const;
    vector<Group>& getGroups();
    */
};
