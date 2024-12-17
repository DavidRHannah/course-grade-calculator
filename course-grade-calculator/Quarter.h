#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Course.h"

class Quarter {
private:
    std::string m_name;
    std::vector<Course> m_courses;
public:
    Quarter(const std::string& name);
    void addCourse(const Course& course);
    void addEntry(const std::string& courseName, const std::string& groupName,
                  const std::string& assignmentName, double pointsEarned, double pointsTotal);
    void saveToCSV(const std::string& filename) const;
    void loadFromCSV(const std::string& filename);
    void display() const;
};
