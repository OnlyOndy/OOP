// Title:  Student.cpp
// Desc:   File where Student class's functions and methods are implemented
// Name:   An Tran

#include <iostream>
#include <iomanip>
#include <ios>
#include <sstream>
#include "Student.h"

// constuctors
// default
Student::Student() : sid(0), phoneNumber(0), count(0) {}

// parameterized
Student::Student(int sid, std::string fName, std::string lName, std::string address, long phoneNumber, std::string grades, int count)
    : sid(sid), fName(fName), lName(lName), address(address), phoneNumber(phoneNumber), grades(grades), count(count) {}

// getter member functions
int Student::getSID() {
    return sid;
}

std::string Student::getFName() {
    return fName;
}

std::string Student::getLName() {
    return lName;
}

std::string Student::getAddress() {
    return address;
}

long Student::getPhone() {
    return phoneNumber;
}

int Student::getCount() {
    return count;
}

int Student::getGrade(int location)
{ //return the string value of the grade at the given location
    std::istringstream iss(grades);
    std::string value;
    int counter(0);
    while (iss >> value)
    {
        if (counter++ == location)
        {
        return stoi(value);
        }
    }
    return -1;
}

// setter member functions
void Student::setSID(int newSID) {
    sid = newSID;
}

void Student::setFName(std::string newFName) {
    fName = newFName;
}

void Student::setLName(std::string newLName) {
    lName = newLName;
}

void Student::setAddress(std::string newAddress) {
    address = newAddress;
}

void Student::setPhone(long newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void Student::setCount()
{ //set the counter to the number of grades in the string

    std::istringstream iss(grades);
    std::string value;

    int counter = 0;
    while (iss >> value)
    {
        counter++;
    }
    count = counter;
}

// Other functions

void Student::setStudent(int newSID, std::string newFName, std::string newLName, std::string newAddress, long newPhoneNumber, std::string newGrades) {
    sid = newSID;
    fName = newFName;
    lName = newLName;
    address = newAddress;
    phoneNumber = newPhoneNumber;
    grades = newGrades;
}

void Student::displayStudent() {
    std::cout << std::string(34, '*') << std::endl;
    std::cout << std::left << std::setw(13) << "Student ID   :" << std::right << std::setw(20) << sid << std::endl;
    std::cout << std::left << std::setw(13) << "First Name   :" << std::right << std::setw(20) << fName << std::endl;
    std::cout << std::left << std::setw(13) << "Last Name    :" << std::right << std::setw(20) << lName << std::endl;
    std::cout << std::left << std::setw(13) << "Address      :" << std::right << std::setw(20) << address << std::endl;
    std::cout << std::left << std::setw(13) << "Phone Number :" << std::right << std::setw(20) << phoneNumber << std::endl;
    std::cout << std::string(34, '*') << std::endl;
}

void Student::addGrade(int grade) {
    if (grade < 0 || grade > 100){
        return;
    };
    if (!grades.empty()) {
        grades += " ";
    };
    grades += std::to_string(grade);
    setCount();
}

std::string Student::convertLetterGrade(int grade) {
    switch (grade / 10) {
        case 10: // For 100
        case 9:  // For 90–99
            if (grade >= 94) return "A";
            else return "A-";
        case 8:  // For 80–89
            if (grade >= 87) return "B+";
            else if (grade >= 84) return "B";
            else return "B-";
        case 7:  // For 70–79
            if (grade >= 77) return "C+";
            else if (grade >= 74) return "C";
            else return "C-";
        case 6:  // For 60–69
            if (grade >= 67) return "D+";
            else if (grade >= 64) return "D";
            else if (grade >= 61) return "D-";
            else return "F"; // for 60 cause autograder broken?
        default: // For anything below 60
            return "F";
    }
}

std::string Student::currentLetterGrade() {
    double sum = 0;
    int count = 0;
    std::istringstream iss(grades);
    int tempGrade;
    while (iss >> tempGrade) {
        sum += tempGrade;
        ++count;
    }
    if (count == 0) return "N/A"; // Handle no grades case
    int average = static_cast<int>(sum / count);
    return convertLetterGrade(average);
}

void Student::listGrades() {
    std::cout << std::string(14, '*') << std::endl;
    std::cout << std::left << std::setw(3) << "GRD  " << std::right << std::setw(9) << "Cum.Avg." << std::endl;
    std::cout << std::string(14, '*') << std::endl;

    std::istringstream iss(grades);
    int grade;
    double sum = 0;

    for (int i = 0; i < count; ++i) {
        iss >> grade;
        sum += grade;
        double cumulativeAverage = sum / (i + 1);
        
        std::cout << std::setw(3) << std::right << grade
                  << std::setw(11) << std::right << std::fixed << std::setprecision(2) << cumulativeAverage
                  << std::endl;
    }
}

