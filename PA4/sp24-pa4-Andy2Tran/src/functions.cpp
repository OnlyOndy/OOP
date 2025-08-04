// Title:  functions.cpp
// Desc:   Implementation of functions
// Name:   An Tran

#include "functions.h"

#include <array>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

int getInput(std::array<float, MAX_SIZE>& grades){
    float gradeEntry;
    int ndx{0};

    while (ndx < MAX_SIZE){
        std::cout << "Grade to input (-1 when done): ";
        std::cin >> gradeEntry;
        if (gradeEntry == -1){
            break;
        };
        grades[ndx++] = gradeEntry;
    }
    return ndx;
};

void randInput(std::array<float, MAX_SIZE>& grades, int& amountToGen){
    if (amountToGen < 1 || amountToGen > MAX_SIZE) {
        return;
    };

    std::srand(std::time(0));
    for (int ndx = 0; ndx < amountToGen; ndx++) {
        grades[ndx] = std::rand() % 100 + 1;
    };
};

float average(std::array<float, MAX_SIZE>& grades, int& arrayLength){
    float sum = 0.0;
    for (int ndx = 0; ndx < arrayLength; ndx++) {
        sum += grades[ndx];
    };
    return sum / arrayLength;
};

void maxAndMin(std::array<float, MAX_SIZE>& grades, int& arrayLength, float& max, float& min){
    max = grades[0];
    min = grades[0];
    for (int ndx = 1; ndx < arrayLength; ndx++) {
        if (grades[ndx] > max){
            max = grades[ndx];
        }
        if (grades[ndx] < min){
            min = grades[ndx];
        }
    };
};

float standardDev(std::array<float, MAX_SIZE>& grades, int& arrayLength){
    float mean = average(grades, arrayLength);
    float sum = 0.0;
    for (int ndx = 0; ndx < arrayLength; ndx++) {
        sum += std::pow(grades[ndx] - mean, 2);
    };
    return std::sqrt(sum / static_cast<float>(arrayLength - 1));
};

void display(std::array<float, MAX_SIZE>& grades, int& arrayLength){
    std::cout << arrayLength << " grades were entered\n"; 
    std::cout << "The values are : \n"; 
    for (int ndx = 0; ndx < arrayLength; ndx++) {
        std::cout << grades[ndx] << " ";
        if ((ndx + 1) % 5 == 0 || ndx == arrayLength - 1) std::cout << "\n";
    };

    if (arrayLength % 5 == 0){
        std::cout << "\n";
    }
    
    float avg = average(grades, arrayLength);
    float max, min;
    maxAndMin(grades, arrayLength, max, min);
    float stddev = standardDev(grades, arrayLength);

    std::cout << "The average of the " << arrayLength << " numbers is : " << avg << "\n";
    std::cout << "The minimum number is : " << min << "\n";
    std::cout << "The maximum number is : " << max << "\n";
    std::cout << "The standard deviation is : " << stddev << "\n";
};
