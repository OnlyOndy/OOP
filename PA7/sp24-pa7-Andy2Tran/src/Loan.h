// Title  : Loan.h
// Desc   : Header file for Loan.cpp
// Name   : An Tran

#include <string>
    using std::string;

#ifndef LOAN_H
#define LOAN_H

class Loan
{
private:
    float principal{0.0};
    float interestRate{0.0};
    int loanLength{0};
    string loanType{""};

public:
    // constuctors
    Loan();
    Loan(float principal, float interestRate, int loanLength, string loanType);

    // getters
    float getPrincipal();
    float getInterestRate();
    float getLoanLength();
    string getLoanType();

    // setters
    void setPrincipal(float newPrincipal);
    void setInterestRate(float newInterestRate);
    void setLoanLength(int newLoanLength);
    void setLoanType(string newLoanType);

    //other
    virtual float monthlyPayment() = 0; //Pure virtual so it will be implemented in derived classes
    void displayLoan();
    void saveLoan();
};

#endif
