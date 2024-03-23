
#include "character.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "hero.h"

//konstruktoren und destruktoren

Character::Character() {}


Character::Character(const std::string& name, int health, int gold, int armor, int magic_resistance) {
    this->name = name;
    this->health = health;
    this->gold = gold;
    this->armor = armor;
    this->magic_resistance = magic_resistance;
    for (int t = 0; t < 10; t++) {
        inventory[t] = Item();
    }
}

Character::~Character() {}



void Character::attack(Character& character) {}

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



// Diese Methode entfernt ein zufälliges Item aus dem Inventar des Charakters
Item Character::retrieveRandomLoot() {
    // Durchlaufen des Inventars
    for (int i = 0; i < 10; i++) {
        // Generierung einer zufälligen Zahl zwischen 0 und 9
        int dice = rand() % 10;
        // Entfernen des Items an der Position "dice" aus dem Inventar
        Item item = removeInventarItem(dice);
        // Überprüfung, ob das entfernte Item gültig ist
        if (item.isIsValid()) {
            // Rückgabe des entfernten Items
            return item;
        }
    }
    // Wenn kein gültiges Item gefunden wurde, Rückgabe eines leeren Items
    return Item();
}





