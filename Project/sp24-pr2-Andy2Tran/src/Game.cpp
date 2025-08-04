#include <iostream>
    using std::cout;
    using std::cin;
    using std::endl;

#include <fstream>
#include <sstream>

#include <cstdlib>
#include <ctime>

#include "Game.h"


// constructor
Game::Game(bool useConfigFile) {
    initializeGame(useConfigFile);
};

// destructor
Game::~Game() {
    for (auto player : players) {
        delete player;
    };
    for (auto item : MasterItemList) {
        delete item;
    };
    for (auto itemBox : ItemBoxes) {
        delete itemBox;
    };
};

// getters
vector<Player*> Game::getPlayers() {
    return players;
};

int Game::getAmountOfRounds() {
    return amountOfRounds;
};

Board& Game::getBoard() {
    return board;
};

// other
void Game::initializeGame(bool useConfigFile) {
    if (useConfigFile) {
        // initalizing from file
        readSettingsFromFile("src/Game-Settings.txt");
    } else {
        // initalizing with default values
        boardSize = 5;
        amountOfPlayers = 4;
        amountOfRounds = 10;
        amountOfItemBoxes = 5;
        itemsPerItemBox = 5;
        startingBudget = 1000;
        powerUpsEnabled = true;
        debuffsEnabled = true;
    };

    board = Board(boardSize);
    initializePlayers();
    initializeItems();
    initializeItemBoxes();
};

void Game::readSettingsFromFile(const string& filename) {
    std::ifstream file(filename);
    string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        string key, value;
        if (std::getline(iss, key, ':') && std::getline(iss, value)) {
            if (key == "boardSize") boardSize = std::stoi(value);
            else if (key == "amountOfPlayers") amountOfPlayers = std::stoi(value);
            else if (key == "amountOfRounds") amountOfRounds = std::stoi(value);
            else if (key == "amountOfItemBoxes") amountOfItemBoxes = std::stoi(value);
            else if (key == "itemsPerItemBox") itemsPerItemBox = std::stoi(value);
            else if (key == "StartingBudget") startingBudget = std::stoi(value);
            else if (key == "powerUpsEnabled") powerUpsEnabled = (value == "true");
            else if (key == "debuffsEnabled") debuffsEnabled = (value == "true");
        };
    };
    file.close();
    std::cout << "Done reading from settings file..." << std::endl; // using for testing if reading works
};

void Game::initializePlayers() {
    std::cout << "Grid will start at (1, 1)" << std:: endl;
    for (int i = 0; i < amountOfPlayers; i++) {
        getBoard().display(); // so players have a visual to where they want to place
        int posX, posY;
        bool validPosition = false;

        do {
            std::cout << "Player " << (i + 1) << ", enter your starting position (format: x y): ";
            std::cin >> posX >> posY;
            posX -= 1;
            posY -= 1;

            if (posX >= 0 && posX < boardSize && posY >= 0 && posY < boardSize && board.isCellEmpty(posX, posY)) {
                validPosition = true;  // the chosen position is both within bounds and empty
            } else {
                std::cout << "Invalid position. Either it's taken or out of bounds. Please try again.\n";
            }
        } while (!validPosition);

        std::cout << "Is player " << (i + 1) << " a computer? (yes/no): ";
        string response;
        std::cin >> response;
        bool isComputer = (response == "yes" || response == "Yes" || response == "y" || response == "Y");

        // create player with the validated position
        Player* player = new Player(i + 1, posX, posY, &board, this, startingBudget, isComputer);
        players.push_back(player);
        board.setCellOccupant(posX, posY, player->getToken()); // Set the player's token on the board
    };
};



void Game::initializeItems() {
    std::ifstream file("src/Master-Item-List.txt");
    string line;

    while (getline(file, line)) {
        std::istringstream iss(line);
        string name, costStr, pointsStr, type;
        getline(iss, name, ',');
        getline(iss, costStr, ',');
        getline(iss, pointsStr, ',');
        getline(iss, type);

        double cost = std::stod(costStr);
        int points = std::stoi(pointsStr);

        Item* newItem = new Item(name, cost, points, type);
        MasterItemList.push_back(newItem);
    };
    file.close();
    std::cout << "Done reading from master items list file..." << std::endl; // using for testing if reading works
};

void Game::initializeItemBoxes() {
    srand(time(NULL));

    for (int i = 0; i < amountOfItemBoxes; ++i) {
        int x, y;
        do {
            x = rand() % boardSize;
            y = rand() % boardSize;
        } while (!board.isCellEmpty(x, y));

        ItemBox* newItemBox = new ItemBox(x, y);

        for (int j = 0; j < itemsPerItemBox; ++j) {
            Item* selectedItem = selectItemBasedOnSettings();
            if (selectedItem) {
                newItemBox->addItem(selectedItem);
            };
        };

        board.setCellOccupant(x, y, newItemBox);
        ItemBoxes.push_back(newItemBox);
    };
};

Item* Game::selectItemBasedOnSettings() {
    int roll = rand() % 7;
    std::vector<Item*> filteredItems;

    if (roll < 4) {  // normal item always available (4/7 probability)
        filteredItems = filterItemsByType("normalItem");
    } else if (roll < 6 && powerUpsEnabled) {  // power up (2/7 probability)
        filteredItems = filterItemsByType("powerUp");
    } else if (debuffsEnabled) {  // debuff (1/7 probability)
        filteredItems = filterItemsByType("debuff");
    } else {
        // If debuffs are not enabled and the roll falls on debuff, reselect as normal item
        return selectItemBasedOnSettings();  // Recursively select again
    };

    if (!filteredItems.empty()) {
        int itemIndex = rand() % filteredItems.size();
        return filteredItems[itemIndex];
    };

    return nullptr;
};

std::vector<Item*> Game::filterItemsByType(string type) {
    std::vector<Item*> filteredItems;
    for (Item* item : MasterItemList) {
        if (item->getType() == type) {
            filteredItems.push_back(item);
        };
    };
    return filteredItems;
};