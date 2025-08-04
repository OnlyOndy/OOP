#include "ItemBox.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>

ItemBox::ItemBox(int x, int y) : GameObject(x, y) {};

std::vector<Item*> ItemBox::chooseItems() {
    std::vector<Item*> chosenItems;
    size_t itemsCount = items.size();
    
    if (itemsCount < 2) {
        // If less than two items, return all that are available
        return items;
    };

    // randomly pick two distinct items
    srand(time(NULL));  // initialize random seed
    int firstIndex = rand() % itemsCount;
    int secondIndex = rand() % itemsCount;
    while (secondIndex == firstIndex) { // ensure two distinct items are chosen
        secondIndex = rand() % itemsCount;
    };

    chosenItems.push_back(items[firstIndex]);
    chosenItems.push_back(items[secondIndex]);
    return chosenItems;
};

void ItemBox::moveToNewLocation(Board* board) {
    int newX, newY;
    do {
        newX = rand() % board->getSize();
        newY = rand() % board->getSize();
    } while (!board->isCellEmpty(newX, newY));  // ensure the new location is empty

    setPosX(newX);
    setPosY(newY);
};

void ItemBox::removeItem(Item* chosenItem) {
    auto it = std::find(items.begin(), items.end(), chosenItem);
    if (it != items.end()) {
        items.erase(it);
    };
};

void ItemBox::addItem(Item* item) {
    items.push_back(item);
};
