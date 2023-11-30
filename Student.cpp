#include "student.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int NuCo;

void student::set_name(string name)
{
    Name = name;
}
void student::set_id(string id)
{
    ID = id;
}
void student::set_year(string yr)
{
    year = yr;

}

string student::get_name()
{

    return Name;

}
string student::get_id()
{

    return ID;
}
string student::get_year() {

    return year;
}



void student::register_course() {

    string n;

    cout << "\nHow many? Max 5: ";
    cin >> NuCo;


    for (int i = 0; i < NuCo; i++)
    {
        int semi = 0;

        //while (semi==0)
        //{


        cout << "enter the course id: \n";
        if (i == 0)
            cin.ignore();
        getline(cin, n);


        fstream MyFile;
        MyFile.open("Coursesid.txt", ios::in);
        string line;
        while (getline(MyFile, line))
        {
            if (n == line)
            {
                semi = 1;
                break;

            }
        }

        if (semi == 0)
        {
            cout << "invalid ID\n";
        }
        else {
            StuC[i].setID(n);

        }


        
        MyFile.close();
    }

}



void student::drop(string c_id)
{
    for (int i = 0; i < NuCo; i++)
    {
        if (StuC[i].getID() == c_id)
        {
            string emptty = " ";
            StuC[i].setID(emptty);
        }
    }

}


void student::view_Rcourses()
{
    fstream studentfile, outfile;
    string line, line1;

    outfile.open(get_name() + ".txt");
    while (getline(outfile, line1))
    {
        cout << line1 << endl;
    }



    for (int i = 0; i < NuCo; i++)
    {
        if (StuC[i].getID().compare(" ") != 0)
        {
            cout << StuC[i].getID() << endl;
        }

    }
    cout << " Do you want to save them in text? y/n ";
    char x;
    cin >> x;

    studentfile.open(get_name() + ".txt", ios::app); //
    if (x == 'y') {

        for (int i = 0; i < NuCo; i++)

        {
            if (StuC[i].getID() != " ")
            {
                studentfile << StuC[i].getID() << endl;
            }

        }

    }


    else if (x == 'n')
    {
        cout << "\n";
    }

    else {

        cout << "invalid Input, won't save them\n ";
    }
    studentfile.close();

}


