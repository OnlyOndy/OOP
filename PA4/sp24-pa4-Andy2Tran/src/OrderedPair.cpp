// Title:  OrderedPair.cpp
// Desc:   Implementation of OrderedPair class
// Name:   An Tran

#include "OrderedPair.h"

#include <iostream>
#include <string>
#include <cmath>


// constuctors 
OrderedPair::OrderedPair() : xVal(0.0), yVal(0.0) {};
OrderedPair::OrderedPair(double xVal, double yVal) : xVal(xVal), yVal(yVal) {};

// getters
double OrderedPair::getX(){
    return xVal;
};

double OrderedPair::getY(){
    return yVal;
};

// setters
void OrderedPair::setX(double newXVal){
    xVal = newXVal;
};

void OrderedPair::setY(double newYVal){
    yVal = newYVal;
};

void OrderedPair::setPair(double& newXVal, double& newYVal){
    setX(newXVal);
    setY(newYVal);
};

// element-wise arithmetic functions
double OrderedPair::addPair(){
    return xVal + yVal;
};

double OrderedPair::subtractPair(){
    return xVal - yVal;
};

double OrderedPair::multiplyPair(){
    return xVal * yVal;
};

double OrderedPair::dividePair(){
    if (yVal == 0){
        std::cout << "yVal==0";
        return -1;
    } else {
        return xVal / yVal;
    };
};

double OrderedPair::powerPair(){
    return pow(xVal, yVal);
};

// pair-wise arithmetic functions
void OrderedPair::addPair(OrderedPair& obj1, OrderedPair& obj2){
    xVal = obj1.xVal + obj2.xVal;
    yVal = obj1.yVal + obj2.yVal;
};

void OrderedPair::subtractPair(OrderedPair& obj1, OrderedPair& obj2){
    xVal = obj1.xVal - obj2.xVal;
    yVal = obj1.yVal - obj2.yVal;
};

void OrderedPair::multiplyPair(OrderedPair& obj1, OrderedPair& obj2){
    xVal = obj1.xVal * obj2.xVal;
    yVal = obj1.yVal * obj2.yVal;
};

void OrderedPair::dividePair(OrderedPair& obj1, OrderedPair& obj2){
    if (obj2.xVal == 0 || obj2.yVal == 0){
        std::cout << "DIVIDE BY ZERO";
    } else {
        xVal = obj1.xVal / obj2.xVal;
        yVal = obj1.yVal / obj2.yVal;
    };
};

void OrderedPair::powerPair(OrderedPair& obj1, OrderedPair& obj2){
    xVal = pow(obj1.xVal, obj2.xVal);
    yVal = pow(obj1.yVal, obj2.yVal);
};

// other functions

void OrderedPair::displayPair(){
    std::cout << "(" << std::to_string(xVal) << ", "<< std::to_string(yVal) << ")" << std::endl;
};
