#include "Course.h"

Course::Course(const string& name)
{
	this->m_name = name;
}

bool Course::isGroup(const string& groupName) const
{
	if (this->m_groups.empty())
	{
		return false;
	}

	for (auto& group : this->m_groups)
	{
		if (groupName == group.getName())
			return true;
	}

	return false;
}

vector<Group> Course::getGroups() const
{
	return this->m_groups;
}

void Course::addGroup(const string& name, float weight)
{
	m_groups.push_back(Group(name, weight));
}

void Course::addGroup(const Group& group)
{
	m_groups.push_back(group);
}

void Course::addAssignment(const string& groupName, const string& assignmentName, float pe, int pt)
{
	for (auto& group : this->m_groups)
	{
		if (group.getName() == groupName)
		{
			group.addAssignment(assignmentName, pe, pt);
		}
	}
}

void Course::display() const
{
	cout << endl;
	float grade = 0.0f;
	for (auto& group : this->m_groups)
	{
		group.display();
		grade += group.getGroupContribution();
	}
	cout << "Expected Grade: " << grade << endl;
	cout << endl;
}

string Course::toCSV() const
{
	std::ostringstream oss;
	for (const auto& group : this->m_groups)
		oss << this->m_name << "," << group.toCSV();
	return oss.str();
}

