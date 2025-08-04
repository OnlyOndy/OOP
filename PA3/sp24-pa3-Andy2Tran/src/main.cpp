// Title:  main.cpp
// Desc:   Testing student.cpp and student.h
// Name:   An Tran

#include "Student.h"
#include <iostream>

int main() {
    Student student(1, "John", "Doe", "123 Main St", 5551234, "90 80 70 60", 4);

    std::cout << "Initial student data:" << std::endl;
    student.displayStudent();

    student.setStudent(2, "Jane", "Doe", "321 St", 1234567, "100, 23, 84");
    student.addGrade(85);
    student.addGrade(95);

    std::cout << "\nUpdated student data:" << std::endl;
    student.displayStudent();

    std::cout << "\nList of grades and cumulative average:" << std::endl;
    student.listGrades();

    std::cout << "\nCurrent letter grade:" << std::endl;
    std::cout << student.currentLetterGrade() << std::endl;

    return 0;
}
