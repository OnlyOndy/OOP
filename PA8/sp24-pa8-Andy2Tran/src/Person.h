// Title  : Person.h
// Desc   : Header file for Person.cpp
// Name   : An Tran

#include <string>
    using std::string;

#ifndef PERSON_H
#define PERSON_H

class Person{
private:
    string name{""};
    int age{0};

public:
    // constructors
    Person();
    Person(string newName, int newAge);

    // getters
    string getName();
    int getAge();

    // setters
    void setName(string newName);
    void setAge(int newAge);
};

#endif
