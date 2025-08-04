#include "Item.h"

// constructor
Item::Item(string name, double cost, int points, string type)
    : name(name), cost(cost), points(points), type(type) {}

// destructor
Item::~Item() {}

// getters
string Item::getName() const {
    return name;
};

double Item::getCost() const {
    return cost;
};

int Item::getPoints() const {
    return points;
};

string Item::getType() const {
    return type;
};

// setters
void Item::setName(const string& newName) {
    name = newName;
};

void Item::setCost(double newCost) {
    cost = newCost;
};

void Item::setPoints(int newPoints) {
    points = newPoints;
};

void Item::setType(string newType) {
    type = newType;
};

// other
void Item::use(Player* targetPlayer) {
    if (type == "powerUp") {

    } else if (type == "debuff") {

    } else {

    };
};
