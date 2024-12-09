#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;

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
};


int main() {
	std::cout << "CalcuBot!\n";

	// Test Data
	Course course("STAT155");
	
	course.addGroup("Quizzes", 0.15f);

	course.addAssignment("Quizzes", "CH 1 Quiz (terminology)", 95, 100);
	course.addAssignment("Quizzes", "CH 1 Quiz (visual descriptive statistics)", 93.33f, 100);
	course.addAssignment("Quizzes", "CH 2 Quiz (event terminology, notation, and relationships", 100, 100);
	course.addAssignment("Quizzes", "CH 2 Quiz (counting rules and probability", 100, 100);
	course.addAssignment("Quizzes", "CH 3 Quiz (discrete rvs)", 100, 100);
	course.addAssignment("Quizzes", "CH 4 Quiz (continuous rvs)", 94, 100);
	//course.addAssignment("Quizzes", "CH 4 Quiz (normal distribution)", 83.17f, 100); // Lowest score dropped
	course.addAssignment("Quizzes", "CH 5 Quiz (joint probability distributions)", 100, 100);
	course.addAssignment("Quizzes", "CH 5 Quiz (sampling distributions)", 92, 100);

	course.addGroup("Homework", 0.15f);

	course.addAssignment("Homework", "HW 1", 50, 50);
	course.addAssignment("Homework", "HW 2", 50, 50);
	//course.addAssignment("Homework", "HW 3", 49, 50); // Lowest score dropped
	course.addAssignment("Homework", "HW 4", 49.5, 50);
	course.addAssignment("Homework", "HW 5", 50, 50);

	course.addGroup("Attendance", 0.1f);
	course.addAssignment("Attendance", "TOTAL", 84, 90);

	course.addGroup("Exam 1", 0.3f);
	course.addAssignment("Exam 1", "Exam 1 Raw Score", 77, 94);
	course.addAssignment("Exam 1", "Exam 1 Practice Submission", 6, 6);
	
	course.addGroup("Exam 2", 0.3f);
	course.addAssignment("Exam 2", "Exam 2 Raw Score", 77, 94);
	course.addAssignment("Exam 2", "Exam 2 Practice Submission", 6, 6);

	course.display();

	return 0;
}
