#include "Group.h"

Group::Group(const string& name, double weight, const vector<Assignment>& assignments)
	: m_name(name), m_weight(weight), m_assignments(assignments)
{}

Group::Group() 
    : m_name(""), m_weight(0.0), m_assignments({})
{}

void Group::setName(const string & name)
{
    m_name = name;
}

void Group::setWeight(double weight)
{
    m_weight = weight;
}

void Group::addAssignment(const Assignment& assignment)
{
	m_assignments.push_back(assignment);
}

//string Group::getName() const
//{
//	return m_name;
//}
//float Group::getWeight() const
//{
//	return m_weight;
//}
//vector<Assignment> Group::getAssignments() const
//{
//	return m_assignments;
//}
//float Group::getGroupContribution() const
//{
//	float totalContribution = 0.0f;
//	float totalPointsEarned = 0.0f;
//	int totalPoints = 0;
//
//	for (auto& assignment : m_assignments)
//	{
//		totalPointsEarned += assignment.getPointsEarned();
//		totalPoints += assignment.getPointTotal();
//	}
//
//	return totalPoints > 0 ? (totalPointsEarned / totalPoints) * m_weight * 100 : 0;
//}
//float Group::getTotalEarnedPoints() const
//{
//	float totalEarnedPoints = 0.0f;
//	for (auto& assignment : m_assignments)
//		totalEarnedPoints += assignment.getPointsEarned();
//	return totalEarnedPoints;
//}
//int Group::getTotalPoints() const
//{
//	int totalPoints = 0;
//	for (auto& assignment : m_assignments)
//		totalPoints += assignment.getPointTotal();
//	return totalPoints;
//}

string Group::toCSV() const
{
    std::ostringstream oss;
    oss << "Group," << m_name << "\n";
    oss << "Weight," << m_weight << "\n";
    for (const auto& assignment : m_assignments)
    {
        oss << assignment.toCSV() << "\n";
    }

    return oss.str();
}

void Group::fromCSV(std::istream& stream)
{
    string line("");
    getline(stream, m_name);
    getline(stream, line);
    stream >> m_weight;
    stream.ignore();

    while (getline(stream, line) && !line.empty() && line[0] == ' ')
    {
        Assignment assignment;
        assignment.fromCSV(line.substr(2));
        m_assignments.push_back(assignment);
    }
}

void Group::display() const
{
    cout << "Group: " << m_name << "\n";
    cout << "Weight: " << m_weight << "\n";
    for (const auto& assignment : m_assignments)
    {
        assignment.display();
    }
}