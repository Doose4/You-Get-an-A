#include <iostream>
#include <string>
#include <vector>

class Student {
private:
	string first_name;
	string last_name;
	vector <float> grades;
	float* grade_ptr = &grades[0];
public:
	explicit Student(string name);
	string get_name();
	float get_grade();
	string list_grades();
	void set_grade(float grade, int location);
};