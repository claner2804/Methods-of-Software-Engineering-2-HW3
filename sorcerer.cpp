//
// Created by Claudia Steiner on 23.03.24.
//

#include "sorcerer.h"
#include <iostream>

Sorcerer::Sorcerer(const std::string &name, int health, int gold, int armor, int magic_resistance, int magicPower) : Npc(name, health, gold, armor, magic_resistance) {
    this->magicPower = magicPower;
}

void Sorcerer::attack(Character &character) {
    int damage = rand() % 6 + 5 + this->getMagicPower() - character.getMagicResistance();
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


