
#include "character.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "hero.h"


void Character::initCharacter(const std::string& name, int health, int gold) {
    this->name = name;
    this->health = health;
    this->gold = gold;
    for (int t = 0; t < 10; t++) {
        inventory[t].initItem();
    }
}

void Character::attack(Hero& hero) {
    int dice = 5 + std::rand() % 11;
    std::cout << name << " trifft " << hero.getName() << " fuer " << dice << " Lebenspunkte!" << std::endl;
    hero.setHealth(hero.getHealth() - dice);
}


const Item* Character::getInventory(int i) const {
    if (i >= 0 && i < 10) {
        return &inventory[i];
    } else {
        return nullptr;
    }
}

int Character::addInventarItem(const Item& item) {
    for (int i = 0; i < 10; i++) {
        if (!inventory[i].isIsValid()) {
            inventory[i] = item;
            return i;
        }
    }
    return -1;
}

Item Character::removeInventarItem(int slot) {
    if (slot >= 0 && slot < 10) {
        Item tmp = inventory[slot];
        inventory[slot].setIsValid(false);
        return tmp;
    }
    Item item;
    item.initItem();
    return item;
}

