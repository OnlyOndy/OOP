// Title  : printStars.h
// Desc   : Header file for printStars.cpp
// Name   : An Tran

#include <vector>
#include <cstddef>

#ifndef PRINT_STARS_H
#define PRINT_STARS_H

size_t getNumberRange();
// Desc:      gets positive number and throws "The input does not meet the requirement" if equals 0
// Receives:  none
// Returns:   size_t

size_t getNumberSize();
// Desc:      gets number and throws "The input does not meet the requirement" if the number doesn't meet the requirement
// Receives:  none
// Returns:   size_t

size_t genRandomNumber(size_t&);
// Desc:      generates random number from 0 - range and returns
// Receives:  size_t&
// Returns:   size_t

int scaleNumber(size_t&, size_t&);
// Desc:      scales the generatedNumber to the desire range [-number, +number]
// Receives:  size_t&, size_t&
// Returns:   int

void fillVector(std::vector<int>&, size_t&, size_t&);
// Desc:      Uses genRandomNumber function to scale the generatedNumber and uses them to push onto the vector
// Receives:  vector<int>, size_t&, size_t&
// Returns:   void

void printStars(std::vector<int>&);
// Desc:      Prints stars based on user enter int. print vector[index] stars and vector[index]+1 blanks, shown as " * * * ". 
//            If number is negative, print vector[index]+1 stars and vector[index] blanks, shown as "* * * *".
// Receives:  vector<int>
// Returns:   void

#endif
