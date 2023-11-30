#include "Admin.h"
#include <fstream>
#include <string>



void Admin::setCourse(string id, string name, string professor)
{
	c[cnt].setID(id);
	c[cnt].setName(name);
	c[cnt].setProfessor(professor);
	cnt++;
}

Course Admin::getCourse(int index)
{
	return c[index];
}

void Admin::displayCourses()
{
	fstream Myfile;
	Myfile.open("Courses.txt", ios::in);
		string line;

		cout << "Old Courses: \n";

		while (getline(Myfile, line))
		{

			cout << line << endl;
		}
		Myfile.close();
		cout << "New courses: \n";
	for (int j = 0; j < cnt; j++)
		cout << "Course number " << j + 1 << " name is: " << c[j].getName() << " and its id is: " << c[j].getID() << " and the Dr who is teaching the course is Dr: " << c[j].getProfessor() << endl;

}

void Admin::writeCourses()
{
	fstream Tot, CID,prof,cour;
	CID.open("Coursesid.txt", ios::app);
	Tot.open("Courses.txt", ios::app); //append
	cour.open("Names.txt", ios::app);
	prof.open("prof.txt", ios::app);


	for (int i = 0; i < cnt; i++)
	{
		CID << c[i].getID() << endl;
		Tot<< c[i].getID() << "          " << c[i].getName() << "              " << c[i].getProfessor() << endl;
		prof << c[i].getProfessor() << endl;
		cour << c[i].getName() << endl;

	}
	Tot.close();
	CID.close();
	cour.close();
	prof.close();
}

void Admin::readCourses()
{
	fstream MyFile;
	MyFile.open("Courses.txt", ios::in); //read
	string line;
	while (getline(MyFile, line))
	{
		cout << line << endl;
	}
	MyFile.close();
}

Admin::Admin()
{

}
