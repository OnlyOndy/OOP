#include <iostream>
#include "Game.h"
#include "GameManager.h"

int main() {
    std::cout << "Welcome to the Shopping Spree Showdown!" << std::endl;
    std::cout << "Please select an option:" << std::endl;
    std::cout << "1. Start a default game" << std::endl;
    std::cout << "2. Start with custom game settings" << std::endl;

    int choice;
    std::cin >> choice;

    bool useConfigFile = choice == 2;
    Game game(useConfigFile);

    GameManager gameManager(game, game.getAmountOfRounds());

    // Start the game
    gameManager.startGame();

    return 0;
};
