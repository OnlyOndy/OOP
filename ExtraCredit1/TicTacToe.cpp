// Title  : Address.cpp
// Desc   : Implementation for TicTacToe class
// Name   : An Tran

#include "TicTacToe.h"
#include <cstdlib>
#include <ctime>

// static constants
const char TicTacToe::PLAYER_MARK = 'X';
const char TicTacToe::COMPUTER_MARK = 'O';
const char TicTacToe::EMPTY_SPACE = '-';

// constructor
TicTacToe::TicTacToe(int size) : size(size > 10 ? 10 : (size < 3 ? 3 : size)) {
    board = new char*[this->size];
    for (int i = 0; i < this->size; ++i) {
        board[i] = new char[this->size];
        std::fill(board[i], board[i] + this->size, EMPTY_SPACE);
    };
};

// destructor
TicTacToe::~TicTacToe() {
    for (int i = 0; i < size; ++i) {
        delete[] board[i];
    };
    delete[] board;
};

// overloads
std::ostream& operator<<(std::ostream& os, const TicTacToe& game) {
    for (int i = 0; i < game.size; ++i) {
        for (int j = 0; j < game.size; ++j) {
            os << game.board[i][j] << ' ';
        };
        os << '\n';
    };
    return os;
};

std::istream& operator>>(std::istream& is, TicTacToe& game) {
    int x, y;
    if (is >> x >> y) {
        if (game.isValidMove(x, y)) {
            game.makeMove(x, y, TicTacToe::PLAYER_MARK);
        } else {
            is.setstate(std::ios::failbit);
        };
    };
    return is;
};

// public member functions
bool TicTacToe::isFull() const {
    for (int i = 0; i < size; ++i) {
        if (std::find(board[i], board[i] + size, EMPTY_SPACE) != (board[i] + size)) {
            return false;
        };
    };
    return true;
};

void TicTacToe::reset() {
    for (int i = 0; i < size; ++i) {
        std::fill(board[i], board[i] + size, EMPTY_SPACE);
    };
};

void TicTacToe::computerMove() {
    if (isFull()) return;
    int x, y;
    do {
        x = std::rand() % size;
        y = std::rand() % size;
    } while (board[x][y] != EMPTY_SPACE);
    makeMove(x, y, COMPUTER_MARK);
};

bool TicTacToe::checkWin(char player) const {
    // Check for three consecutive marks in rows
    for (int i = 0; i < size; ++i) {
        int count = 0;
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == player) {
                count++;
                if (count == 3) return true;
            } else {
                count = 0;
            };
        };
    };

    // Check for three consecutive marks in columns
    for (int j = 0; j < size; ++j) {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (board[i][j] == player) {
                count++;
                if (count == 3) return true;
            } else {
                count = 0;
            };
        };
    };

    // Check diagonals for three consecutive marks
    // Main diagonals and anti-diagonals are checked with possible offsets to include all diagonal lines
    // that can fit at least three cells
    for (int offset = 0; offset <= size - 3; ++offset) {
        int countMain = 0, countAnti = 0, countAntiMain = 0, countMainAnti = 0;
        for (int i = 0; i < size - offset; ++i) {
            // Main diagonal from top-left to bottom-right
            if (board[i + offset][i] == player) {
                countMain++;
                if (countMain == 3) return true;
            } else {
                countMain = 0;
            };

            if (board[i][i + offset] == player && offset != 0) {
                countAnti++;
                if (countAnti == 3) return true;
            } else {
                countAnti = 0;
            };

            // Anti-diagonal from top-right to bottom-left
            if (board[i + offset][size - 1 - i] == player) {
                countAntiMain++;
                if (countAntiMain == 3) return true;
            } else {
                countAntiMain = 0;
            };

            if (board[i][size - 1 - i - offset] == player && offset != 0) {
                countMainAnti++;
                if (countMainAnti == 3) return true;
            } else {
                countMainAnti = 0;
            };
        };
    };

    return false; // If no win condition is met
};

bool TicTacToe::isValidMove(int x, int y) const {
    return x >= 0 && x < size && y >= 0 && y < size && board[x][y] == EMPTY_SPACE;
};

void TicTacToe::makeMove(int x, int y, char playerMark) {
    board[x][y] = playerMark;
};

