#include "Year.h"

Year::Year(const string& yearName, const vector<Quarter>& quarters)
    : m_name(yearName), m_quarters(quarters)
{}

Year::Year()
    : m_name(" "), m_quarters({})
{}

void Year::addQuarter(const Quarter& quarter)
{
    m_quarters.push_back(quarter);
}

Quarter* Year::getQuarter(const std::string& name)
{
    for (auto& quarter : m_quarters)
    {
        if (quarter.getName() == name)
        {
            return &quarter;
        }
    }
    return nullptr;
}

string Year::toCSV() const
{
    std::ostringstream oss;
    oss << "Year," << m_name << "\n";
    for (const auto& quarter : m_quarters)
    {
        oss << quarter.toCSV();
    }
    return oss.str();
}

void Year::fromCSV(const std::string& filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            if (line.rfind("Year,", 0) == 0)
            {
                continue;
            }
            else if (line.rfind("Quarter,", 0) == 0)
            {
                Quarter quarter;
                quarter.setName(line.substr(8));
                m_quarters.push_back(quarter);
            }
            else if (line.rfind("Course,", 0) == 0)
            {
                Course course;
                course.setName(line.substr(7));
                
                m_quarters.back().addCourse(course);
            }
            else if (line.rfind("Group,", 0) == 0)
            {
                Group group;
                group.setName(line.substr(6));

                m_quarters.back()
                    .getCourses()->back()
                    .addGroup(group);
            }
            else if (line.rfind("Weight,", 0) == 0)
            {
                double weight = 0.0;
                weight = stod(line.substr(7));

                m_quarters.back()
                    .getCourses()->back()
                    .getGroups()->back()
                    .setWeight(weight);
            }
            else if (line.rfind("Assignment,", 0) == 0)
            {
                Assignment a;
                string csvData = line.substr(11);

                vector<string> tokens;
                stringstream ss(csvData);
                string token;
                while (getline(ss, token, ','))
                {
                    tokens.push_back(token);
                }

                string name = tokens[0];
                double pe = stod(tokens[1]);
                double pt = stod(tokens[2]);

                a.setName(name);
                a.setPointsEarned(pe);
                a.setPointTotal(pt);

                m_quarters.back()
                    .getCourses()->back()
                    .getGroups()->back()
                    .addAssignment(a);
            }
        }
    }
}

void Year::display() const
{
    for (const auto& quarter : m_quarters)
    {
        quarter.display();
    }
}