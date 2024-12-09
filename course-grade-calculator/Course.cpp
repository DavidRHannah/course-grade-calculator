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
		if (!line.empty())
		{
			groupRows.push_back(line);
		}
	}

	if (!groupRows.empty())
	{
		for (auto& row : groupRows)
		{
			vector<string> tokenizedRow;
			std::istringstream iss(row);
			string str;
			while (std::getline(iss, str, ','))
			{
				tokenizedRow.push_back(str);
			}

			string groupName = tokenizedRow[0];
			float weight = std::stof(tokenizedRow[1]);
			string assignmentName = tokenizedRow[2];
			float pe = std::stof(tokenizedRow[3]);
			int pt = std::stoi(tokenizedRow[4]);

			if (isGroup(groupName))
			{
				this->addAssignment(groupName, assignmentName, pe, pt);
			}
			else
			{
				this->addGroup(groupName, weight);
				this->addAssignment(groupName, assignmentName, pe, pt);
			}
		}
	}

	file.close();
}