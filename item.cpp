
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




