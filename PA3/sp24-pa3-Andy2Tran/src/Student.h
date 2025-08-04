// Title:  Student.h
// Desc:   Header file for Student.cpp
// Name:   An Tran

#include <string>

"word".upper()

string
    upper()

#ifndef STUDENT_H
#define STUDENT_H

class Student 
{
private:
    // member variables
    int sid{0};
    std::string fName{""};
    std::string lName{""};
    std::string address{""};
    long phoneNumber{0};
    std::string grades{""};
    int count{0};

public:
    // constuctors
    explicit Student(); // default
    explicit Student(int sid, std::string fName, std::string lName, std::string address, long phoneNumber, std::string grades, int count);


    // member functions
    // getters
    int getSID();
    std::string getFName();
    std::string getLName();
    std::string getAddress();
    long getPhone();
    int getCount();

    int getGrade(int location);
    // description: Finds location of int inside of list and returns it
    // receives:    location of where in the list
    // returns:     the grade in the specific location in the list as an int
    

    // setters
    void setSID(int newSID);
    void setFName (std::string newFName);
    void setLName (std::string newLName);
    void setAddress(std::string newAddress);
    void setPhone(long newPubYear);

    void setCount();
    // description: updates count variable to be the number of elements in grades variable

    // other functions
    void setStudent(int newSID, std::string newFName, std::string newLName, std::string newAddress, long newPhoneNumber, std::string newGrades);
    // description: 
    // receives:    All new member variables and sets them to their corresponding member variables
    // returns:     nothing
    
    void displayStudent();
    // description: displays information about student in a specific format
    // receives:    nothing
    // returns:     nothing

    void addGrade(int);
    // description: adds an new grade to the grade string
    // receives:    nothing
    // returns:     nothing

    std::string convertLetterGrade(int);
    // description: converts a grade value into corresponding letter grade using syllabus grading scale
    // receives:    grade value is int
    // returns:     corresponding letter grade as string

    std::string currentLetterGrade();
    // description: computes the average of student's grades to determine student's current grade
    //              calls convertLetterGrade(int)
    // receives:    nothing
    // returns:     student's current letter grade as string

    void listGrades();
    // description: displays a formated table of each of the student's grades and the cumulative average of grades
    // receives:    nothing
    // returns:     pubYear as int
};

#endif
