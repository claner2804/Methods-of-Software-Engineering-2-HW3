
#include "hero.h"
#include <cstdlib>
#include <iostream>
#include "character.h"

//Konstruktor und Destruktor
Hero::Hero() {}


Hero::Hero(const std::string &name, int health, int gold, int armor, int magic_resistance) : Character(name, health, gold, armor, magic_resistance) {
    // Initialisierung der Ausrüstung des Helden mit leeren Gegenständen
    for (int t = 0; t < 2; t++) {
        gear[t] = Item();
    }
}

Hero::~Hero() {
    std::cout << "HeldIn " << name << " verabschiedet sich und reitet in den Sonnenuntergang... " << std::endl;
}




void Hero::attack(Character& character) {
    int damage = rand() % 11 + 15 - character.getArmor();
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




// Diese Methode verkauft ein Item aus dem Inventar des Helden
Item Hero::sellItem(int index) {
    // Überprüfung, ob der angegebene Index gültig ist
    if (index >= 0 && index < 10) {
        // Überprüfung, ob das Item an dem angegebenen Index gültig ist
        if (inventory[index].isIsValid()) {
            // Speichern des Items in einer temporären Variable
            Item item = inventory[index];
            // Erhöhung des Goldes des Helden um den Goldwert des Items
            setGold(gold += inventory[index].getGold());
            // Setzen des Items auf ungültig
            inventory[index].setIsValid(false);
            // Rückgabe des verkauften Items
            return item;
        }
    }
    // Wenn der angegebene Index ungültig ist oder das Item ungültig ist, wird ein leeres Item zurückgegeben
    return Item();
}




bool Hero::fight(Character& enemy) {
    while (health > 0 && enemy.getHealth() > 0) {
        attack(enemy);
        if (enemy.getHealth() > 0) {
            enemy.attack(*this);
        }
    }
    if (enemy.getHealth() <= 0) {
        std::cout << enemy.getName() << " fiel in Ohnmacht! " << name << " hat noch " << health << " Lebenspunkte uebrig!" << std::endl;
        return true;
    } else {
        std::cout << name << " fiel in Ohnmacht! GAME OVER!" << std::endl;
        return false;
    }
}


const Item* Hero::getInventory(int i) const {
    if (i >= 0 && i < 2) {
        return &inventory[i];
    } else {
        return nullptr;
    }
}


int Hero::addInventarItem(const Item& item) {
    for (int i = 0; i < 10; i++) {
        if (!inventory[i].isIsValid()) {
            inventory[i] = item;
            return i;
        }
    }
    return -1;
}

Item Hero::removeInventarItem(int slot) {
    if (slot >= 0 && slot < 10) {
        Item tmp = inventory[slot];
        inventory[slot].setIsValid(false);
        return tmp;
    }
    return Item();
}

int Hero::addEquipmentItem(const Item& item) {
    for (int i = 0; i < 2; i++) {
        if (!gear[i].isIsValid()) {
            gear[i] = item;
            return i;
        }
    }
    return -1;
}

Item Hero::removeEquipmentItem(int slot) {
    if (slot >= 0 && slot < 2) {
        Item tmp = gear[slot];
        gear[slot].setIsValid(false);
        return tmp;
    }
    return Item();
}

