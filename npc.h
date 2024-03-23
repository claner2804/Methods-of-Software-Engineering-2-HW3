//
// Created by Claudia Steiner on 23.03.24.
//

#ifndef HW3_NPC_H
#define HW3_NPC_H

#include "character.h"
#include <string>
#include "item.h"
#include "hero.h"


class Npc : public Character{

public:
    Npc();

    Npc(const std::string& name, int health, int gold, int armor, int magic_resistance );

    virtual ~Npc();

    //vererbte Methode von Character wird überschrieben
    void attack(Character& character) override;



};


#endif //HW3_NPC_H
