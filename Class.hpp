#include <iostream>
#include <string>
#include <vector>

using namespace std;

//sets class up
class Gradebook {
private:
	string name;
	vector<vector<string>> students;
	vector<string> assignments;
	vector<int> max_grades;

public:
	explicit Gradebook(string gradebook_name);
	void add_name(string student_name, string student_id);
	void add_assignment(string assignment_name, int max_score);
	int get_assignment(string assignment_name);
	int get_student_num(string student);
	void enter_grade(string student, string assignment_name, int score);
	string get_name(int student_num);
	float get_grade(string student);
	string list_grades(string student);
	string report();
	string assignment_info(string assignment_name);
};