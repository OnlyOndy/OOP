// Title  : Person.cpp
// Desc   : Implementation of Person class
// Name   : An Tran

#include "Person.h"

// constructors
Person::Person() : Person("", 0) {
    // LEFT EMPTY ON PURPOSE
};

Person::Person(string newName, int newAge) : name(newName), age(newAge) {
    // LEFT EMPTY ON PURPOSE
    // setName(newName);
    // setAge(newAge);
}; 

// getters
string Person::getName(){
    return name;
};

int Person::getAge(){
    return age;
};

// setters
void Person::setName(string newName){
    name = newName;
};

void Person::setAge(int newAge){
    age = newAge;
};
