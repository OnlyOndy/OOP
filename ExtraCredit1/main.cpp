// Title  : main.cpp
// Desc   : Testing
// Name   : An Tran

#include "TicTacToe.h"

#include <iostream>
    using std::cout;
    using std::cin;

#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed random number generator
    
    int boardSize;
    int option;
    bool running = true;

    while (running) {
        cout << "1. Start new game\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        if (option == 1) {
            cout << "Enter the size of the Tic-Tac-Toe board (3-10): ";
            cin >> boardSize;

            TicTacToe game(boardSize);
            char currentPlayer = 'X'; // Player X always starts
            bool gameEnd = false;

            while (!gameEnd) {
                cout << game; // Display the board using the overloaded << operator

                // Player's turn
                if (currentPlayer == 'X') {
                    int x, y;
                    cout << "Player X, enter your move (row column, 1-based index): ";
                    cin >> x >> y;
                    x -= 1; // Adjust from 1-based to 0-based index
                    y -= 1;

                    if (game.isValidMove(x, y)) {
                        game.makeMove(x, y, currentPlayer);
                    } else {
                        cout << "Invalid move. Try again." << std::endl;
                        continue;
                    };
                } else {
                    // Computer's turn
                    game.computerMove();
                    cout << "Computer's move:" << std::endl;
                };

                // Check for win or draw
                if (game.checkWin(currentPlayer)) {
                    cout << game; // Display the board
                    cout << "Player " << currentPlayer << " wins!" << std::endl;
                    gameEnd = true;
                } else if (game.isFull()) {
                    cout << game; // Display the board
                    cout << "The game is a draw." << std::endl;
                    gameEnd = true;
                };

                // Switch player for the next turn
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            };
        } else if (option == 2) {
            running = false;
            cout << "Exiting game." << std::endl;
        } else {
            cout << "Invalid option. Please try again." << std::endl;
        };
    };

    return 0;
};
