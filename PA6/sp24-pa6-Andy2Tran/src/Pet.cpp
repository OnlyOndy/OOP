// Title  : Pet.cpp
// Desc   : Implementation for Pet class
// Name   : An Tran

#include <iostream>
    using std::getline;
    using std::cout;
    using std::cin;

#include <iomanip>
    using std::setw;
    using std::left;
    using std::right;

#include <algorithm>

#include "Pet.h"

// constructor
Pet::Pet() : name(""), DOB(Date()), type(""), breed(""){};
Pet::Pet(const string& name, const Date& DOB, const int& typeNum, const string& breed)
    : DOB(DOB){
    setName(name);
    setType(typeNum);
    setBreed(breed);
};

// getter
string Pet::getName(){
    return name;
};

Date Pet::getDOB(){
    return DOB;
};

string Pet::getType(){
    return type;
};

string Pet::getBreed(){
    return breed;
};

// setter
void Pet::setName(const string& newName) {
    name = newName;
    transform(name.begin(), name.end(), name.begin(), toupper);
}

void Pet::setDOB(const int& month, const int& day, const int& year) {
    DOB = Date(month, day, year);
}

void Pet::setType(const int &typeNum) {
    switch (typeNum) {
            case 1:
                type = "DOG"; 
                break;
            case 2:
                type = "CAT"; 
                break;
            case 3:
                type = "BIRD"; 
                break;
            case 4: 
                type = "SNAKE"; 
                break;
            default:
                string customType;
                cin >> customType;
                type = customType;
                transform(type.begin(), type.end(), type.begin(), toupper);
                break;
    };
}

void Pet::setBreed(const std::string& newBreed) {
    breed = newBreed;
    transform(breed.begin(), breed.end(), breed.begin(), toupper);
}

// other
std::ostream& operator<<(std::ostream& os, Pet& pet) {
    os << left << setw(13) << "NAME" << ":" << right << setw(21) << pet.name << '\n'
       << left << setw(13) << "DOB" << ":" << right << setw(21) << pet.DOB.dateString() << '\n'
       << left << setw(13) << "TYPE" << ":" << right << setw(21) << pet.type << '\n'
       << left << setw(13) << "BREED" << ":" << right << setw(21) << pet.breed << '\n';
    return os;
}

std::istream& operator>>(std::istream& input, Pet& pet) {
    getline(input, pet.name);
    int month, day, year, typeNum;
    input >> month >> day >> year;
    pet.setDOB(month, day, year);
    input >> typeNum;
    pet.setType(typeNum);
    input.ignore();
    getline(input, pet.breed);
    pet.setName(pet.name);
    pet.setBreed(pet.breed);
    return input;
}

