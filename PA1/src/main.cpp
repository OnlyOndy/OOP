//Title:  main.cpp
//Desc:   Includes main.cpp. Demonstrates the use of functions and associated files.
//Name:   An Tran

#include "functions.h"
#include <iostream>
//TODO - Add the Program Assignment boilerplate comment block here. You can find its template in the C++ Code Style Guide

// TODO - Build a main function for testing your code.
int main(){
    // Working
    float lakeArea = calculateLakeArea();
    std::cout << "Area of lake: " << lakeArea << std::endl;

    // Working
    float volumeLake = calculateLakeVolume(lakeArea);
    std::cout << "Volume of lake: " << volumeLake << std::endl;

    // Working
    int fishStock = calculateFishStock(volumeLake);
    std::cout << "Fish stock: " << fishStock << std::endl;

    // Working
    int maxLicenses = calculateMaxLicenses(fishStock);
    std::cout << "Max licenses: " << maxLicenses << std::endl;
}