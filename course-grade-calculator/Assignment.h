#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;

class Assignment
{
private:
	string m_name;
	float m_pointsEarned;
	int m_pointTotal;
public:
	// Constructors
	Assignment(const string& name, float pe, int pt);
	
	// Accessors
	string getName() const;
	float getPointsEarned() const;
	int getPointTotal() const;

	// Mutators

	// Console Output
	void display() const;

	// File Methods
	string toCSV() const;
};