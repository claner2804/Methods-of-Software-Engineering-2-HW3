
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "hero.h"
#include "character.h"


// Diese Funktion ermöglicht es einem Helden, ein zufälliges Item von einem Charakter zu plündern
void lootRandomItem(Hero& hero, Character& chr) {
    // Die Schleife wird bis zu 10 Mal durchlaufen
    for (int i = 0; i < 10; i++) {
        // Eine zufällige Zahl zwischen 0 und 9 wird generiert
        int dice = rand() % 10;
        // Das Item an der Position "dice" wird aus dem Inventar des Charakters entfernt
        Item item = chr.removeInventarItem(dice);
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
            // Beenden der Funktion, da ein Item erfolgreich geplündert wurde
            return;
        }
    }
    // Ausgabe einer Nachricht, dass der Charakter keinen brauchbaren Gegenstand im Inventar hat
    std::cout << chr.getName() << " hat leider keinen brauchbaren Gegenstand im Inventar." << std::endl;
}


int main() {
    std::srand(std::time(nullptr));

    // Initialisierung des Helden
    Hero hero;
    hero.initHero("Annina", 300, 10);

    // Initialisierung des Charakters Matthias
    Character matthias;
    matthias.initCharacter("Matthias", 50, 100);
    Item item1;
    item1.initItem("Zaubertrank", 120);
    matthias.addInventarItem(item1);
    Item item2;
    item2.initItem("Schwert", 80);
    matthias.addInventarItem(item2);

    // Initialisierung des Charakters Pascal
    Character pascal;
    pascal.initCharacter("Pascal", 100, 100);
    Item item3;
    item3.initItem("Diamant", 300);
    pascal.addInventarItem(item3);
    Item item4;
    item4.initItem("Zauberstab", 80);
    pascal.addInventarItem(item4);

    // Der Held kämpft gegen den Charakter Matthias
    if (hero.fight(matthias)) {
        lootRandomItem(hero, matthias);
        if (hero.fight(pascal)) {
            lootRandomItem(hero, pascal);
            // Der Held verkauft alle Items im Inventar
            for (int t = 0; t < 10; t++) {
                Item item = hero.sellItem(t);
                if (item.isIsValid()) {
                    std::cout << item.getName() << " wurde für " << item.getGold() << " Gold verkauft" << std::endl;
                }
            }
        }
    }
}
