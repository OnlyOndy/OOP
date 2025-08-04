#ifndef ITEMBOX_H
#define ITEMBOX_H

#include "GameObject.h"
#include "Player.h"
#include "Item.h"
#include <vector>

class Board;
class Game;
class Player;
class Item;

class ItemBox : public GameObject {
private:
    std::vector<Item*> items; // Stores items within the item box

public:
    // constructor
    ItemBox(int x, int y);

    // method to randomly select two items to present to the player
    std::vector<Item*> chooseItems();

    // method to randomly move to a new location
    void moveToNewLocation(Board* board);

    void removeItem(Item* chosenItem);

    void addItem(Item* item);
};

#endif
