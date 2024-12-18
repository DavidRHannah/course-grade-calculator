#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Course.h"
#include "CSVManager.h"

using std::string;
using std::vector;

class Quarter {
private:
    string m_name;
    vector<Course> m_courses;
public:
    Quarter(const string& name);
    void addCourse(const Course& course);

    void display() const;
}; 
