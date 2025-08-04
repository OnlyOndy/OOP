#include "GameManager.h"
#include <iostream>

GameManager::GameManager(Game& game, int totalRounds)
    : game(game), totalRounds(totalRounds), currentRound(0) {};

void GameManager::startGame() {
    game.getBoard().display();
    while (!isGameOver()) {
        playRound();
    };
    endGame();
};

void GameManager::playRound() {
    std::cout << "Round " << currentRound + 1 << " of " << totalRounds << std::endl;

    for (Player* player : game.getPlayers()) {
        player->takeTurn(currentRound);
        game.getBoard().display();
    };

    currentRound++;
};

bool GameManager::isGameOver() const {
    return currentRound >= totalRounds;
};

void GameManager::endGame() {
    Player* winner = nullptr;
    int highestPoints = 0;

    // determine the player with the highest points
    for (Player* player : game.getPlayers()) {
        if (player->getPoints() > highestPoints) {
            highestPoints = player->getPoints();
            winner = player;
        };
    };

    // display final game state and winner
    std::cout << "Game over! Here are the final results:\n";
    game.getBoard().display();  // display the final state of the board

    if (winner != nullptr) {
        std::cout << "Winner is Player " << winner->getId() << " with " << winner->getPoints() << " points.\n";
        displayReceipt(winner);
    } else {
        std::cout << "No winner this game.\n";
    };
};

void GameManager::displayReceipt(Player* player) {
    std::cout << "Receipt for Player " << player->getId() << ":\n";
    for (const std::string& itemDetail : player->getReceipt()) {
        std::cout << itemDetail << std::endl;
    };
};