// Title  : main.cpp
// Desc   : Testing
// Name   : An Tran

#include <iostream>
    using std::cout;
    using std::cin;

#include "functions.h"

int main(){
    std::vector<CollegePerson*> collegeRecords;
    greeting();

    for(int i = 0; i < recordCount() ; i++) {
        collegeRecords.push_back(new CollegePerson());
    };

    cout << "Record Count: " << recordCount() << std::endl;

    getInput(collegeRecords);
    cout << collegeRecords[0] << std::endl;
    cout << collegeRecords[1] << std::endl;
    cout << collegeRecords[2] << std::endl;
    cout << collegeRecords[3] << std::endl;
    calcGrades(collegeRecords);
    display(collegeRecords);


    for (CollegePerson* person : collegeRecords) {
        delete person;
    }
    collegeRecords.clear();

    return 0;
};
