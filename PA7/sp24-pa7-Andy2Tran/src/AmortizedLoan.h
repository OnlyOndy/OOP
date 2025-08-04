// Title  : AmortizedLoan.h
// Desc   : Header file for AmortizedLoan.cpp
// Name   : An Tran

#ifndef AMORTIZEDLOAN_H
#define AMORTIZEDLOAN_H

#include "Loan.h"

class AmortizedLoan : public Loan
{
private:
    // has no member variables of its own
public:
    // constuctors
    AmortizedLoan();
    AmortizedLoan(float principal, float interestRate, int loanLength);

    //other
    float monthlyPayment() override;
    // override the monthly payment function of the Loan class
    // returns monthlyPayment of SimpleLoan
};

#endif
