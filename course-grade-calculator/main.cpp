#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Course.h"
#include "Group.h"
#include "Assignment.h"
#include "Menu.h"

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
	Course course("My Course");
	unsigned int optionCount = 5;
	Menu menu(optionCount);
	int c = 0;
	int selected = 1;
	std::string inp;
	while (true) {
		c = 0;
		switch ((c = _getch())) {
		case KEY_UP:
			if (selected == 1)
				selected = optionCount;
			else
				selected--;
			menu.menu(selected);
			break;
		case KEY_DOWN:
			if (selected == optionCount)
				selected = 1;
			else
				selected += 1;
			menu.menu(selected);
			break;
		default: 
			break;
		}
	}

	return 0;
}
