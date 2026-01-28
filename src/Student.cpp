#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;

Student::Student() {}

Student::Student(int i, string n, int a, string c, string con)
    : id(i), name(n), age(a), className(c), contact(con) {}

int Student::getId() const {
    return id;
}

string Student::getName() const {
    return name;
}

void Student::display() const {
    cout << left
         << setw(6)  << id
         << setw(15) << name
         << setw(6)  << age
         << setw(10) << className
         << setw(15) << contact
         << endl;
}

string Student::toFileString() const {
    return to_string(id) + "," + name + "," +
           to_string(age) + "," + className + "," + contact;
}
