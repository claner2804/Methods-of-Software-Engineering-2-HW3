
#ifndef HERO_H_
#define HERO_H_

#include "item.h"
#include <string>

// forward declarations
class Character;

class Hero {
private:
    std::string name;
    int health;
    int gold;
    Item inventory[10];
    Item gear[10];

public:
    void initHero(const std::string& name, int health, int gold);

    void attack(Character& enemy);

    Item sellItem(int index);

    bool fight(Character& enemy);



// Diese Methode gibt einen Zeiger auf ein Ausrüstungsitem an einer bestimmten Position zurück
    const Item* getGear(int i) const {
        // Überprüfung, ob der angegebene Index gültig ist
        if (i >= 0 && i < 2) {
            // Rückgabe eines Zeigers auf das Ausrüstungsitem an der angegebenen Position
            return &gear[i];
        } else {
            // Wenn der angegebene Index ungültig ist, wird ein Nullzeiger zurückgegeben
            return nullptr;
        }
    }



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

    int addEquipmentItem(const Item& item);
    Item removeEquipmentItem(int slot);
};



#endif /* HERO_H_ */