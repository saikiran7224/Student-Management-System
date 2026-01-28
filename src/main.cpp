#include <iostream>
#include "StudentManager.h"
using namespace std;

int main() {
    StudentManager sm;
    int role;

    cout << "Select Role:\n1. Admin\n2. Viewer\n";
    cin >> role;

    int choice;
    do {
        cout << "\n1. Add Student";
        cout << "\n2. View Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Sort Students";
        cout << "\n7. Export to CSV";
        cout << "\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (role == 1) sm.addStudent();
                else cout << "Access denied!\n";
                break;
            case 2: sm.viewStudents(); break;
            case 3: sm.searchStudent(); break;
            case 4:
                if (role == 1) sm.updateStudent();
                else cout << "Access denied!\n";
                break;
            case 5:
                if (role == 1) sm.deleteStudent();
                else cout << "Access denied!\n";
                break;
            case 6: sm.sortStudents(); break;
            case 7: sm.exportToCSV(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
