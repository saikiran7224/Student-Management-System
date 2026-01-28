# 🎓 Student Management System (C++)

A **console-based Student Management System** built using **C++** that allows efficient management of student records with **persistent storage**.  
This project demonstrates strong use of **Object-Oriented Programming (OOP)**, **file handling**, and **STL** concepts, making it ideal for **college projects, resumes, and GitHub portfolios**.

---

## 📌 Project Overview

The Student Management System (SMS) helps manage student records such as:
- Adding new students
- Viewing and searching existing records
- Updating or deleting student information
- Sorting and exporting data
- Maintaining data even after the program exits

All records are stored using **file-based persistence**, ensuring data is not lost.

---

## ✨ Features

### 🔹 Core Features
- Add student records with **unique student ID**
- Display all students in a **tabular format**
- Search students by **ID or Name**
- Update student details
- Delete student records with confirmation
- Sort students by **ID** or **Name**
- Input validation for safe data entry
- Prevents **duplicate student IDs**
- Persistent storage using file handling

### 🔹 Advanced Features
- Export student records to **CSV file**
- **Role-based access**
  - Admin: Full access
  - Viewer: Read-only access
- **Pagination support** for large datasets

---

## 🛠 Technologies Used

- **Language:** C++
- **Concepts:**  
  - Object-Oriented Programming (OOP)  
  - Encapsulation & Modularity
- **Libraries:** STL (`vector`, `algorithm`, `fstream`)
- **Tools:**  
  - VS Code  
  - GCC / Clang Compiler
- **Storage:** Text file & CSV

---

## 📁 Project Structure

student-management-system/

│── main.cpp

│── Student.h

│── Student.cpp

│── StudentManager.h

│── StudentManager.cpp

│── students.txt

│── students.csv

│── README.md


### File Description
- `main.cpp` – Entry point and menu handling  
- `Student.h / Student.cpp` – Student class definition  
- `StudentManager.h / StudentManager.cpp` – Core logic, file handling, sorting, pagination  
- `students.txt` – Persistent storage file  
- `students.csv` – Exported student data  
- `README.md` – Project documentation  

---

## ⚙️ How to Compile

```bash
g++ main.cpp Student.cpp StudentManager.cpp -o student_app

./student_app

