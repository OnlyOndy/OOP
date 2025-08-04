// Title  : SimpleLoan.cpp
// Desc   : Implementation for SimpleLoad class which is derived from Loan class
// Name   : An Tran

#include "SimpleLoan.h"

// constructors
SimpleLoan::SimpleLoan() : Loan(){};
SimpleLoan::SimpleLoan(float principal, float interestRate, int loanLength) 
          : Loan(principal, interestRate, loanLength, "Simple Loan"){};

// other
float SimpleLoan::monthlyPayment() {
    float monthlyInterestRate = getInterestRate() / 12 / 100;
    int totalMonths = getLoanLength() * 12;
    return (getPrincipal() * (monthlyInterestRate * totalMonths + 1)) / totalMonths;
};
