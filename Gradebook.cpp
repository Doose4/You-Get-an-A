#include <iostream>
#include "Gradebook.hpp"

using namespace std;

Gradebook::Gradebook(string gradebook_name) {
	name = gradebook_name;
}

void Gradebook::add_student(string name, string student_id) {

}

void Gradebook::add_assignment(string assignment_name, int max_score) {

}

void Gradebook::enter_grade(string student, string assignment_name, int score) {

}

string Gradebook::report() {
	int k = 0;
	int assign = assignments.size();
	string output = "Last_Name,First_Name,Student_Id";
	
	while (k<assign)
	{
		output = output + assignments[k];
		k++;
	}
	output = output + "\n";

	for (int i = 0; i < student_name.size(); i++)
	{
		int cel1 = (i * 2);
		int cel2 = (i * 2)+1;
		output = output + "\n" + student_name[cel1] +","+student_name[cel2]+"," + id[cel2] + ",";
		for (int j = 0; j < assign; j++)
		{

		}
	}

// Last_Name,First_Name,Student_Id,Quiz_1,Lab_1
// Bobberson,Bob,ABC123,85,0
// Jesserson,Jess,HIJ789,93,49
// Sammerson,Sam,DEF456,95,none
}

string Gradebook::assignment_report(string assignment_name) {

}