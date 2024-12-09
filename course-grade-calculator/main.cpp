#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Course.h"
#include "Group.h"
#include "Assignment.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;

void addData(Course& course) {
	string groupName, assignmentName;
	float weight, pointsEarned;
	int pointTotal;

	cout << "Enter group name: ";
	cin >> groupName;
	cout << "Enter group weight (0.0 to 1.0): ";
	cin >> weight;

	Group group(groupName, weight);
	cout << "Enter assignments for this group (type 'done' to finish):" << endl;

	while (1) {
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

int main() {
	std::cout << "CalcuBot!\n";

	Course course("My Course");
	int choice;

	while (true) {
		cout << "1. Add Data\n2. Display\n3. Save\n4. Load\n5. Exit\nChoice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			addData(course);
			break;
		case 2:
			course.display();
			break;
		case 3:
			course.saveToFile("course.csv");
			break;
		case 4:
			course.loadFromFile("course.csv");
			break;
		case 5:
			return 0;
		default:
			cout << "Invalid choice." << endl;
		}
	}
	return 0;
}
