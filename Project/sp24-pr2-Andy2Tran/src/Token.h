#ifndef TOKEN_H
#define TOKEN_H

#include <vector>
    using std::vector;

#include "GameObject.h"

class Token : public GameObject {
private:

public:
    // constructors
    Token(int posX, int posY);

    void move(int newX, int newY);
};

#endif
