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
	// Constructors
	Course(const string& name);

	// Accessors
	bool isGroup(const string& groupName) const;

	// Mutators
	void addGroup(const string& name, float weight);
	void addGroup(const Group& group);
	void addAssignment(const string& groupName, const string& assignmentName, float pe, int pt);

	// Console Output
	void display() const;
	
	// File Methods
	void saveToFile(const string& filename) const;
	void loadFromFile(const string& filename);
};