#include "GameObject.h"

// constructor
GameObject::GameObject(int posX, int posY) : posX(posX), posY(posY) {  
};

// getters
int GameObject::getPosX() {
    return posX;
};

int GameObject::getPosY() {
    return posY;
};

// setters
void GameObject::setPosX(int posX) {
    this->posX = posX;
};

void GameObject::setPosY(int posY) {
    this->posY = posY;
};
