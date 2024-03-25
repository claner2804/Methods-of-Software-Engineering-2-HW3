//
// Created by Claudia Steiner on 23.03.24.
//

#include "npc.h"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Npc &npc) {
    os << "Die Kampfarena betritt NPC " << npc.getName() << " mit "
       << npc.getHealth() << " Gesundheitspunkten, "
       << npc.getArmor() << " Rüstungspunkten, "
       << npc.getMagicResistance() << " Magieresistenzpunkten und "
       << npc.getGold() << " Goldstücken im Beutel.";
    return os;
}

Npc::Npc() {}

Npc::Npc(const std::string& name, int health, int gold, int armor, int magic_resistance) :  Character(name, health, gold, armor, magic_resistance) {}


Npc::~Npc() {
    std::cout << "NPC " << name << " ist nicht mehr da. " << std::endl;
}

void Npc::attack(Character& character) {
    int damage = 5 + std::rand() % 11;
    if (damage < 0) {
        damage = 0;
    }
    std::cout << name << " trifft " << character.getName() << " fuer " << damage << " Lebenspunkte!" << std::endl;
    if (character.getHealth() - damage < 0) {
        character.setHealth(0);
    } else {
        character.setHealth(character.getHealth() - damage);
    }
}




