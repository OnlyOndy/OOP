// Title  : Loan.cpp
// Desc   : Implementation for Loan class
// Name   : An Tran

#include <iostream>
    using std::cout;

#include <iomanip>
    using std::setfill;
    using std::setw;
    using std::left;
    using std::right;

#include <fstream>

#include "Loan.h"

// constructors
Loan::Loan() : Loan(0.0, 0.0, 0, ""){};
Loan::Loan(float principal, float interestRate, int loanLength, string loanType)
    : principal(principal), interestRate(interestRate), loanLength(loanLength), loanType(loanType){
    // setPrincipal(principal);
    // setInterestRate(interestRate);
    // setLoanLength(loanLength);
    // setLoanType(loanType);
};

// getters
float Loan::getPrincipal(){
    return principal;
};

float Loan::getInterestRate(){
    return interestRate;
};

float Loan::getLoanLength(){
    return loanLength;
};

string Loan::getLoanType(){
    return loanType;
};

// setters
void Loan::setPrincipal(float newPrincipal){
    principal = newPrincipal;
};

void Loan::setInterestRate(float newInterestRate){
    interestRate = newInterestRate;
};

void Loan::setLoanLength(int newLoanLength){
    loanLength = newLoanLength;
};

void Loan::setLoanType(string newLoanType){
    loanType = newLoanType;
};

//other
void Loan::displayLoan(){
    double monthlyPayment = this->monthlyPayment();
    cout << "Loan Overview" << '\n'
         << std::setfill('=') << std::setw(32) << "" << std::setfill(' ') << '\n'
         << left << setw(18) << "Loan Type:" << this->getLoanType() << '\n'
         << left << setw(18) << "Principal:" << this->getPrincipal() << '\n'
         << left << setw(18) << "Interest Rate:" << this->getInterestRate() << '%' << '\n'
         << left << setw(18) << "Length in Years:" << this->getLoanLength() << '\n'
         << left << setw(18) << "Monthly Payment:" << monthlyPayment << '\n';
};

void Loan::saveLoan(){
    std::fstream file;
    file.open("data/loans.txt", std::ios::out);
    file << getPrincipal() << " " << getInterestRate() << " " << getLoanLength();
    file.close();
};
