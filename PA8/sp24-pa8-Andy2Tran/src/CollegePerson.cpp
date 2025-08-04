// Title  : CollegePerson.cpp
// Desc   : Implementation of CollegePerson class
// Name   : An Tran

#include "CollegePerson.h"

// constructor
CollegePerson::CollegePerson() : CollegePerson("", 0, "", "", 0) {};

CollegePerson::CollegePerson(string newName, int newAge, string newUniv, string newCollege, int newId) 
    : Person(newName, newAge), university(newUniv), college(newCollege), id(newId) {};

// getter
string CollegePerson::getUniv() {
    return university;
};

string CollegePerson::getCollege() {
    return college;
};

int CollegePerson::getID() {
    return id;
};

float CollegePerson::getEarned() {
    return earned;
};

float CollegePerson::getTotal() {
    return total;
};

float CollegePerson::getGrade() {
    return grade;
};

float CollegePerson::getgpa() {
    return gpa;
};

string CollegePerson::getLetterGrade() {
    return letterGrade;
};

// setter
void CollegePerson::setUniv(string newUniv) {
    university = newUniv;
};

void CollegePerson::setCollege(string newCollege) {
    college = newCollege;
};

void CollegePerson::setID(int newID) {
    id = newID;
};

void CollegePerson::setEarned(float newEarned) {
    earned = newEarned;
};

void CollegePerson::setTotal(float newTotal) {
    total = newTotal;
};

void CollegePerson::setGrade(float newGrade) {
    grade = newGrade;
};

void CollegePerson::setgpa(float newgpa) {
    gpa = newgpa;
};

void CollegePerson::setLetterGrade(string newLetterGrade) {
    letterGrade = newLetterGrade;
};
