#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    int age;
    string className;
    string contact;

public:
    Student();
    Student(int, string, int, string, string);

    int getId() const;
    string getName() const;

    void display() const;
    string toFileString() const;
};

#endif
