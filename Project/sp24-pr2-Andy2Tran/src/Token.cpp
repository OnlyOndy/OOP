#include "Token.h"

// Constructor
Token::Token(int posX, int posY) : GameObject(posX, posY) {};

void Token::move(int newX, int newY) {
    setPosX(newX);
    setPosY(newY);
};