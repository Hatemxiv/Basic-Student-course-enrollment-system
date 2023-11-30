#include <iostream>
#include <fstream>
#include <string>
#include "Admin.h"
#include "Course.h"
#include "student.h"
#include "Professor.h"
using namespace std;

int main()
{
	Admin ad1;
	student st1;
	Professor pr1;

	int x, y = 1;
	string id, name, professor, year;
	// choosing

	while (y != 0)
	{
		cout << endl;
		cout << "Who would you like to log in as?" << endl;
		cout << "1. Admin." << endl;
		cout << "2. Student" << endl;
		cout << "3. Professor." << endl;
		cout << "Your choice: ";
		cin >> x;

		//Admin

		if (x == 1)
		{
			char choice = 'y';

			while (choice == 'y')
			{
				cout << endl;
				cout << "What would you like to do?" << endl;
				cout << "1. Add a new course." << endl;
				cout << "2. View all available courses." << endl;
				cout << "3. Write courses list to a file." << endl;
				cout << "0. Exit." << endl;
				cout << "Your choice: ";
				cin >> y;
				// declare 
				if (y == 1)
				{
					cout << endl;
					cout << "Enter course ID: ";
					getline(cin >> ws, id);
					cout << "Enter course name: ";
					getline(cin >> ws, name);
					cout << "Enter course instructor: ";
					getline(cin >> ws, professor);
					ad1.setCourse(id, name, professor);
					cout << "The course was saved successfully." << endl << endl;
				}
				//show
				else if (y == 2)
				{
					cout << endl;
					cout << "All the available courses: " << endl;
					ad1.displayCourses();
				}
				//write
				else if (y == 3)
				{
					cout << endl;
					ad1.writeCourses();
					cout << "All the courses were saved in the Courses.txt file" << endl;
				}

				else if (y == 0)
				{
					break;
				}

				else
				{
					cout << "Please enter a valid choice.";
					break;
				}

				cout << endl;
				cout << "Do u want something else? y/n ";
				cin >> choice;
			}
		}

		//Student

		else if (x == 2)
		{
			cout << "\nYour name: ";
			cin >> name;
			st1.set_name(name);
			cout << "Your id: ";
			cin >> id;
			st1.set_id(id);

			cout << "Your year: ";
			cin >> year;

			st1.set_year(year);

			char choice = 'y';

			while (choice == 'y')
			{


				cout << "\nDo you want to:\n1-View all available courses\n2-Register in a course by id\n3-Drop a course by id\n4-View all registered courses\n0-Exit ";
				cin >> y;

				if (y == 1)
				{
					string line;
					fstream myfile;
					myfile.open("Courses.txt", ios::in);

					while (getline(myfile, line))
					{
						cout << line << "\n";
					}
					myfile.close();

				}

				else if (y == 2)
				{
					st1.register_course();
				}

				else if (y == 3)
				{
					string coursetobedroped;
					cout << "Enter its ID please: ";
					cin.ignore();
					getline(cin, coursetobedroped);
					st1.drop(coursetobedroped);
				}

				else if (y == 4)
				{
					st1.view_Rcourses();
				}

				else if (y == 0)
				{
					break;
				}

				else
				{
					cout << "Please enter a valid choice.";
					break;
				}

				cout << "Do u want something else? y/n ";
				cin >> choice;

			}
		}

		//Professor

		else if (x == 3)
		{
			char choice = 'y';

			while (choice == 'y')
			{
				cout << endl;
				cout << "What would you like to do?" << endl;
				cout << "1. View all available courses." << endl;
				cout << "2. View all your courses." << endl;
				cout << "0. Exit." << endl;
				cout << "Your choice: ";
				cin >> y;

				if (y == 1)
				{
					cout << "All the available courses: " << endl;
					pr1.viewCourses();
				}

				else if (y == 2)
				{
					cout << "Please enter your name: ";
					cin >> professor;
					cout << "All your courses: " << endl;
					pr1.viewmyCourses(professor);
				}

				else if (y == 0)
				{
					break;
				}

				else
				{
					cout << "Please enter a valid choice.";
					break;
				}

				cout << endl;
				cout << "Do u want something else? y/n ";
				cin >> choice;
			}
		}

		else
		{
			cout << "Please enter a valid choice." << endl << endl;
		}
	}
	cout << "You logged out successfully." << endl;
	return 0;
}

