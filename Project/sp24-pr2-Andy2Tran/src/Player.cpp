#include "Player.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

Player::Player(int id, int posX, int posY, Board* board, Game* game, double budget, bool isComputer)
    : id(id), token(new Token(posX, posY)), board(board), game(game), budget(budget), points(0), isComputer(isComputer) {};

Player::~Player() {
    delete token;
    clearInventory();
};

int Player::getId() const {
    return id;
};

Token* Player::getToken() const {
    return token;
};

bool Player::getIsComputer() const {
    return isComputer;
};

const std::vector<std::string>& Player::getReceipt() const {
    return receipt;
};

double Player::getBudget() const {
    return budget;
};

int Player::getPoints() const {
    return points;
};

void Player::setBudget(double newBudget) {
    budget = newBudget;
};

void Player::takeTurn(int roundNumber) {
    std::cout << "Player " << id << "'s turn. You are on cell " << token->getPosX() + 1 << " " << token->getPosY() + 1 << ".\n";
    if (isComputer) {
        aiDecideMove(roundNumber);
        aiDecideUseItem(roundNumber);
        
        // Here you can implement additional AI logic or end the turn
    } else {
        displayMenu(roundNumber);
    }
}

void Player::aiDecideMove(int roundNumber) {
    srand(static_cast<unsigned int>(time(NULL)));

    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // up, right, down, left

    // shuffle directions to randomize the AI's move choices
    std::random_shuffle(directions.begin(), directions.end());

    for (const auto& dir : directions) {
        int newX = token->getPosX() + dir.first;
        int newY = token->getPosY() + dir.second;

        if (validateMove(newX, newY)) {
            moveToken(newX, newY);
            std::cout << "AI Player " << getId() << " moves to (" << newX << ", " << newY << ")\n";
            break;
        };
    };
};

void Player::aiDecideUseItem(int roundNumber) {
    if (inventory.empty()) return; // No items to use

    // Randomly decide if the AI should use an item this turn
    if (rand() % 3 == 0) { // 1/3 chance to use an item
        int itemIndex = rand() % inventory.size();
        
        // right now using item on self. Need to make logic for targeting others
        useItem(itemIndex, this);
        std::cout << "AI uses an item from inventory.\n";
    }
}



void Player::displayMenu(int roundNumber) {
    int choice = 0;
    while (choice != 4) { // loop until the player chooses to end their turn
        std::cout << "Choose an action:\n";
        std::cout << "1. Move Token\n";
        std::cout << "2. Use Item\n";
        std::cout << "3. End Turn\n";
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleMove(roundNumber);
                break;
            case 2:
                handleUseItem();
                break;
            case 3:
                std::cout << "Ending turn for Player " << getId() << ".\n";
                return;
            default:
                std::cout << "Invalid choice, try again.\n";
                break;
        };
    };
};

void Player::handleMove(int roundNumber) {
    int newX, newY;
    std::cout << "Enter new X and Y coordinates for your move: ";
    std::cin >> newX >> newY;

    if (!validateMove(newX, newY)) {
        std::cout << "Invalid move. Try again.\n";
        return;
    };

    GameObject* objectInCell = board->getCellOccupant(newX, newY);
    if (ItemBox* itemBox = dynamic_cast<ItemBox*>(objectInCell)) {
        interactWithItemBox(itemBox, roundNumber);
    } else {
        moveToken(newX, newY);
        std::cout << "Moved to (" << newX << ", " << newY << ").\n";
    };
};

bool Player::validateMove(int newX, int newY) {
    // ensure the new coordinates are within board limits
    if (newX < 0 || newX >= board->getSize() || newY < 0 || newY >= board->getSize()) {
        return false;
    };

    // check if the new position is adjacent to the current position
    int currentX = token->getPosX();
    int currentY = token->getPosY();
    if (abs(newX - currentX) > 1 || abs(newY - currentY) > 1) {
        return false;
    };

    // check if the destination cell is an item box
    if (ItemBox* itemBox = dynamic_cast<ItemBox*>(board->getCellOccupant(newX, newY))) {
        return true;
    };

    // check if the destination cell is empty
    if (!board->isCellEmpty(newX, newY)) {
        return false;
    };

    return true;
};


