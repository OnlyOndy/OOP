// Title  : Address.h
// Desc   : Header file for Address.cpp
// Name   : An Tran

#include <string>
    using std::string;

#ifndef ADDRESS_H
#define ADDRESS_H

class Address{
private:
    string street{""};
    string city{""};
    string state{""};
    size_t zipCode{0};

public:
    friend class Person;

    // constructors
    explicit Address(); // default
    explicit Address(const string& street, const string& city, const string& state, const size_t& zipCode);

    // getters
    string getStreet();
    string getCity();
    string getState();
    size_t getZip();
    
    // setters
    void setStreet(const string& newStreet);
    void setCity(const string& newCity);
    void setState(const string& newState);
    void setZip(const size_t& newZipCode);

    // other 
    friend std::ostream& operator<<(std::ostream& os, Address& addr);
    friend std::istream& operator>>(std::istream& input, Address& addr);
};

#endif
