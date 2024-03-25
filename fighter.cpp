//
// Created by Claudia Steiner on 23.03.24.
//

#include "fighter.h"
#include <iostream>


std::ostream &operator<<(std::ostream &os, const Fighter &fighter) {
    os << "Die Kampfarena betritt Fighter " << fighter.getName() << " mit "
       << fighter.getHealth() << " Gesundheitspunkten, "
       << fighter.getArmor() << " Rüstungspunkten, "
       << fighter.getMagicResistance() << " Magieresistenzpunkten, "
       << fighter.getGold() << " Goldstücken im Beutel und "
       << fighter.getStrength() << " Stärkepunkten.";
    return os;
}



Fighter::Fighter() { }


Fighter::Fighter(const std::string &name, int health, int gold, int armor, int magic_resistance, int strength) : Npc(name, health, gold, armor, magic_resistance) {
    this->strength = strength;
}

void Fighter::attack(Character &character) {
    int damage = rand() % 6 + 5 + this->getStrength() - character.getArmor();
    if (damage < 0) {
        damage = 0;
    }
    std::cout << this->getName() << " trifft " << character.getName() << " fuer " << damage << " Lebenspunkte!" << std::endl;
    if (character.getHealth() - damage < 0) {
        character.setHealth(0);
    } else {
        character.setHealth(character.getHealth() - damage);
    }
}

Fighter::~Fighter() { }