void Player::handleUseItem() {
    if (inventory.empty()) {
        std::cout << "No items in inventory to use.\n";
        return;
    };

    std::cout << "Available items to use:\n";
    int itemNumber = 1;
    for (Item* item : inventory) {
        std::cout << itemNumber++ << ": " << item->getName() << " (Type: " << item->getType() << ")\n";
    };

    std::cout << "Enter the index of the item you want to use: ";
    int index;
    std::cin >> index;

    if (index < 1 || index > inventory.size()) {
        std::cout << "Invalid index. Please select a valid item.\n";
        return;
    };

    Item* selectedItem = inventory[index - 1];

    // display all players for targeting
    std::vector<Player*> players = game->getPlayers();
    std::cout << "Select a target player:\n";
    for (size_t i = 0; i < players.size(); ++i) {
        std::cout << (i + 1) << ". Player " << players[i]->getId() << "\n";
    }

    std::cout << "Enter the number of the player to target: ";
    int targetIndex;
    std::cin >> targetIndex;

    if (targetIndex < 1 || targetIndex > players.size()) {
        std::cout << "Invalid player index. No item used.\n";
        return;
    };

    useItem(index - 1, players[targetIndex - 1]);
};

void Player::moveToken(int newX, int newY) {
    if (token != nullptr) {
        token->move(newX, newY);
    };
};

void Player::interactWithItemBox(ItemBox* itemBox, int roundNumber) {
    std::vector<Item*> items = itemBox->chooseItems();  // Method to randomly choose 2 items from the box

    std::cout << "Items available:\n";
    int index = 1;
    for (Item* item : items) {
        std::cout << index++ << ". " << item->getName() << " - Cost: $" << item->getCost()
                  << ", Points: " << item->getPoints() << ", Type: " << item->getType() << "\n";
    };

    std::cout << "Select an item to buy (1 or 2): ";
    int choice;
    std::cin >> choice;

    if (choice == 1 || choice == 2) {
        Item* chosenItem = items[choice - 1];
        if (buyItem(chosenItem, roundNumber)) {
            std::cout << "You bought: " << chosenItem->getName() << "\n";
            itemBox->removeItem(chosenItem);
        } else {
            std::cout << "Not enough budget to buy this item.\n";
        };
    } else {
        std::cout << "Invalid choice.\n";
    };

    // handles if box is now empty
    if (items.empty()) {
        std::cout << "The item box is now empty.\n";
        board->setCellOccupant(itemBox->getPosX(), itemBox->getPosY(), nullptr);
        delete itemBox;
        return;
    } else { // if not, then moves to new empty location
        itemBox->moveToNewLocation(board);
    };
};


bool Player::buyItem(const Item* item, int roundNumber) {
    if (budget >= item->getCost()) {
        budget -= item->getCost();
        points += item->getPoints();
        logItem(formatItemDetails(item, roundNumber));
        return true;
    }
    return false;
};

void Player::useItem(int index, Player* targetPlayer) {
    // hard coded solutions to all the different powerups and debuff interactions. With do if have time.
};

void Player::addItem(Item* item, int roundNumber) {
    if (buyItem(item, roundNumber)) {
        if (item->getType() == "powerUp" || item->getType() == "debuff") {
            inventory.push_back(item);
        } else {
            delete item;  // normal items are logged but not stored
        };
    } else {
        std::cout << "Not enough budget to buy " << item->getName() << std::endl;
    };
};

void Player::clearInventory() {
    for (Item* item : inventory) {
        delete item;
    };
    inventory.clear();
};

std::string Player::formatItemDetails(const Item* item, int roundNumber) const {
    std::ostringstream stream;
    stream << "Round " << roundNumber << ": " << item->getName()
           << ", Cost: " << std::fixed << std::setprecision(2) << item->getCost()
           << ", Points: " << item->getPoints() << ", Type: " << item->getType();
    return stream.str();
};

void Player::logItem(const std::string& itemDetails) {
    receipt.push_back(itemDetails);
};