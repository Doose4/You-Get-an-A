#include <iostream>
#include "Class.hpp"

int main() {
	//runs a test through the program
	cout << "Test starting... " << endl;

	Gradebook css_122 = Gradebook("CSS_122");
	css_122.add_name("Bob Bobberson", "ABC123");
	css_122.add_name("Sam Sammerson", "DEF456");
	css_122.add_name("Jess Jesserson", "HIJ789");

	css_122.add_assignment("Quiz 1", 100);
	css_122.add_assignment("Lab 1", 50);

	css_122.enter_grade("Sam Sammerson", "Quiz 1", 95);
	css_122.enter_grade("Bob Bobberson", "Quiz 1", 85);
	css_122.enter_grade("Jess Jesserson", "Lab 1", 49);
	css_122.enter_grade("Jess Jesserson", "Quiz 1", 93);
	css_122.enter_grade("Bob Bobberson", "Lab 1", 0);

	cout << css_122.report() << endl;

	css_122.add_name("Jess Jesserson", "HIJ789");

	css_122.add_name("Jacob Jacoberson", "LMN024");
	css_122.enter_grade("Jacob Jacoberson", "Lab 1", 49);

	//Prints out to verify correct output
	cout << css_122.report() << endl;

	css_122.enter_grade("Bob Bobberson", "Test 1", 0);

	css_122.add_assignment("Test 1", 100);
	css_122.enter_grade("Bob Bobberson", "Test 1", 80);
	css_122.enter_grade("Sam Sammerson", "Test 1", 100);
	css_122.enter_grade("Bob Bobberson", "Test 1", 85);
	css_122.enter_grade("Jess Jesserson", "Test 1", 74);
	css_122.enter_grade("Jacob Jacoberson", "Test 1", 92.5);

	//Prints out to verify correct output
	cout << css_122.report() << endl;

	//prints average grade for a student
	cout << css_122.get_grade("Bob Bobberson") << "%" << endl;
	cout << css_122.get_grade("Sam Sammerson") << "%" << endl;

	//prints assignment information
	cout << css_122.assignment_info("Test 1") << endl;
	cout << css_122.assignment_info("Quiz 1") << endl;

	cout << "Test Finished!" << endl;

	return 0;
}