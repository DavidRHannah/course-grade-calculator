#include "Quarter.h"

Quarter::Quarter(const string& name, const vector<Course>& courses)
    : m_name(name), m_courses(courses)
{}

Quarter::Quarter() : m_name(""), m_courses({})
{}

void Quarter::addCourse(const Course& course)
{
    m_courses.push_back(course);
}

vector<Course>* Quarter::getCourses() 
{
    return &m_courses;
}

string Quarter::getName() const
{
    return m_name;
}

void Quarter::setName(const string& name)
{
    m_name = name;
}

std::string Quarter::toCSV() const
{
    std::ostringstream oss;
    oss << "Quarter," << m_name << "\n";
    for (const auto& course : m_courses)
    {
        oss << course.toCSV();
    }
    return oss.str();
}

void Quarter::fromCSV(std::istream& stream)
{
    string line;
    getline(stream, line);
    m_name = line.substr(8);
    while (stream.peek() != EOF)
    {
        Course course;
        course.fromCSV(stream);
        m_courses.push_back(course);
    }
}

Course* Quarter::findOrCreateCourse(const std::string& name)
{
    for (Course& c : m_courses)
    {
        if (c.getName() == name)
            return &c;
    }
    m_courses.emplace_back(name);
    return &m_courses.back();
}

void Quarter::display() const
{
    cout << m_name << "\n";
    for (const auto& course : m_courses)
    {
        course.display();
    }
}