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
    double m_weight;
    vector<Assignment> m_assignments;
public:
    Group(const string& name, double weight, const vector<Assignment>& assignments = {});
    Group();
    string getName() const;
    double getWeight() const;
    void setName(const string& name);
    void setWeight(double weight);
    vector<Assignment>* getAssignments();
    void addAssignment(const Assignment& assignment);
    string toCSV() const;
    void fromCSV(std::istream& stream);
    void display() const;
    /*string getName() const;
    double getWeight() const;
    vector<Assignment> getAssignments() const;
    double getTotalEarnedPoints() const;
    double getTotalPoints() const;
    double getGroupContribution() const;*/
};