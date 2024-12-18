#include "Course.h"

Course::Course(const string& name)
{
	m_name = name;
}

bool Course::isGroup(const string& groupName) const
{
	if (m_groups.empty())
		return false;

	for (auto& group : m_groups)
		if (groupName == group.getName())
			return true;

	return false;
}

vector<Group> Course::getGroups() const
{
	return m_groups;
}

string Course::getName() const
{
	return m_name;
}

void Course::addGroup(const Group& group)
{
	m_groups.push_back(group);
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


