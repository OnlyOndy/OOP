#ifndef ITEM_H
#define ITEM_H

#include <string>
    using std::string;

#include "Player.h"

class Board;
class Game;
class Player;


class Item {
private:
    string name;
    double cost;
    int points;
    string type;

public:
    Item(string name, double cost, int points, string type);

    virtual ~Item();

    // getters
    string getName() const;
    double getCost() const;
    int getPoints() const;
    string getType() const;

    // setters
    void setName(const std::string& newName);
    void setCost(double newCost);
    void setPoints(int newPoints);
    void setType(string newType);


    void use(Player* targetPlayer);
};

#endif
