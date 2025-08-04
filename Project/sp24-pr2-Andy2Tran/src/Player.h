#ifndef PLAYER_H
#define PLAYER_H

#include "Token.h"
#include "Item.h"
#include "ItemBox.h"
#include "Board.h"
#include "Game.h"
#include <vector>
#include <string>

class Board;
class Game;

class Player {
private:
    int id;
    Token* token;
    Board* board;
    Game* game;
    std::vector<Item*> inventory;  // inventory holding power-ups and debuffs
    std::vector<std::string> receipt;  // stores detailed information about all acquired items
    double budget;
    int points;
    bool isComputer;

public:
    Player(int id, int posX, int posY, Board* board, Game* game, double budget, bool isComputer);
    ~Player();

    int getId() const;
    Token* getToken() const;
    bool getIsComputer() const;
    const std::vector<std::string>& getReceipt() const;
    double getBudget() const;
    int getPoints() const;

    void setBudget(double newBudget);

    void takeTurn(int currentRound);
    void aiDecideMove(int roundNumber);
    void aiDecideUseItem(int roundNumber);
    void displayMenu(int roundNumber);
    void handleMove(int roundNumber);
    bool validateMove(int newX, int newY);
    void handleUseItem();

    void moveToken(int newX, int newY);
    void interactWithItemBox(ItemBox* itemBox, int roundNumber);
    bool buyItem(const Item* item, int roundNumber);
    void useItem(int index, Player* targetPlayer);

    void addItem(Item* item, int roundNumber);
    void clearInventory();
    std::string formatItemDetails(const Item* item, int roundNumber) const;
    void logItem(const std::string& itemDetails);
};

#endif
