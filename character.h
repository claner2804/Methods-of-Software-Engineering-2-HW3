
#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "item.h"
#include <string>

// forward declarations
struct Hero;


class Character {
private:
    std::string name;
    int health;
    int gold;
    Item inventory[10];

public:
    void initCharacter(const std::string& name, int health, int gold);

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