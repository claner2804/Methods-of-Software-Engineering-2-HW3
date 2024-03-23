//
// Created by Claudia Steiner on 23.03.24.
//

#include "npc.h"
#include <iostream>

Npc::Npc() {}

Npc::Npc(const std::string& name, int health, int gold, int armor, int magic_resistance) :  Character(name, health, gold, armor, magic_resistance) {}


Npc::~Npc() {
    std::cout << "NPC " << name << " ist nicht mehr da. " << std::endl;
}

void Npc::attack(Character& character) {
    int dice = 5 + std::rand() % 11;
    std::cout << name << " trifft " << getName() << " fuer " << dice << " Lebenspunkte!" << std::endl;
    setHealth(getHealth() - dice);
}


