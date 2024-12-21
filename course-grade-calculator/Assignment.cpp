#include "Assignment.h"

Assignment::Assignment(const string& name, double score, double maxScore)
    : m_name(name), m_pointsEarned(score), m_pointTotal(maxScore)
{}

Assignment::Assignment() : m_name(""), m_pointsEarned(0), m_pointTotal(0)
{}

string Assignment::getName()
{
    return m_name;
}

double Assignment::getPointsEarned()
{
    return m_pointsEarned;
}

double Assignment::getPointTotal()
{
    return m_pointTotal;
}

void Assignment::setName(const string & name)
{
    m_name = name;
}

void Assignment::setPointsEarned(double pe)
{
    m_pointsEarned = pe;
}

void Assignment::setPointTotal(double pt)
{
    m_pointTotal = pt;
}

string Assignment::toCSV() const
{
    std::ostringstream oss;
    oss << "\tAssignment," << m_name << "," << m_pointsEarned << "," << m_pointTotal;
    return oss.str();
}

void Assignment::fromCSV(const string& csvLine)
{
    std::istringstream iss(csvLine);
    
    std::string temp;
    std::getline(iss, temp, ',');

    std::getline(iss, m_name, ',');
    iss >> m_pointsEarned;
    iss.ignore();
    iss >> m_pointTotal;
}

void Assignment::display() const
{
    cout << "\t\t" << m_name << "\t" << m_pointsEarned
        << "/" << m_pointTotal << "\t(" << (m_pointsEarned / m_pointTotal) * 100.0 << "%)\n";

}