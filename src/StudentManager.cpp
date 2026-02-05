#include "StudentManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cctype>

using namespace std;

bool isNumeric(const string &str) {
    if (str.empty()) return false;

    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

StudentManager::StudentManager() {
    loadFromFile();
}

/* ---------- LOAD FROM FILE ---------- */
void StudentManager::loadFromFile() {
    ifstream file("students.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, age, cls, contact;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');
        getline(ss, cls, ',');
        getline(ss, contact, ',');

        students.push_back(
            Student(stoi(id), name, stoi(age), cls, contact)
        );
    }
    file.close();
}

/* ---------- SAVE TO FILE ---------- */
void StudentManager::saveToFile() {
    ofstream file("students.txt");
    for (auto &s : students) {
        file << s.toFileString() << endl;
    }
    file.close();
}

/* ---------- ADD STUDENT ---------- */
void StudentManager::addStudent() {
    int id, age;
    string idStr, name, cls, contact;

    cout << "Enter ID: ";
    cin >> idStr;

    if (!isNumeric(idStr)) {
        cout << "Invalid ID! ID should be in numeric.\n";
        return;
    }

    id = stoi(idStr);

    if (id <= 0) {
        cout << "Invalid ID! ID must be positive.\n";
        return;
    }

    for (auto &s : students) {
        if (s.getId() == id) {
            cout << "Duplicate ID not allowed!\n";
            return;
        }
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;
    if (age <= 0 || age > 100) {
        cout << "Invalid age!\n";
        return;
    }

    cout << "Enter Class: ";
    cin >> cls;

    while (true) {
        cout << "Enter Contact (10 digits): ";
        cin >> contact;

        if (contact.length() == 10 && isNumeric(contact)) {
            break;
        }

        cout << "Invalid contact number! Please enter exactly 10 digits.\n";
    }

    students.push_back(Student(id, name, age, cls, contact));
    saveToFile();
    cout << "Student added successfully!\n";
}

/* ---------- VIEW STUDENTS ---------- */
void StudentManager::viewStudents() {
    int pageSize = 5;
    int count = 0;

    cout << left
         << setw(6)  << "ID"
         << setw(15) << "Name"
         << setw(6)  << "Age"
         << setw(10) << "Class"
         << setw(15) << "Contact" << endl;
    cout << string(52, '-') << endl;

    for (auto &s : students) {
        s.display();
        count++;

        if (count % pageSize == 0) {
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }
}

/* ---------- SEARCH STUDENT ---------- */
void StudentManager::searchStudent() {
    int choice;
    cout << "1. Search by ID\n2. Search by Name\n";
    cin >> choice;

    if (choice == 1) {
        int id;
        cout << "Enter ID: ";
        cin >> id;

        for (auto &s : students) {
            if (s.getId() == id) {
                s.display();
                return;
            }
        }
    } else {
        string name;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);

        for (auto &s : students) {
            if (s.getName() == name) {
                s.display();
                return;
            }
        }
    }
    cout << "Student not found!\n";
}

/* ---------- UPDATE STUDENT ---------- */
void StudentManager::updateStudent() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    for (auto &s : students) {
        if (s.getId() == id) {
            string name, cls, contact;
            int age;

            cin.ignore();
            cout << "New Name: ";
            getline(cin, name);

            cout << "New Age: ";
            cin >> age;

            cout << "New Class: ";
            cin >> cls;

            cout << "New Contact: ";
            cin >> contact;

            s = Student(id, name, age, cls, contact);
            saveToFile();
            cout << "Student updated successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

/* ---------- DELETE STUDENT ---------- */
void StudentManager::deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == id) {
            char confirm;
            cout << "Confirm delete (y/n): ";
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                students.erase(it);
                saveToFile();
                cout << "Student deleted successfully!\n";
            }
            return;
        }
    }
    cout << "Student not found!\n";
}

/* ---------- SORT STUDENTS ---------- */
void StudentManager::sortStudents() {
    int choice;
    cout << "1. Sort by ID\n2. Sort by Name\n";
    cin >> choice;

    if (choice == 1) {
        sort(students.begin(), students.end(),
             [](Student &a, Student &b) {
                 return a.getId() < b.getId();
             });
    } else {
        sort(students.begin(), students.end(),
             [](Student &a, Student &b) {
                 return a.getName() < b.getName();
             });
    }

    cout << "Sorted successfully!\n";
}

/* ---------- EXPORT TO CSV ---------- */
void StudentManager::exportToCSV() {
    ofstream file("students.csv");
    file << "ID,Name,Age,Class,Contact\n";

    for (auto &s : students) {
        file << s.toFileString() << endl;
    }

    file.close();
    cout << "Exported to students.csv successfully!\n";
}
