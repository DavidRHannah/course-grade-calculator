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

class Quarter
{
private:
    string m_name;
    vector<Course> m_courses;
public:
    Quarter(const std::string& name, const vector<Course>& courses = {});
    Quarter();
    void addCourse(const Course& course);
    vector<Course>* getCourses();
    string getName() const;
    void setName(const string& name);
    string toCSV() const;
    void fromCSV(std::istream& stream);
    void display() const;
    Course* findOrCreateCourse(const std::string& name);
};