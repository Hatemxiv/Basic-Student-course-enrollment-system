#pragma once
#include <string>
#include "Course.h"
using namespace std;

class Professor
{
	int cnt = 0;

private:
	string Name, List_of_courses;
	Course c[100];

public:
	void viewCourses();
	void viewmyCourses(string professor);

	Professor();
};
