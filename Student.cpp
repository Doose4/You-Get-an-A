#include <iostream>
#include <string>
#include "Student.hpp"

using namespace std;

Student::Student(string name){
	size_t pos = name.find(" ");
	first_name = name.substr(0, pos);
	last_name = name.substr(pos, string::npos);
}

string Student::get_name() {
	return last_name + ", " + first_name;
}

float Student::get_grade() {
	float grade;
	int missing=0;

	for (int i = 0; i < grades.size(); i++) {
		if (grades[i] = -1) {
			missing++;
		} else {
			grade = grade + grades[i];
		}
	}

	grade = grade / (grades.size()-missing);

	return grade;
}

string Student::list_grades() {
	string listed_grades = to_string(grades[0]);

	for (int i = 1; i < grades.size(); i++) {
		if (grades[i] = -1) {
			listed_grades = listed_grades + ",none";
		}
		else {
			listed_grades = listed_grades + "," + to_string(grades[i]);
		}
	}

	return listed_grades;
}

void Student::set_grade(float grade, int location) {
	grades[location] = grade;
}