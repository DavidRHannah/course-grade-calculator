#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Assignment.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;

class Group
{
private:
	string m_name;
	float m_weight;
	vector<Assignment> m_assignments;
public:
	Group(const string& name, float weight);

	string getName() const;
	float getWeight() const;
	vector<Assignment> getAssignments() const;
	float getTotalEarnedPoints() const;
	int getTotalPoints() const;
	float getGroupContribution() const;
	
	void addAssignment(const string& name, float pe, int pt);
	void addAssignment(const Assignment& assignment);
	
	void display() const;
	
	string toCSV() const;
};