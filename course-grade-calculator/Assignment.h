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
	Assignment(const string& name, float pe, int pt);
	
	string getName() const;
	float getPointsEarned() const;
	int getPointTotal() const;

	void display() const;

	string toCSV() const;
};