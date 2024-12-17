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
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filename << "\n";
        return;
    }

    file << "Quarter,Course,Group,Assignment,PointsEarned,PointTotal\n";
    //for (const auto& course : this->m_courses)
    //{
    //    course.toCSV(file, m_name); // Pass quarter name to Course
    //}

    file.close();
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
        std::string quarterName, courseName, groupName, assignmentName;
        double pointsEarned, pointsTotal;

        std::getline(ss, quarterName, ',');
        std::getline(ss, courseName, ',');
        std::getline(ss, groupName, ',');
        std::getline(ss, assignmentName, ',');
        ss >> pointsEarned;
        ss.ignore();
        ss >> pointsTotal;

        addEntry(courseName, groupName, assignmentName, pointsEarned, pointsTotal);
    }

    file.close();
    std::cout << "Data loaded successfully from " << filename << ".\n";
}

void Quarter::addEntry(const std::string& cName, const std::string& gName,
              const std::string& aName, double pe, double pt)
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
        this->m_courses.emplace_back(cName);
        course = &this->m_courses.back();
    }

    Group* group = nullptr;
    for (auto& g : course->getGroups())
    {
        if (g.getName() == gName)
        {
            group = &g;
            break;
        }
    }
    if (!group)
    {
        course->addGroup(Group(gName, 0.0));
        group = &course->getGroups().back();
    }

    group->addAssignment(Assignment(aName, pe, pt));
}