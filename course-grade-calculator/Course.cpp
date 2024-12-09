#include "Course.h"

Course::Course(const string& name)
{
	this->m_name = name;
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
	float totalPointsEarned = 0.0f;
	int totalPoints = 0;
	for (auto& group : this->m_groups)
	{
		group.display();
		totalPointsEarned += group.getTotalEarnedPoints();
		totalPoints += group.getTotalPoints();
	}
	cout << "Expected Grade: " << (totalPointsEarned / totalPoints) * 100.0f << endl;
	cout << endl;
}

void Course::saveToFile(const string& filename) const
{
	ofstream file(filename);
	if (!file)
	{
		cout << "Error opening file for writing." << endl;
		return;
	}

	for (const auto& group : m_groups)
	{
		file << group.toCSV();
	}

	file.close();
}

void Course::loadFromFile(const string& filename)
{
	ifstream file(filename);
	if (!file)
	{
		cout << "Error opening file for reading." << endl;
		return;
	}

	m_groups.clear();
	string line;
	vector<string> groupRows;

	while (std::getline(file, line))
	{
		if (!line.empty() && line.find(",") != string::npos)
		{
			groupRows.push_back(line);
		}
		else if (!groupRows.empty())
		{
			m_groups.push_back(Group::fromCSV(groupRows));
			groupRows.clear();
		}
	}

	if (!groupRows.empty())
	{
		m_groups.push_back(Group::fromCSV(groupRows));
	}

	file.close();
}