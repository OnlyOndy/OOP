#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Game.h"

class GameManager {
private:
    Game& game;
    int currentRound;
    int totalRounds;

public:
    GameManager(Game& game, int totalRounds);
    void startGame();
    void playRound();
    void endGame();
    bool isGameOver() const;
    void displayReceipt(Player* player);
};

#endif
