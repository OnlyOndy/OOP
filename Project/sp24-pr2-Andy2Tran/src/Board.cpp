#include <iostream>
    using std::cout;

#include "Board.h"
#include "ItemBox.h"


// constructor
Board::Board() : Board(5) {};;
Board::Board(int size) : size(size), grid(size, vector<Cell>(size)) {};

// getter
int Board::getSize() {
    return size;
};

GameObject* Board::getCellOccupant(int x, int y) {
    return grid[x][y].getOccupant();
};

// setter
void Board::setCellOccupant(int x, int y, GameObject* occupant) {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        grid[x][y].setOccupant(occupant);
    };
};

// other functions
bool Board::isCellEmpty(int x, int y) const {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        return grid[x][y].isEmpty();
    };
    return false;  // eeturn false if the coordinates are out of bounds
};

void Board::display() const {
    // EXAMPLE:
    //  +---+---+---+---+---+
    //  | 1 |   |   |   |   |
    //  +---+---+---+---+---+
    //  |   |   |   |   |   |
    //  +---+---+---+---+---+
    //  |   |   | I |   |   |
    //  +---+---+---+---+---+
    //  |   |   |   |   | 2 |
    //  +---+---+---+---+---+
    //  | I |   |   |   |   |
    //  +---+---+---+---+---+
    // specifically for 5x5 board but board should dynamically chagne depending on size 

    // Calculate the total width dynamically
    const std::string separator = "+" + std::string(size * 4 - 1, '-') + "+";
    
    std::cout << separator << std::endl;
    
    for (int y = 0; y < size; y++) {
        std::cout << "|";
        for (int x = 0; x < size; x++) {
            const Cell& cell = grid[y][x];
            if (!cell.isEmpty()) {
                GameObject* occupant = cell.getOccupant();
                Token* token = dynamic_cast<Token*>(occupant);
                if (token) {
                    std::cout << " P |"; // 'P' represents a player token
                } else if (dynamic_cast<ItemBox*>(occupant)) {
                    std::cout << " I |"; // 'I' represents an item box
                } else {
                    std::cout << " ? |"; // Unknown GameObject type
                }
            } else {
                std::cout << "   |";  // empty cell
            }
        }
        std::cout << std::endl;
        std::cout << separator << std::endl;
    }
}

void Board::clear() {
    for (auto& row : grid) {
        for (auto& cell : row) {
            cell.clear();
        };
    };
};