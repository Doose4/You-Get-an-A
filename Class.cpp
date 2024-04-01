#include <iostream>
#include <string>
#include <vector>
#include "Class.hpp"

using namespace std;

//sets up Gradebook and titles
Gradebook::Gradebook(string gradebook_name) {
	name = gradebook_name;
	students.push_back(vector<string>());
	students[0].push_back("last_name");
	students[0].push_back("first_name");
	students[0].push_back("student_id");
	assignments.push_back("assignment_name");
	max_grades.push_back(100);
}

//adds student name
void Gradebook::add_name(string student_name, string student_id) {
	for (int i = 0; i < students.size(); i++)
	{
		string full_name = (students[i][1] + " " + students[i][0]);
		if (student_name == full_name) {
			cout << "Name is already used..." << endl;
			return;
		}
		if (student_id == students[i][2]) {
			cout << "Student ID already used..." << endl;
			return;
		}
	}

	int pos = student_name.find(" ");
	string first_name = student_name.substr(0, pos);
	string last_name = student_name.substr(pos+1, student_name.size());
	int i = students.size();


	students.push_back(vector<string>());
	students[i].push_back(last_name);
	students[i].push_back(first_name);
	students[i].push_back(student_id);

	for (int j = 3; j < students[0].size(); j++)
	{
		students[i].push_back("none");
	}
}

//adds an assignment and the max grade
void Gradebook::add_assignment(string assignment_name, int max_score) {
	for (int i = 0; i < assignments.size(); i++)
	{
		if (assignment_name == assignments[i])
		{
			cout << "Assignment name taken, please try agina." << endl;
		}
	}

	assignments.push_back(assignment_name);
	max_grades.push_back(max_score);
	students[0].push_back(assignment_name);
	for (int i = 1; i < students.size(); i++)
	{
		students[i].push_back("none");
	}
}

//pulls assignments location
int Gradebook::get_assignment(string assignment_name) {
	for (int i = 0; i < assignments.size(); i++)
	{
		if (assignment_name == assignments[i])
		{
			return i;
		}
	}
	return -1;
}

//pulls student location
int Gradebook::get_student_num(string student) {
	string full_name;

	for (int i = 0; i < students.size(); i++)
	{
		full_name = (students[i][1] + " " + students[i][0]);
		if (student == full_name) {
			return i;
		}
	}
	return -1;
}

//enters a grade for a student for an assignment
void Gradebook::enter_grade(string student, string assignment_name, int score) {
	int location = get_student_num(student);
	

	if (location == -1)
	{
		cout << "Student not found, try again. . ." << endl;
		return;
	}

	int assign_loc = get_assignment(assignment_name);

	if (assign_loc == -1)
	{
		cout << "Assignment not found, please try agian or add the assignment." << endl;
		return;
	}

	if (students[location][assign_loc + 2] != "none") {
		char YorN;
		cout << "This assignment already has a grade. Do you want to overwrite it (Yes or No)? ";
		cin >> YorN;
		if (toupper(YorN) == 'N') {
			return;
		}
	}

	students[location][assign_loc+2] = to_string(score);
}

//pulls student name from list
string Gradebook::get_name(int student_num) {
	return students[student_num][0] + ", " + students[student_num][1];
}

//pulls a students average grade for class.
float Gradebook::get_grade(string student) {
	float grade = 0;
	float mid = 0;
	int missing = 0;
	int student_num = get_student_num(student);

	for (int i = 3; i < students[student_num].size(); i++) {
		if (students[student_num][i] == "none") {
			missing++;
		}
		else {
			mid = grade + (stof(students[student_num][i]) / max_grades[i - 2]);
			grade = mid;
		}
	}

	mid = grade / (students[student_num].size() - (missing + 3));
	grade = mid * 100;

	return grade;
}

//lists all the grades for a student
string Gradebook::list_grades(string student) {
	int student_num = get_student_num(student);

	string listed_grades = students[student_num][3];

	for (int i = 4; i < students[student_num].size(); i++) {
		listed_grades = listed_grades + "," + students[student_num][i];
	}

	return listed_grades;
}

//prints out full report for class
string Gradebook::report() {
	int k = 1;
	int assign = assignments.size();
	string outputed;

	outputed = "Last_Name,First_Name,Student_Id";

	while (k < assign)
	{
		outputed = outputed + "," + assignments[k];
		k++;
	}
	outputed = outputed + "\n";

	for (int i = 1; i < students.size(); i++)
	{
		outputed = outputed + students[i][0];
		for (int j = 1; j < assign+2; j++)
		{
			outputed = outputed + "," + students[i][j];
		}
		outputed = outputed + "\n";
	}
	string final_output;

	final_output = outputed;

	return final_output;
}