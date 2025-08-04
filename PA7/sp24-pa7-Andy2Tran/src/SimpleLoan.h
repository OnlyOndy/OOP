// Title  : SimpleLoan.h
// Desc   : Header file for SimpleLoan.cpp
// Name   : An Tran

#ifndef SIMPLELOAN_H
#define SIMPLELOAN_H

#include "Loan.h"

class SimpleLoan : public Loan
{
private:
    // has no member variables of its own
public:
    // constuctors
    SimpleLoan();
    SimpleLoan(float principal, float interestRate, int loanLength);

    //other
    float monthlyPayment() override;
    // override the monthly payment function of the Loan class
    // returns monthlyPayment of SimpleLoan
};

#endif
