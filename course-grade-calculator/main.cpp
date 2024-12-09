#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;

class Assignment {
	private:
		int m_id;
		string m_name;
		float m_pointsEarned;
		int m_pointTotal;
	public:
		Assignment(const string& name, float pe, int pt) {
			this->m_name = name;
			this->m_pointsEarned = pe;
			this->m_pointTotal = pt;
		}
		string getName() const {
			return this->m_name;
		}
		float getPointsEarned() const {
			return this->m_pointsEarned;
		}
		int getPointTotal() const {
			return this->m_pointTotal;
		}
		void display() const {
			cout << "\t"
				<< this->getName()
				<< ": "
				<< this->getPointsEarned()
				<< "/"
				<< this->getPointTotal()
				<< endl;
		}
		string toCSV() const {
			std::ostringstream oss;
			oss << m_name << "," << m_pointsEarned << "," << m_pointTotal;
			return oss.str();
		}

		inline static Assignment fromCSV(const string& csv) {
			std::istringstream iss(csv);
			string name;
			float pe;
			int pt;
			std::getline(iss, name, ',');
			std::getline(iss, name, ',');
			std::getline(iss, name, ',');
			iss >> pe;
			iss.ignore(1, ',');
			iss >> pt;

			return Assignment(name, pe, pt);
		}
};

class Group {
	private:
		int m_id;
		string m_name;
		float m_weight;
		vector<Assignment> m_assignments;
	public:
		Group(const string& name, float weight) {
			this->m_name = name;
			this->m_weight = weight;
		}
		void addAssignment(const string& name, float pe, int pt) {
			m_assignments.push_back(Assignment(name, pe, pt));
		}
		void addAssignment(const Assignment& assignment) {
			m_assignments.push_back(assignment);
		}
		string getName() const {
			return this->m_name;
		}
		float getWeight() const {
			return this->m_weight;
		}
		vector<Assignment> getAssignments() const {
			return this->m_assignments;
		}
		float getGroupContribution() const {
			float totalContribution = 0.0f;

			float totalPointsEarned = 0.0f;
			int totalPoints = 0;

			for (auto& assignment : m_assignments) {
				totalPointsEarned += assignment.getPointsEarned();
				totalPoints += assignment.getPointTotal();
			}

			return totalPoints > 0 ? (totalPointsEarned / totalPoints) * this->m_weight * 100 : 0;
		}
		float getTotalEarnedPoints() const {
			float totalEarnedPoints = 0.0f;
			for (auto& assignment : this->m_assignments) {
				totalEarnedPoints += assignment.getPointsEarned();
			}
			return totalEarnedPoints;
		}
		int getTotalPoints() const {
			int totalPoints = 0;
			for (auto& assignment : this->m_assignments) {
				totalPoints += assignment.getPointTotal();
			}
			return totalPoints;
		}
		void display() const {
			cout << this->getName()
				<< ": "
				<< this->getWeight()
				<< " "
				<< this->getGroupContribution()
				<< " "
				<< this->getTotalEarnedPoints() << "/" << this->getTotalPoints()
				<< " "
				<< this->getGroupContribution() / (this->getWeight() * 100) * 100
				<< "%"
				<< endl;

			for (auto& assignment : this->m_assignments) {
				assignment.display();
			}
			cout << endl;
		}
		string toCSV() const {
			std::ostringstream oss;
			for (const auto& assignment : m_assignments) {
				oss << m_name << "," << m_weight << "," << assignment.toCSV() << "\n";
			}
			return oss.str();
		}

		inline static Group fromCSV(const vector<string>& csvRows) {
			if (csvRows.empty()) return Group("", 0);

			std::istringstream iss(csvRows[0]);
			string groupName;
			float weight;
			std::getline(iss, groupName, ',');
			iss >> weight;
			iss.ignore(1, ',');

			Group group(groupName, weight);

			for (const auto& row : csvRows) {;
				group.addAssignment(Assignment::fromCSV(row));
			}

			return group;
		}
};

class Course {
	private:
		string m_name;
		vector<Group> m_groups;
	public:
		Course(const string& name) {
			this->m_name = name;
		}
		void addGroup(const string& name, float weight) {
			m_groups.push_back(Group(name, weight));
		}
		void addGroup(const Group& group) { 
			m_groups.push_back(group); 
		}
		void addAssignment(const string& groupName, const string& assignmentName, float pe, int pt) {
			for (auto& group : this->m_groups) {
				if (group.getName() == groupName) {
					group.addAssignment(assignmentName, pe, pt);
				}
			}
		}
		void display() const {
			cout << endl;
			float totalPointsEarned = 0.0f;
			int totalPoints = 0;
			for (auto& group : this->m_groups) {	
				group.display();
				totalPointsEarned += group.getTotalEarnedPoints();
				totalPoints += group.getTotalPoints();
			}
			cout << "Expected Grade: " << (totalPointsEarned / totalPoints) * 100.0f << endl;
			cout << endl;
		}
		void saveToFile(const string& filename) const {
			ofstream file(filename);
			if (!file) {
				cout << "Error opening file for writing." << endl;
				return;
			}

			for (const auto& group : m_groups) {
				file << group.toCSV();
			}

			file.close();
		}

		void loadFromFile(const string& filename) {
			ifstream file(filename);
			if (!file) {
				cout << "Error opening file for reading." << endl;
				return;
			}

			m_groups.clear();
			string line;
			vector<string> groupRows;

			while (std::getline(file, line)) {
				if (!line.empty() && line.find(",") != string::npos) {
					groupRows.push_back(line);
				}
				else if (!groupRows.empty()) {
					m_groups.push_back(Group::fromCSV(groupRows));
					groupRows.clear();
				}
			}

			if (!groupRows.empty()) {
				m_groups.push_back(Group::fromCSV(groupRows));
			}

			file.close();
		}
};

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
			bool continueAddDataInput = true;
			string groupName = "";
			while (continueAddDataInput) {
				
			}
			/*addData(course);*/
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
