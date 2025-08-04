// Title  : useArray.cpp
// Desc   : Implementation for useArray.h
// Name   : An Tran

#include "useArray.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int howMany() {
    int num{0};
    std::cout << "Enter the number of elements (1-100): ";
    std::cin >> num;
    if (std::cin.fail() || num > 100 ||num < 1) {
        throw "The input does not meet the requirements";
    } else {
        return num;
    };
};

void fillArray(std::array<int, MAX_SIZE>& arr, int& size) {
    if (size < 1 || size > 100) {
        return;
    };

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    };
};

void printArray(std::array<int, MAX_SIZE>& arr, int& size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) {
            std::cout << '\n';
        };
    };
};

bool dupeCheck(std::array<int, MAX_SIZE>& arr, int& size){;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return false;
            };
        };
    };
    return true;
};

void sortArray(std::array<int, MAX_SIZE>& arr, int& size) {
    int temp{0};
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
