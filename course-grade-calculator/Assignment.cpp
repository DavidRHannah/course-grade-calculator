#include "Assignment.h"

Assignment::Assignment(const string& name, float pe, int pt)
{
	m_name = name;
	m_pointsEarned = pe;
	m_pointTotal = pt;
}
string Assignment::getName() const
{
	return m_name;
}
float Assignment::getPointsEarned() const
{
	return m_pointsEarned;
}
int Assignment::getPointTotal() const
{
	return m_pointTotal;
}
void Assignment::display() const
{
	cout << "\t"
		<< getName()
		<< ": "
		<< getPointsEarned()
		<< "/"
		<< getPointTotal()
		<< endl;
}