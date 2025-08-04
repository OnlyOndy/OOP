// Title  : Address.cpp
// Desc   : Implementation for Address class
// Name   : An Tran

#include <iostream>
    using std::getline;

#include <iomanip>
    using std::setw;
    using std::left;
    using std::right;

#include <algorithm>

#include "Address.h"

// constructor
Address::Address() : street(""), city(""), state(""), zipCode(0){};
Address::Address(const string& street, const string& city, const string& state, const size_t& zipCode)
    : zipCode(zipCode) {
        setStreet(street);
        setCity(city);
        setState(state);
    };

// getter
string Address::getStreet(){
    return street;
};

string Address::getCity(){
    return city;
};

string Address::getState(){
    return state;
};

size_t Address::getZip(){
    return zipCode;
};

// setter
void Address::setStreet(const string& newStreet) {
    street = newStreet;
    transform(street.begin(), street.end(), street.begin(), toupper);
}

void Address::setCity(const string& newCity) {
    city = newCity;
    transform(city.begin(), city.end(), city.begin(), toupper);
}

void Address::setState(const string& newState) {
    state = newState;
    transform(state.begin(), state.end(), state.begin(), toupper);
}

void Address::setZip(const size_t& newZipCode) {
    zipCode = newZipCode;
}

// other
std::ostream& operator<<(std::ostream& os, Address& addr) {
    os << left << setw(13) << "STREET" << ":" << right << setw(21) << addr.street << '\n'
       << left << setw(13) << "CITY" << ":" << right << setw(21) << addr.city << '\n'
       << left << setw(13) << "STATE" << ":" << right << setw(21) << addr.state << '\n'
       << left << setw(13) << "ZIP CODE" << ":" << right << setw(21) << addr.zipCode << '\n';
    return os;
}

std::istream& operator>>(std::istream& input, Address& addr) {
    getline(input, addr.street);
    getline(input, addr.city);
    getline(input, addr.state);
    input >> addr.zipCode;

    if (input.peek() == '\n') {
        input.ignore();
    };

    addr.setStreet(addr.street);
    addr.setCity(addr.city);
    addr.setState(addr.state);
    return input;
}
