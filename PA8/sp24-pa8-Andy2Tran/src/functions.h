// Title  : functions.h
// Desc   : Header file for functions.cpp
// Name   : An Tran

#include <vector>
    using std::vector;

#include "CollegePerson.h"

void greeting();

int recordCount();

void getInput(vector<CollegePerson*> collegeRecords);

void calcGrades(vector<CollegePerson*> collegeRecords);
// grade = (earned / total) * 100

void display(vector<CollegePerson*> collegeRecords);

