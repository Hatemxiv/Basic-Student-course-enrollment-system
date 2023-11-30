#pragma once
#include <iostream>
#pragma once
#include <string>
using namespace std;

class Course
{
private:
	string ID = " ", Name, Professor;
public:
	void setID(string i);
	void setName(string n);
	void setProfessor(string p);
	string getID();
	string getName();
	string getProfessor();

	Course();
};




