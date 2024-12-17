#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Course.h"
#include "CSVManager.h"

class Quarter {
private:
    std::string m_name;
    std::vector<Course> m_courses;
public:
    Quarter(const std::string& name);
    void addCourse(const Course& course);
    void addEntry(const std::string& cName, const std::string& gName,
                  const std::string& weight, const std::string& aName,
                  const std::string& pe, const std::string& pt);
    void saveToCSV(const std::string& filename) const;
    void loadFromCSV(const std::string& filename);
    void display() const;
};
