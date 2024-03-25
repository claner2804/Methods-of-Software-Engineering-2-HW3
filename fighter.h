//
// Created by Claudia Steiner on 23.03.24.
//

#ifndef HW3_FIGHTER_H
#define HW3_FIGHTER_H

#include "npc.h"

class Fighter : public Npc{

    // Die friend-Deklaration für den Operator <<
    friend std::ostream& operator<<(std::ostream& os, const Fighter& fighter);

private:
    int strength;

public:
    Fighter();

    Fighter(const std::string& name, int health, int gold, int armor, int magic_resistance, int strength);

    virtual ~Fighter();

    void attack(Character& character) override;

    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        if (strength >= 0) {
            this->strength = strength;
        }
    }



};


#endif //HW3_FIGHTER_H
