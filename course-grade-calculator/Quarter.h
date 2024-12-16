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
    Quarter(const std::string& name) : m_name(name) {}

    void addCourse(const Course& course) {
        this->m_courses.push_back(course);
    }

    void display() const {
        std::cout << "Quarter: " << m_name << "\n";
        for (const auto& course : this->m_courses) {
            course.display();
        }
    }

    void saveToCSV(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << "\n";
            return;
        }

        file << "Quarter,Course,Group,Assignment,PointsEarned,PointTotal\n";
        for (const auto& course : this->m_courses) {
            course.toCSV(file, m_name); // Pass quarter name to Course
        }

        file.close();
        std::cout << "Data saved successfully to " << filename << ".\n";
    }

    void loadFromCSV(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << "\n";
            return;
        }

        this->m_courses.clear();
        std::string line, header;
        std::getline(file, header); 
        while (std::getline(file, line)) {
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

    void addEntry(const std::string& courseName, const std::string& groupName,
        const std::string& assignmentName, double pointsEarned, double pointsTotal) {
        Course* course = nullptr;
        for (auto& c : this->m_courses) {
            if (c.getName() == courseName) {
                course = &c;
                break;
            }
        }
        if (!course) {
            this->m_courses.emplace_back(courseName);
            course = &this->m_courses.back();
        }

        Group* group = nullptr;
        for (auto& g : course->getGroups()) {
            if (g.getName() == groupName) {
                group = &g;
                break;
            }
        }
        if (!group) {
            course->addGroup(Group(groupName, 0.0)); 
            group = &course->getGroups().back();
        }

        group->addAssignment(Assignment(assignmentName, pointsEarned, pointsTotal));
    }
};
