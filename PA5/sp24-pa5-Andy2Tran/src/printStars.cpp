// Title  : printStars.cpp
// Desc   : Implementation for printStars.h
// Name   : An Tran

#include "printStars.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>

size_t getNumberRange(){
    size_t range{0};
    std::cout << "Enter number range: ";
    std::cin >> range;
    if (range == 0){
        throw "The input does not meet the requirements";
    };
    return range;
};

size_t getNumberSize(){
    size_t size;
    std::cout << "Enter number size (1-100): ";
    std::cin >> size;
    if (size <= 1 || size >= 100){
        throw "The input does not meet the requirements";
    }
    return size;

};

size_t genRandomNumber(size_t& range){
    srand (time(NULL));
    return rand() % (range + 1);
};

int scaleNumber(size_t& generatedNumber, size_t& range){
    int scaled = static_cast<int>(generatedNumber) - static_cast<int>(range / 2);
    if (scaled == 0){
        return 1;
    };
    return scaled;
};

void fillVector(std::vector<int>& vec, size_t& numberRange, size_t& numberSize){
    for (size_t i = 0; i < numberSize; i++) {
        size_t num = genRandomNumber(numberRange);
        int scaledNum = scaleNumber(num, numberRange);
        vec.push_back(scaledNum);
    };
};

void printStars(std::vector<int>& vec){
    int index{0};
    int num{0};
    int absNum{0};

    std::cin >> index;
    do {
        if (index >= 0 && index < vec.size()){
            num = vec[index];
            if (num > 0){ // Positive
                for (int i = 0; i < num; i++) {
                    std::cout << " *";
                };
                std::cout << " " << std::endl;
            } else if (num < 0){// Negative (num < 0) 
                absNum = std::abs(num);
                for (int i = 0; i < absNum; i++) {
                    std::cout << "* ";
                };
                std::cout << "*" <<std::endl;
            };
        };

        std::cin >> index;
    } while (index != 0);
};
