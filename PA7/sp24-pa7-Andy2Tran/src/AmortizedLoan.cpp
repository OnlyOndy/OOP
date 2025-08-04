// Title  : AmortizedLoan.cpp
// Desc   : Header file for AmortizedLoan.cpp
// Name   : An Tran

#include "AmortizedLoan.h"

#include <cmath>

// constructors
AmortizedLoan::AmortizedLoan() : Loan(){};
AmortizedLoan::AmortizedLoan(float principal, float interestRate, int loanLength) 
          : Loan(principal, interestRate, loanLength, "Amortized Loan"){};

// other
float AmortizedLoan::monthlyPayment() {
float monthlyInterestRate = getInterestRate() / 12 / 100;
    int totalMonths = getLoanLength() * 12;
    float numerator = getPrincipal() * monthlyInterestRate * std::pow(1 + monthlyInterestRate, totalMonths);
    float denominator = std::pow(1 + monthlyInterestRate, totalMonths) - 1;
    return numerator / denominator;
};
