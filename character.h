
#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "item.h"
#include <string>

// forward declarations
class Hero;


class Character {
protected:
    std::string name;
    int health;
    int gold;
    Item inventory[10];
    int armor;
    int magic_resistance;

public:

    //constructor
    Character();

    Character(const std::string& name, int health, int gold, int armor, int magic_resistance);

    //destructor
    virtual ~Character();


    void attack(Hero& hero);

    int getGold() const {
        return gold;
    }

    void setGold(int gold) {
        if (gold >= 0) {
            this->gold = gold;
        }
    }

    int getHealth() const {
        return health;
    }

    void setHealth(int health) {
        if (health < 0) {
            health = 0;
        }
        this->health = health;
    }

    const Item* getInventory(int i) const;

    const std::string& getName() const {
        return name;
    }

    int addInventarItem(const Item& item);
    Item removeInventarItem(int slot);
};



#endif /* CHARACTER_H_ */