// Title  : main.cpp
// Desc   : Testing
// Name   : An Tran

#include "Loan.h"
#include "SimpleLoan.h"
#include "AmortizedLoan.h"

int main(){
    // Simple loan
    SimpleLoan simpleLoan(15000, 8.5, 3);
    simpleLoan.displayLoan();
    simpleLoan.saveLoan();

    // Amortized loan
    AmortizedLoan amortizedLoan(15000, 8.5, 3);
    amortizedLoan.displayLoan();
    amortizedLoan.saveLoan();

    return 0;
};
