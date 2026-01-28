#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <vector>
#include "Student.h"

class StudentManager {
private:
    vector<Student> students;

    void loadFromFile();
    void saveToFile();

public:
    StudentManager();

    void addStudent();
    void viewStudents();
    void searchStudent();
    void updateStudent();
    void deleteStudent();
    void sortStudents();

    // Advanced features
    void exportToCSV();
};

#endif
