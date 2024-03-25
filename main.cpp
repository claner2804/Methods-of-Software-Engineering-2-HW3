
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "hero.h"
#include "character.h"
#include "npc.h"
#include "sorcerer.h"
#include "fighter.h"
#include "item.h"




// Diese Funktion ermöglicht es einem Helden, ein zufälliges Item von einem Charakter zu plündern
void lootRandomItem(Hero& hero, Character& character) {


    // Ein zufälliges Item wird aus dem Inventar des Charakters entfernt
    Item item = character.retrieveRandomLoot();
    // Überprüfung, ob das entfernte Item gültig ist
    if (item.isIsValid()) {
        // Versuch, das Item zum Inventar des Helden hinzuzufügen
        if (hero.addInventarItem(item) >= 0) {
            // Ausgabe einer Nachricht, dass das Item zum Inventar des Helden hinzugefügt wurde
            std::cout << "Gegenstand " << item.getName() << " wurde zum Inventar der Heldin hinzugefügt." << std::endl;
        } else {
            // Ausgabe einer Nachricht, dass im Inventar des Helden kein Platz mehr für das Item ist
            std::cout << "Im Inventar der Heldin ist leider kein Platz mehr für " << item.getName() << "." <<std::endl;
        }
    } else {
        // Ausgabe einer Nachricht, dass der Charakter keinen brauchbaren Gegenstand im Inventar hat
        std::cout << character.getName() << " hat leider keinen brauchbaren Gegenstand im Inventar." << std::endl;
    }
}


int main() {
    std::srand(std::time(nullptr));

    // Initialisierung des Helden
    Hero Hero("Annina", 500, 150, 12, 100);

    // Initialisierung des Charakters Matthias
    Npc matthias("Matthias", 70, 100, 10, 30);
    Item item1("Zaubertrank", 120);
    matthias.addInventarItem(item1);
    Item item2("Schwert", 80);
    matthias.addInventarItem(item2);

    // Initialisierung des Charakters Pascal
    Npc pascal("Pascal", 80, 100, 4, 30);
    Item item3("Diamant", 300);
    pascal.addInventarItem(item3);
    Item item4("Zauberstab", 80);
    pascal.addInventarItem(item4);


    std::cout << item1 << std::endl;
    std::cout << item2 << std::endl;
    std::cout << item3 << std::endl;
    std::cout << item4 << std::endl;

    //leerzeile einfügen
    std::cout << std::endl;

    std::cout << Hero << std::endl;
    std::cout << matthias << std::endl;

    //leerzeile einfügen
    std::cout << std::endl;


    // Der Held kämpft gegen die Charaktere Matthias und Pascal
    if (Hero.fight(matthias)) {
        lootRandomItem(Hero, matthias);

        //leerzeile einfügen
        std::cout << std::endl;
        //leerzeile einfügen
        std::cout << std::endl;

        std::cout << Hero << std::endl;
        std::cout << pascal << std::endl;

        //leerzeile einfügen
        std::cout << std::endl;

        if (Hero.fight(pascal)) {
            lootRandomItem(Hero, pascal);

            //leerzeile einfügen
            std::cout << std::endl;

            // Der Held verkauft alle Items im Inventar
            for (int t = 0; t < 10; t++) {
                Item item = Hero.sellItem(t);
                if (item.isIsValid()) {
                    std::cout << item.getName() << " wurde für " << item.getGold() << " Gold verkauft" << std::endl;
                }
            }
        }
    }

//leerzeile einfügen
    std::cout << std::endl;



}
