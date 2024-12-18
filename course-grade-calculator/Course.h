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

class Course
{
private:
	string m_name;
	vector<Group> m_groups;
	bool isGroup(const string& groupName) const;
public:
	Course(const string& name);
	vector<Group> getGroups() const;
	string getName() const;
	void addGroup(const Group& group);
	void display() const;
};