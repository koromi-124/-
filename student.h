#ifndef STUDENT_H
#define STUDENT_H

#include "course.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Course;

class Student {
private:
    string id;
    string name;
    vector<Course*> enrolledCourses;

public:
    Student(string id, string name) : id(id), name(name) {}

    string getId() const { return id; }
    string getName() const { return name; }

    void enroll(Course* course);
    void drop(Course* course);
    void printCourses() const;
};

#endif // !STUDENT_H

