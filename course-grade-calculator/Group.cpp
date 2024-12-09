#include "Group.h"

Group::Group(const string& name, float weight)
{
	this->m_name = name;
	this->m_weight = weight;
}
void Group::addAssignment(const string& name, float pe, int pt)
{
	m_assignments.push_back(Assignment(name, pe, pt));
}
void Group::addAssignment(const Assignment& assignment)
{
	m_assignments.push_back(assignment);
}
string Group::getName() const
{
	return this->m_name;
}
float Group::getWeight() const
{
	return this->m_weight;
}
vector<Assignment> Group::getAssignments() const
{
	return this->m_assignments;
}
float Group::getGroupContribution() const
{
	float totalContribution = 0.0f;

	float totalPointsEarned = 0.0f;
	int totalPoints = 0;

	for (auto& assignment : m_assignments)
	{
		totalPointsEarned += assignment.getPointsEarned();
		totalPoints += assignment.getPointTotal();
	}

	return totalPoints > 0 ? (totalPointsEarned / totalPoints) * this->m_weight * 100 : 0;
}
float Group::getTotalEarnedPoints() const
{
	float totalEarnedPoints = 0.0f;
	for (auto& assignment : this->m_assignments)
	{
		totalEarnedPoints += assignment.getPointsEarned();
	}
	return totalEarnedPoints;
}
int Group::getTotalPoints() const
{
	int totalPoints = 0;
	for (auto& assignment : this->m_assignments)
	{
		totalPoints += assignment.getPointTotal();
	}
	return totalPoints;
}
void Group::display() const
{
	cout << this->getName()
		<< ": "
		<< this->getWeight()
		<< " "
		<< this->getGroupContribution()
		<< " "
		<< this->getTotalEarnedPoints() << "/" << this->getTotalPoints()
		<< " "
		<< this->getGroupContribution() / (this->getWeight() * 100) * 100
		<< "%"
		<< endl;

	for (auto& assignment : this->m_assignments)
	{
		assignment.display();
	}
	cout << endl;
}
string Group::toCSV() const
{
	std::ostringstream oss;
	for (const auto& assignment : m_assignments)
	{
		oss << m_name << "," << m_weight << "," << assignment.toCSV() << "\n";
	}
	return oss.str();
}
