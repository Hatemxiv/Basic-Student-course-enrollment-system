#include "Course.h"
#include <fstream>
#include <iostream>
using namespace std;

void Course::setID(string i)
{
	ID = i;
}

void Course::setName(string n)
{
	Name = n;
}

void Course::setProfessor(string p)
{
	Professor = p;
	

}

string Course::getID()
{
	return ID;
}

string Course::getName()
{
	return Name;
}

string Course::getProfessor()
{
	return Professor;
}

Course::Course()
{

}
