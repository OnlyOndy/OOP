#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Token.h"
#include "GameObject.h"
#include "Board.h"
#include "ItemBox.h"
#include <string>
#include <vector>
    using std::vector;

class Board;
class ItemBox;
class Player;

class Game {
private:
    Board board;
    vector<Player*> players;
    vector<Item*> MasterItemList;
    vector<ItemBox*> ItemBoxes;
    bool useConfigFile;
    int boardSize;
    int amountOfPlayers;
    int amountOfRounds;
    int amountOfItemBoxes;
    int itemsPerItemBox;
    double startingBudget;
    bool powerUpsEnabled;
    bool debuffsEnabled;

public:
    Game(bool useConfigFile);
    ~Game();

    // getter
    vector<Player*> getPlayers();
    int getAmountOfRounds();
    Board& getBoard();

    void initializeGame(bool useConfigFile);
    void readSettingsFromFile(const std::string& filename);
    void initializePlayers();
    void initializeItems();
    void initializeItemBoxes();
    Item* selectItemBasedOnSettings(); // using method for recursion
    vector<Item*> filterItemsByType(string type);
};

#endif
