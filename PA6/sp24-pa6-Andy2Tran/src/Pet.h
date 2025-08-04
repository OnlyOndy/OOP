// Title  : Pet.h
// Desc   : Header file for Pet.cpp
// Name   : An Tran

#include <string>
    using std::string;

#include "Date.h"

#ifndef PET_H
#define PET_H

class Pet{
private:
    string name{""};
    Date DOB;
    string type{""};
    string breed{""};

public:
    // constructors
    explicit Pet(); // default
    explicit Pet(const string& name, const Date& DOB, const int& typeNum, const string& breed);

    // getters
    string getName();
    Date getDOB();
    string getType();
    string getBreed();
    
    // setters
    void setName(const string& newName);
    void setDOB(const int& month, const int& day, const int& year);
    void setType(const int& typeNum); //typeNum represents the switch-case num for the pets
    void setBreed(const string& newBreed);

    // other 
    friend std::ostream& operator<<(std::ostream& os, Pet& pet);
    friend std::istream& operator>>(std::istream& input, Pet& pet);
};

#endif

