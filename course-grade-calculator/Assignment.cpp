#include "Assignment.h"

Assignment::Assignment(const string& name, float pe, int pt)
{
	this->m_name = name;
	this->m_pointsEarned = pe;
	this->m_pointTotal = pt;
}
string Assignment::getName() const
{
	return this->m_name;
}
float Assignment::getPointsEarned() const
{
	return this->m_pointsEarned;
}
int Assignment::getPointTotal() const
{
	return this->m_pointTotal;
}
void Assignment::display() const
{
	cout << "\t"
		<< this->getName()
		<< ": "
		<< this->getPointsEarned()
		<< "/"
		<< this->getPointTotal()
		<< endl;
}
string Assignment::toCSV() const
{
	std::ostringstream oss;
	oss << m_name << "," << m_pointsEarned << "," << m_pointTotal;
	return oss.str();
}
