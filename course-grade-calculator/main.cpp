#include <iostream>
#include <vector>
#include "Menu.h"
#include "Year.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

static void addQuarter(Year& year, const string& quarterName)
{
    Quarter newQuarter(quarterName);
    year.addQuarter(newQuarter);
    std::cout << "Quarter '" << quarterName << "' added.\n";
}

static void addCourseToQuarter(Year& year, const string& quarterName, const Course& course)
{
    Quarter* quarter = year.getQuarter(quarterName);
    if (quarter)
    {
        quarter->addCourse(course);
        std::cout << "Course '" << course.getName() << "' added to Quarter '" << quarterName << "'.\n";
    }
    else
    {
        std::cerr << "Quarter '" << quarterName << "' not found.\n";
    }
}


static void displayData(Quarter& q) {
    q.display();
}

static void saveData(Quarter& q) {
    
    cout << "Data saved successfully.\n";
} 

static void loadData(Quarter& q) {
    cout << "Data loaded successfully.\n";
}

static void saveToFile(const Year& year, const std::string& filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        file << year.toCSV();
        file.close();
        std::cout << "Data saved to " << filename << "\n";
    }
    else
    {
        std::cerr << "Error opening file for writing.\n";
    }
}

static Year loadFromFile(const std::string& filename)
{    
    Year year;
    year.fromCSV(filename);
    cout << "Data loaded from " << filename << "\n";
    return year;
}


int main() {
    //Year year("2024");

    //// Add a quarter
    //addQuarter(year, "Fall 2024");

    //// Add a course to the quarter
    //Course cppCourse("C++ Programming");

    //Group cppGroupHw("Homework", 0.25);

    //Assignment cppAssHw_a("HW 1", 8, 10);
    //Assignment cppAssHw_b("HW 2", 9, 10);
    //Assignment cppAssHw_c("HW 3", 7, 10);

    //cppGroupHw.addAssignment(cppAssHw_a);
    //cppGroupHw.addAssignment(cppAssHw_b);
    //cppGroupHw.addAssignment(cppAssHw_c);

    //Group cppGroupQ("Quiz", 0.25);

    //Assignment cppAssQ_a("Quiz 1", 4.2, 5);
    //Assignment cppAssQ_b("Quiz 2", 16, 16);
    //Assignment cppAssQ_c("Quiz 3", 6, 6);

    //cppGroupQ.addAssignment(cppAssQ_a);
    //cppGroupQ.addAssignment(cppAssQ_b);
    //cppGroupQ.addAssignment(cppAssQ_c);

    //Group cppGroupF("Final", 0.5);
    //Assignment cppFinal("Final", 82.2, 100);
    //cppGroupF.addAssignment(cppFinal);

    //cppCourse.addGroup(cppGroupHw);
    //cppCourse.addGroup(cppGroupQ);
    //cppCourse.addGroup(cppGroupF);


    //addCourseToQuarter(year, "Fall 2024", cppCourse);

    //saveToFile(year, "grades.csv");

    Year loadedYear = loadFromFile("grades.csv");

    loadedYear.display();


    /*std::vector<std::string> labels = {
        "1. Add Course Data",
        "2. Display Data",
        "3. Save Data",
        "4. Load Data",
        "5. Exit",
    };
    std::vector<std::function<void()>> actions = {
        [&]() { addCourseData(q); },
        [&]() { displayData(q); },
        [&]() { saveData(q); },
        [&]() { loadData(q); },
        [&]() { exit(0); },
    };
    Menu menu(labels, actions);*/
    /*auto data = CSVManager::readCSV("course.csv");
    CSVManager::displayCSV(data);*/
    /*while (true) 
    {
        menu.run(); 
        system("pause");
    }*/

    return 0;
}
