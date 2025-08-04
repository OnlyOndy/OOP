// Title  : functions.cpp
// Desc   : Implementation of functions
// Name   : An Tran

#include <iostream>
    using std::cout;
    using std::cin;
    using std::endl;

#include <iomanip>
    using std::setfill;
    using std::setw;
    using std::left;
    using std::right;

#include <fstream>

#include <sstream>

#include "functions.h"

void greeting() {
    cout << "Press Enter to Continue";
    cin.get();
};

int recordCount() {
    std::ifstream file("data/data.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return -1;
    };
    std::string line;
    int recordCount = 0;
    bool isPreviousLineEmpty = true; // to handle the case where file starts directly with data

    while (getline(file, line)) {
        if (line.empty()) {
            recordCount++;
            isPreviousLineEmpty = true;
        } else {
            isPreviousLineEmpty = false;
        };
    };

    if (!isPreviousLineEmpty) { // if last line read was not empty, increment count for the last record
        recordCount++;
    }

    file.close();
    return recordCount;
};

void getInput(vector<CollegePerson*> collegeRecords) {;
    std::ifstream file("data/data.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    };

    std::string line;
    int recordIndex = 0; // keep an index to track which CollegePerson we're updating.

    while (recordIndex < collegeRecords.size() && std::getline(file, line)) {
        if (line.empty()) {
            continue;  // skip empty lines between records
        };

        std::istringstream iss(line);
        string name, university, college;
        int age, id;
        float earned = 0.0, total = 0.0;

        // parsing first line of data for personal info
        getline(iss, name, ',');
        iss >> age;
        iss.ignore();
        getline(iss, university, ',');
        getline(iss, college, ',');
        iss >> id;

        CollegePerson* person = collegeRecords[recordIndex]; 
        person->setName(name);
        person->setAge(age);
        person->setUniv(university);
        person->setCollege(college);
        person->setID(id);

        // read all grades for this person until an empty line is found.
        while (std::getline(file, line) && !line.empty()) {
            std::istringstream issGrade(line);
            float gradeEarned, gradeTotal;
            string gradeType;
            getline(issGrade, gradeType, ','); // skip to the grade value
            issGrade >> gradeEarned;
            issGrade.ignore();
            issGrade >> gradeTotal;

            earned += gradeEarned;
            total += gradeTotal;
        };

        // set the total earned and total points
        person->setEarned(earned);
        person->setTotal(total);

        recordIndex++;
    };
    file.close();
};

void calcGrades(vector<CollegePerson*> collegeRecords) {
    float grade{0.0};
    for (int i = 0; i < collegeRecords.size(); i++) {
        if (collegeRecords[i]->getTotal() > 0) { // ensure no division by zero
            grade = (collegeRecords[i]->getEarned() / collegeRecords[i]->getTotal()) * 100;
            collegeRecords[i]->setGrade(grade);

            // apply grading scale
            if (grade > 94) {
                collegeRecords[i]->setLetterGrade("A+");
                collegeRecords[i]->setgpa(4.5);
            } else if (grade > 89) {
                collegeRecords[i]->setLetterGrade("A");
                collegeRecords[i]->setgpa(4.0);
            } else if (grade > 84) {
                collegeRecords[i]->setLetterGrade("B+");
                collegeRecords[i]->setgpa(3.5);
            } else if (grade > 79) {
                collegeRecords[i]->setLetterGrade("B");
                collegeRecords[i]->setgpa(3.0);
            } else if (grade > 74) {
                collegeRecords[i]->setLetterGrade("C+");
                collegeRecords[i]->setgpa(2.5);
            } else if (grade > 69) {
                collegeRecords[i]->setLetterGrade("C");
                collegeRecords[i]->setgpa(2.0);
            } else if (grade > 64) {
                collegeRecords[i]->setLetterGrade("D+");
                collegeRecords[i]->setgpa(1.5);
            } else if (grade > 60) {
                collegeRecords[i]->setLetterGrade("D");
                collegeRecords[i]->setgpa(1.0);
            } else {
                collegeRecords[i]->setLetterGrade("F");
                collegeRecords[i]->setgpa(0);
            };
        } else {
            // If total points are 0
            collegeRecords[i]->setLetterGrade("F");
            collegeRecords[i]->setgpa(0);
        };
    };
};

void display(vector<CollegePerson*> collegeRecords) {
    //display UCD Students
    cout << "UCD" << endl
         << left << setw(15) << "Name" << left << setw(15) << "Age" << left << setw(15) << "ID"
         << left << setw(15) << "College" << left << setw(15) << "GPA" << left << setw(15) << "Grade" << endl;
    for(int i = 0; i < collegeRecords.size() ; i++)
    {
        if (collegeRecords[i]->getUniv() == "UCD") {
            cout << left << setw(15) << collegeRecords[i]->getName() << left << setw(15) << collegeRecords[i]->getAge() << left << setw(15) << collegeRecords[i]->getID()
                 << left << setw(15) << collegeRecords[i]->getCollege() << left << setw(15) << collegeRecords[i]->getgpa() << left << setw(15) << collegeRecords[i]->getLetterGrade() << endl;
        };
    };

    //display Metro State Students
    cout << "Metro State" << endl
         << left << setw(15) << "Name" << left << setw(15) << "Age" << left << setw(15) << "ID"
         << left << setw(15) << "College" << left << setw(15) << "GPA" << left << setw(15) << "Grade" << endl;
    for(int i = 0; i < collegeRecords.size() ; i++)
    {
        if (collegeRecords[i]->getUniv() == "Metro State") {
            cout << left << setw(15) << collegeRecords[i]->getName() << left << setw(15) << collegeRecords[i]->getAge() << left << setw(15) << collegeRecords[i]->getID()
                 << left << setw(15) << collegeRecords[i]->getCollege() << left << setw(15) << collegeRecords[i]->getgpa() << left << setw(15) << collegeRecords[i]->getLetterGrade() << endl;
        };
    };
};
