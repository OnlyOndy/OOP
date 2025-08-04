#include <vector>
    using std::vector;

#include <string>
    using std::string;

#include "Cell.h"

#ifndef BOARD_H
#define BOARD_H

class Board {
private:
    vector<vector<Cell>> grid;
    int size{0};

public:
    // constructor
    Board();
    Board(int size); // Just in case but logical will always default to 5
    
    // getter    
    int getSize();
    GameObject* getCellOccupant(int x, int y);

    // setter
    void setCellOccupant(int x, int y, GameObject* occupant);

    // other functions
    bool isCellEmpty(int x, int y) const;

    void display() const;

    void clear();
};


#endif