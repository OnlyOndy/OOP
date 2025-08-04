#include "Cell.h"

// constructor
Cell::Cell() : occupant(nullptr) {}

// destructor
Cell::~Cell() {
    delete occupant;
    occupant = nullptr;
};

// setter
void Cell::setOccupant(GameObject* newOccupant) {
    occupant = newOccupant;
};

// getter
GameObject* Cell::getOccupant() const {
    return occupant;
};

// other
bool Cell::isEmpty() const {
    return occupant == nullptr;
};

void Cell::clear(){
    delete occupant;
    occupant = nullptr;
};
