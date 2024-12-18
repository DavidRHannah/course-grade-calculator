#include "Group.h"

Group::Group(const string& name, float weight)
{
	m_name = name;
	m_weight = weight;
}
void Group::addAssignment(const Assignment& assignment)
{
	m_assignments.push_back(assignment);
}
string Group::getName() const
{
	return m_name;
}
float Group::getWeight() const
{
	return m_weight;
}
vector<Assignment> Group::getAssignments() const
{
	return m_assignments;
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

	return totalPoints > 0 ? (totalPointsEarned / totalPoints) * m_weight * 100 : 0;
}
float Group::getTotalEarnedPoints() const
{
	float totalEarnedPoints = 0.0f;
	for (auto& assignment : m_assignments)
		totalEarnedPoints += assignment.getPointsEarned();
	return totalEarnedPoints;
}
int Group::getTotalPoints() const
{
	int totalPoints = 0;
	for (auto& assignment : m_assignments)
		totalPoints += assignment.getPointTotal();
	return totalPoints;
}
void Group::display() const
{
	cout << getName()
		<< ": "
		<< getWeight()
		<< " "
		<< getGroupContribution()
		<< " "
		<< getTotalEarnedPoints() << "/" << getTotalPoints()
		<< " "
		<< getGroupContribution() / (getWeight() * 100) * 100
		<< "%"
		<< endl;

	for (auto& assignment : m_assignments)
		assignment.display();

	cout << endl;
}
