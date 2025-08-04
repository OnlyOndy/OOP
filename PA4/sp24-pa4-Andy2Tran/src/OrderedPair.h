// Title:  OrderedPair.h
// Desc:   Header file for OrderedPair.cpp
// Name:   An Tran

#ifndef ORDEREDPAIR_H
#define ORDEREDPAIR_H

class OrderedPair{
private:
    double xVal{0.0};
    double yVal{0.0};

public:
    // constructors
    OrderedPair();
    OrderedPair(double xVal, double yVal);

    // getters
    double getX();
    double getY();
    
    // setters
    void setX(double newXVal);
    void setY(double newYVal);
    void setPair(double& newXVal, double& newYVal);

    // element-wise arithmetic functions
    // description: Does calculates using the object's xVal and yVals and returns it as a double
    // receives:    nothing
    // returns:     double
    double addPair();
    double subtractPair();
    double multiplyPair();
    double dividePair(); // has error check for dividing by zero
    double powerPair();

    // pair-wise arithmetic functions
    // description: Replace target object's xVal and yVal with corresponding calculates of OrderPair object's x and y
    // receives:    Reference to two OrderedPair objects. 
    // returns:     nothing
    void addPair(OrderedPair& obj1, OrderedPair& obj2);
    void subtractPair(OrderedPair& obj1, OrderedPair& obj2);
    void multiplyPair(OrderedPair& obj1, OrderedPair& obj2);
    void dividePair(OrderedPair& obj1, OrderedPair& obj2); // has error check for dividing by zero
    void powerPair(OrderedPair& obj1, OrderedPair& obj2);

    // other functions
    void displayPair(); // values are expected to be to 6 decimal places
};

#endif
