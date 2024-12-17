#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Group.h"

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
public:
	Course(const string& name);

	bool isGroup(const string& groupName) const;
	vector<Group> getGroups() const;

	string getName() const;
	void addGroup(const string& name, float weight);
	void addGroup(const Group& group);
	void addAssignment(const string& groupName, const string& assignmentName, float pe, int pt);

	void display() const;
	
	string toCSV() const;
};