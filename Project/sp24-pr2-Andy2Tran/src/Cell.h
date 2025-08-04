#ifndef CELL_H
#define CELL_H

#include <string>
    using std::string;

#include "GameObject.h"

class Cell{
private:
    GameObject* occupant;

public:
    // constructor
    Cell();
    ~Cell();

    //setter
    void setOccupant(GameObject* newOccupant);

    //getter
    GameObject* getOccupant() const;

    // other
    bool isEmpty() const;
    void clear();
};

#endif
