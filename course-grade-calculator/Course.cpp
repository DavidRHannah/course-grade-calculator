#include "Course.h"

//bool Course::isGroup(const string& groupName) const
//{
//	if (m_groups.empty())
//		return false;
//
//	for (auto& group : m_groups)
//		if (groupName == group.getName())
//			return true;
//
//	return false;
//}

//vector<Group>& Course::getGroups()
//{
//	return m_groups;
//}

//string Course::getName() const
//{
//	return m_name;
//}

//void Course::addGroup(const Group& group)
//{
//	m_groups.push_back(group);
//}

Course::Course(const string& name, const vector<Group>& groups)
    : m_name(name), m_groups(groups)
{}

Course::Course()
    : m_name(""), m_groups({})
{}

vector<Group>* Course::getGroups()
{
    return &m_groups;
}

void Course::addGroup(const Group& group)
{
    m_groups.push_back(group);
}

string Course::getName() const
{
    return m_name;
}

void Course::setName(const string& name)
{
    m_name = name;
}

string Course::toCSV() const
{
    ostringstream oss;
    oss << "Course," << m_name << "\n";
    for (const auto& group : m_groups)
    {
        oss << group.toCSV();
    }
    return oss.str();
}

void Course::fromCSV(std::istream& stream)
{
    string line;
    getline(stream, line);
    m_name = line.substr(7);
    while (stream.peek() != EOF)
    {
        Group group;
        group.fromCSV(stream);
        m_groups.push_back(group);
    }
}

void Course::display() const
{
    std::cout << "Course: " << m_name << "\n";
    for (const auto& group : m_groups)
    {
        group.display();
    }
}