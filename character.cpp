
#include "character.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "hero.h"

//konstruktoren und destruktoren

Character::Character() {}


Character::Character(const std::string& name, int health, int gold) {
    this->name = name;
    this->health = health;
    this->gold = gold;
    for (int t = 0; t < 10; t++) {
        inventory[t] = Item();
    }
}

Character::~Character() {}





void Character::attack(Hero& hero) {
    int dice = 5 + std::rand() % 11;
    std::cout << name << " trifft " << hero.getName() << " fuer " << dice << " Lebenspunkte!" << std::endl;
    hero.setHealth(hero.getHealth() - dice);
}

const Item* Character::getInventory(int i) const {
    if (i >= 0 && i < 10) {
        return &inventory[i];
    } else {
        return nullptr;
    }
}



// Diese Methode fügt ein Item zum Inventar des Charakters hinzu
int Character::addInventarItem(const Item& item) {
    // Durchlaufen des Inventars
    for (int i = 0; i < 10; i++) {
        // Überprüfung, ob der aktuelle Slot im Inventar leer ist
        if (!inventory[i].isIsValid()) {
            // Hinzufügen des Items zum aktuellen Slot
            inventory[i] = item;
            // Rückgabe des Index des Slots, in den das Item eingefügt wurde
            return i;
        }
    }
    // Wenn kein leerer Slot gefunden wurde, Rückgabe von -1
    return -1;
}



// Diese Methode entfernt ein Item aus dem Inventar des Charakters
Item Character::removeInventarItem(int slot) {
    // Überprüfung, ob der angegebene Slot gültig ist
    if (slot >= 0 && slot < 10) {
        // Speichern des Items aus dem angegebenen Slot in einer temporären Variable
        Item tmp = inventory[slot];
        // Setzen des Slots auf ungültig
        inventory[slot].setIsValid(false);
        // Rückgabe des entfernten Items
        return tmp;
    }
    // Wenn der angegebene Slot ungültig ist, wird ein leeres Item zurückgegeben
    return Item();
}


