// Title  : useArray.h
// Desc   : Header file for useArray.cpp
// Name   : An Tran

#include <array>

#ifndef __USEARRAY_H__
#define __USEARRAY_H__

const int MAX_SIZE = 100;

int howMany();
// Desc:      returns int from 0 - 100 and if it doesn't meet the requirement, throw an exception of type const char* with 
//            message: "The input does not meet the requirements"
// Receives:  none
// Returns:   int

void fillArray(std::array<int, MAX_SIZE>&, int&);
// Desc:      populates an empty array of ints with passed in int value of random values. If that value is less than 1 or more than 100,
//            the function will terminate without any values being added to the array. Those random numbers range from 1 - 9999.
// Receives:  empty array of ints passed by reference, int passed by reference
// Returns:   none

void printArray(std::array<int, MAX_SIZE>&, int&);
// Desc:      display the array 10 numbers per row where each value is delimited by a space
// Receives:  empty array of ints passed by reference, int passed by reference
// Returns:   none

bool dupeCheck(std::array<int, MAX_SIZE>&, int&);
// Desc:      Checks if the Array Contains any Duplicates 
// Receives:  empty array of ints passed by reference, int passed by reference
// Returns:   none

void sortArray(std::array<int, MAX_SIZE>&, int&);
// Desc:      Will arrange the elements of the array in ascending order
// Receives:  empty array of ints passed by reference, int passed by reference
// Returns:   none

#endif
