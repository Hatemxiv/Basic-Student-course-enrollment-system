#pragma once
#include "Course.h"
using namespace std;

class student {
private:
    Course StuC[5];
    string year;
    string ID;

    string Name;
    string courses;
public:
    string view_courses();
    void set_name(string name);
    void set_year(string yr);
    void set_id(string id);
    void register_course();
    void drop(string c_id);
    void view_Rcourses();
    string get_name();
    string get_id();
    string get_year();


};


