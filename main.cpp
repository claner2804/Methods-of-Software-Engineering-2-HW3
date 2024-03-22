
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "hero.h"
#include "character.h"


void lootRandomItem(Hero& hero, Character& chr) {
    for (int i = 0; i < 10; i++) {
        int dice = rand() % 10;
        Item item = chr.removeInventarItem(dice);
        if (item.isIsValid()) {
            if (hero.addInventarItem(item) >= 0) {
                std::cout << "Gegenstand " << item.getName() << " wurde zum Inventar der Heldin hinzugefügt." << std::endl;
            } else {
                std::cout << "Im Inventar der Heldin ist leider kein Platz mehr für " << item.getName() << "." <<std::endl;
            }
            return;
        }
    }
    std::cout << chr.getName() << " hat leider keinen brauchbaren Gegenstand im Inventar." << std::endl;
}


int main() {
    std::srand(std::time(nullptr));

    Hero hero;
    hero.initHero("Annina", 300, 10);

    Character matthias;
    matthias.initCharacter("Matthias", 50, 100);
    Item item1;
    item1.initItem("Zaubertrank", 120);
    matthias.addInventarItem(item1);
    Item item2;
    item2.initItem("Schwert", 80);
    matthias.addInventarItem(item2);

    Character pascal;
    pascal.initCharacter("Pascal", 100, 100);
    Item item3;
    item3.initItem("Diamant", 300);
    pascal.addInventarItem(item3);
    Item item4;
    item4.initItem("Zauberstab", 80);
    pascal.addInventarItem(item4);

    if (hero.fight(matthias)) {
        lootRandomItem(hero, matthias);
        if (hero.fight(pascal)) {
            lootRandomItem(hero, pascal);
            for (int t = 0; t < 10; t++) {
                Item item = hero.sellItem(t);
                if (item.isIsValid()) {
                    std::cout << item.getName() << " wurde für " << item.getGold() << " Gold verkauft" << std::endl;
                }
            }
        }
    }
}
