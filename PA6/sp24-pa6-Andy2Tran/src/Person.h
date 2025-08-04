// Title  : Pet.h
// Desc   : Header file for Pet.cpp
// Name   : An Tran

#include <vector>

#include <string>
    using std::string;

#include "Address.h"
#include "Pet.h"

#ifndef PERSON_H
#define PERSON_H

#endif

class Person {
private:
    string fName{""};
    string lName{""};
    Address address;
    std::vector<Pet*> pets;

public:
    // constructors
    explicit Person(); // default
    explicit Person(const string& fName, const string& lName, const Address& address);
    explicit Person(const string& fName, const string& lName);

    ~Person();

    // getters
    string getFName();
    string getLName();
    Address& getAddress();
    std::vector<Pet*>& getPets();

    // setters
    void setFName(const string& newFName);
    void setLName(const string& newLName);
    void setAddress(const Address& newAddress);
    void setStreet(const string& newStreet);
    void setCity(const string& newCity);
    void setState(const string& newState);
    void setZip(const size_t& newZipCode);

    // other
    friend void operator+(std::vector<Pet*>& pets, Pet* pet);
    friend void operator-(std::vector<Pet*>& pets, string& petName);
    friend std::ostream& operator<<(std::ostream& output, Person& person);
    friend std::istream& operator>>(std::istream& input, Person& person);

    bool searchPet(const string& searchName);
    void addPet();
    void deletePet();
};
