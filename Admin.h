#pragma once
#include <iostream>
#include <string>
#include "Course.h"
using namespace std;

class Admin
{
	int cnt = 0;

private:
	string Name;
	Course c[100];

public:
	void setCourse(string id, string name, string professor);
	Course getCourse(int index);
	void displayCourses();
	void writeCourses();
	void readCourses();

	Admin();
};

