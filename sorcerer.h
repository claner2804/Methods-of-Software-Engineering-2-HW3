//
// Created by Claudia Steiner on 23.03.24.
//

#ifndef HW3_SORCERER_H
#define HW3_SORCERER_H


#include "npc.h"

class Sorcerer : public Npc{
private:
    int magicPower;

public:
    void attack(Character& character) override;

    int getMagicPower() const {
        return magicPower;
    }

    void setMagicPower(int magicPower) {
        if (magicPower >= 0) {
            this->magicPower = magicPower;
        }
    }

    Sorcerer();

    Sorcerer(const std::string& name, int health, int gold, int armor, int magic_resistance, int magicPower);

};


#endif //HW3_SORCERER_H
