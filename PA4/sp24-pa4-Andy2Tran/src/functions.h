// Title:  functions.h
// Desc:   Header file for functions.cpp
// Name:   An Tran

#include <array>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

const int MAX_SIZE = 50;

int getInput(std::array<float, MAX_SIZE>& grades);

void randInput(std::array<float, MAX_SIZE>& grades, int& amountToGen);

float average(std::array<float, MAX_SIZE>& grades, int& arrayLength);

void maxAndMin(std::array<float, MAX_SIZE>& grades, int& arrayLength, float& max, float& min);

float standardDev(std::array<float, MAX_SIZE>& grades, int& arrayLength);

void display(std::array<float, MAX_SIZE>& grades, int& arrayLength);

#endif
