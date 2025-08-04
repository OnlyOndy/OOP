// Title  : TicTacToe.h
// Desc   : Header for TicTacToe.cpp class
// Name   : An Tran

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>

class TicTacToe {
private:
    int size;
    char** board;

public:
    // static constants
    static const char PLAYER_MARK;
    static const char COMPUTER_MARK;
    static const char EMPTY_SPACE;

    // constructor + destructor
    explicit TicTacToe(int size);
    ~TicTacToe();

    // overides
    friend std::ostream& operator<<(std::ostream& os, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& is, TicTacToe& game);

    // public member functions

    // checks if the board is full.
    bool isFull() const;

    // resets the board to start a new game.
    void reset();

    // generates a move for the computer.
    void computerMove();

    // checks if a player has won.
    bool checkWin(char player) const;

    // checks if a move is valid in board space
    bool isValidMove(int x, int y) const;

    // makes board spot with current player's mark
    void makeMove(int x, int y, char playerMark);
};

#endif


