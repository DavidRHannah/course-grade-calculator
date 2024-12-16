#include <iostream>
#include <vector>
#include "Menu.h"
#include "Course.h"
#include "Group.h"
#include "Assignment.h"

using std::cout;
using std::cin;
using std::endl;

// Define actions for the menu
void addData(Course& course) {
    std::string groupName, assignmentName;
    float weight, pointsEarned;
    int pointTotal;

    cout << "Enter group name: ";
    cin >> groupName;
    cout << "Enter group weight (0.0 to 1.0): ";
    cin >> weight;

    Group group(groupName, weight);
    cout << "Enter assignments for this group (type 'done' to finish):" << endl;

    while (true) {
        cout << "Assignment name (or 'done'): ";
        cin >> assignmentName;
        if (assignmentName == "done") break;
        cout << "Points earned: ";
        cin >> pointsEarned;
        cout << "Point total: ";
        cin >> pointTotal;

        group.addAssignment(Assignment(assignmentName, pointsEarned, pointTotal));
    }

    course.addGroup(group);
}

void displayData(Course& course) {
    course.display();
}

void saveData(Course& course) {
    course.saveToFile("course.csv");
    cout << "Data saved successfully.\n";
}

void loadData(Course& course) {
    course.loadFromFile("course.csv");
    cout << "Data loaded successfully.\n";
}

int main() {
    Course course("My Course");

    // Create menu labels and actions
    std::vector<std::string> labels = {
        "1. Add Data",
        "2. Display Data",
        "3. Save Data",
        "4. Load Data",
        "5. Exit"
    };

    std::vector<std::function<void()>> actions = {
        [&]() { addData(course); },     // Lambda to call addData
        [&]() { displayData(course); }, // Lambda to call displayData
        [&]() { saveData(course); },    // Lambda to call saveData
        [&]() { loadData(course); },    // Lambda to call loadData
        [&]() { exit(0); }              // Lambda to exit program
    };

    // Initialize and run the menu
    Menu menu(labels, actions);
    while (true) {
        menu.run();
        system("pause"); // Wait before redisplaying menu
    }

    return 0;
}
