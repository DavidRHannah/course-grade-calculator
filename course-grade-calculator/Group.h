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
	// Constructors
	Group(const string& name, float weight);
	
	// Accessors
	string getName() const;
	float getWeight() const;
	vector<Assignment> getAssignments() const;
	float getTotalEarnedPoints() const;
	int getTotalPoints() const;
	float getGroupContribution() const;
	
	// Mutators
	void addAssignment(const string& name, float pe, int pt);
	void addAssignment(const Assignment& assignment);
	
	// Console Output
	void display() const;
	
	// File Methods
	string toCSV() const;
	inline static Group fromCSV(const vector<string>& csvRows)
	{
		if (csvRows.empty()) return Group("", 0);

		std::istringstream iss(csvRows[0]);
		string groupName;
		float weight;
		std::getline(iss, groupName, ',');
		iss >> weight;
		iss.ignore(1, ',');

		Group group(groupName, weight);

		for (const auto& row : csvRows)
		{
			;
			group.addAssignment(Assignment::fromCSV(row));
		}

		return group;
	}
};