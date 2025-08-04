// Title:  functions.h
// Desc:   Header file for functions.cpp
// Name:   An Tran

//TODO - Add the appopriate file header here

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//TODO - Add header comments for each function using the template ad guidelines shown to you in class

// int getInput()
// desc:      gets an input by the user through the console and returns it
// receives:  nothing
// returns:   int value
int getInput();

// float calculateLakeArea()
// desc:      calculates the area of the lake using Simpson's Rule.
//            math variables include:
// receives:  nothing
// returns:   float value of calculated lake area
float calculateLakeArea();

// float calculateLakeVolume(float)
// desc:      Calculates the volume of the lake by multiplying the value of areaOfLake parameter by the average lake depth of 20 feet.
//            math variables include:
// receives:  One float
// returns:   Float value of calculated lake volume
float calculateLakeVolume(float areaOfLake);

// int calculateFishStock(float)
// desc:      Calculates amount of fish stock by dividing the value of volumeOfLake parameter by 1000 cubic feet. Because we plan to
//            stock 1 fish per 1000 cubic feet.
// note:      Despite possibily calculating a float, since the function type is int, the return will drop any number following the decimal. The logical
//            of this interaction still represents the floor division we would want in this type of problem. You can't have a part of a fish.
// receives:  One float
// returns:   Int value of calculated fish stock
int calculateFishStock(float volumeOfLake);

// float calculateMaxLicenses(int)
// desc:      Calculates max amount of lincenses. First, calculates 75% of value of fishStock parameter. The 75% will be stored as availableFishStock
//            and be used to represent as it's name states. If average catch is 20 fish per license, then availableFishStock can be dividied by 20
//            to find the max amount of lincenses.
// note:      Despite possibily calculating a float, since the function type is int, the return will drop any number following the decimal. The logical
//            of this interaction still represents the floor division we would want in this type of problem. We are finding possible max
// receives:  One int
// returns:   Int value of calculated max licenses
int calculateMaxLicenses(int fishStock);

#endif