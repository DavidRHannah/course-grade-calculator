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
