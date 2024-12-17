#include "Quarter.h"

Quarter::Quarter(const std::string & name) : m_name(name)
{}

void Quarter::addCourse(const Course& course)
{
    this->m_courses.push_back(course);
}

void Quarter::display() const
{
    std::cout << "Quarter: " << m_name << "\n";
    for (const auto& course : this->m_courses)
    {
        course.display();
    }
}

void Quarter::saveToCSV(const std::string& filename) const
{
    vector<vector<string>> data;

    static const vector<string> csvFormat = {
        "Quarter",
        "Course",
        "Group",
        "Assignment",
        "PointsEarned",
        "PointTotal"
    };

    data.push_back(csvFormat);
    for (const auto& course : m_courses)
    {
        vector<string> row;
        row.push_back(course.getName());
        data.push_back(row);

        for (const auto& group : course.getGroups())
        {
            row.clear();
            row.push_back(group.getName());
            row.push_back(std::to_string(group.getWeight()));
            data.push_back(row);

            for (const auto& assignment : group.getAssignments())
            {
                row.clear();
                row.push_back(assignment.getName());
                row.push_back(std::to_string(assignment.getPointsEarned()));
                row.push_back(std::to_string(assignment.getPointTotal()));
                data.push_back(row);
            }
        }
    }

    CSVManager::writeCSV(filename, data);

    std::cout << "Data saved successfully to " << filename << ".\n";
}

void Quarter::loadFromCSV(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filename << "\n";
        return;
    }

    this->m_courses.clear();
    std::string line, header;
    std::getline(file, header);
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string courseName, groupName, assignmentName;
        double pointsEarned, pointsTotal;
        addEntry(courseName, groupName, assignmentName, pointsEarned, pointsTotal);
    }

    file.close();
    std::cout << "Data loaded successfully from " << filename << ".\n";
}

void Quarter::loadFromCSV(const std::string& filename)
{
    vector<vector<string>> data = CSVManager::readCSV(filename);
    m_courses.clear();

    for (const auto& row : data)
    {
        std::string courseName, groupName, weight, assignmentName, pointsEarned, pointTotal;
    }
}

void Quarter::addEntry(const std::string& cName, const std::string& gName, 
                       const std::string& weight, const std::string& aName, 
                       const std::string& pe, const std::string& pt)
{
    Course* course = nullptr;
    for (auto& c : this->m_courses)
    {
        if (c.getName() == cName)
        {
            course = &c;
            break;
        }
    }
    if (!course)
    {
        Assignment newAssignment(aName, stof(pe), stoi(pt));
        Group newGroup(gName, stof(weight));
        newGroup.addAssignment(newAssignment);
        course->addGroup(newGroup);

        m_courses.emplace_back(cName);
        course = &m_courses.back();
    }

    Group* group = nullptr;
    for (auto& g : course->getGroups())
    {
        if (g.getName() == gName)
        {
            group = &g;
            return;
        }
    }
    if (!group)
    {
        course->addGroup(Group(gName, 0.0));
        group = &course->getGroups().back();
    }

    group->addAssignment(Assignment(aName, stod(pe), stod(pt)));
}