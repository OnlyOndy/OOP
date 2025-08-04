// Title  : main.cpp
// Desc   : for testing
// Name   : An Tran

#include "useArray.h"
#include "printStars.h"
#include <ctime>
#include <iostream>

int main(){
    // Testing array
    srand (time(NULL));
    std::array<int, MAX_SIZE> myArray;
    int size = howMany();
    fillArray(myArray, size);
    printArray(myArray, size);
    if (dupeCheck(myArray, size)){
        std::cout << "No duplicates found \n";
    } else {
        std::cout << "Duplicates found \n";
    };
    printArray(myArray, size);
    sortArray(myArray, size);
    printArray(myArray, size);

    // Testing stars
    size_t numberRange = getNumberRange();
    size_t numberSize = getNumberSize();
    std::vector<int> myVector;
    fillVector(myVector, numberRange, numberSize);
    printStars(myVector);
    return 0;
};
