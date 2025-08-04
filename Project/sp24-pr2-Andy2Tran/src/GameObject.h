// Base class for all game objects

#include <string>
    using std::string;

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
private:
    int posX{0};
    int posY{0};

public:
    // constructors
    GameObject(int posX, int posY);

    //destructor
    virtual ~GameObject() = default;

    // getters
    int getPosX();
    int getPosY();

    // setters
    void setPosX(int posX);
    void setPosY(int posY);

};

#endif
