#include <iostream>
#include <fstream>
#include "Professor.h"
#include "Course.h"
using namespace std;

void Professor::viewCourses()
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

void Professor::viewmyCourses(string professor)
{
	fstream Myfile, myfile, C;
	Myfile.open("Prof.txt", ios::in);
	string line,line1;
	int i = 0,c=0;
	int chec[20]= {0};
	while (getline(Myfile, line))
	{
		if (line == professor)
		{
			chec[c] = i;
			
			c++;
		}
		i++;
	}
	Myfile.close();

	myfile.open("coursesid.txt",ios::in);
	C.open("Names.txt", ios::in);
	i = 0,c=0;
	while (getline(myfile, line)&&getline(C,line1))
	{
		if (i == chec[c])
		{

			cout << line<<"   "<<line1 << endl;
			c++;
		}

		i++;
	}

	myfile.close();



}

Professor::Professor()
{

}
