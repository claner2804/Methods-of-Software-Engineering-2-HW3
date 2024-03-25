#include <iostream>
#include "item.h"

Item::Item() {
    isValid = false;
}

Item::Item(const std::string &name, int gold) {
    this->name = name;
    if (gold >= 0) {
        this->gold = gold;
    } else {
        this->gold = 0;
    }
    isValid = true;
}

Item::~Item() {}

// Die Operator-Überladungsfunktion außerhalb der Klassendefinition.
std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << "Neues Item erschaffen: " << item.getName() << ", Wert: " << item.getGold() << " Gold ";
    if (!item.isIsValid()) {
        os << "ungültig";
    }
    return os;
}







