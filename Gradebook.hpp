#include <iostream>
#include <vector>
#include <string>
#include "Student.hpp"

class Gradebook {
private:
	string name;
	vector<string> student_name;
	vector<string> assignments;
	vector<int> max_grades;

public:
	explicit Gradebook(string gradebook_name);
	void add_student(string name, string student_id);
	void add_assignment(string assignment_name, int max_score);
	void enter_grade(string student, string assignment_name, int score);
	string report();
	string assignment_report(string assignment_name);
};