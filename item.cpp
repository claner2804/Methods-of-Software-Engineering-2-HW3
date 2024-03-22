
#include "item.h"

void Item::initItem(const std::string& name, int gold) {
    this->name = name;
    if (gold >= 0) {
        this->gold = gold;
    } else {
        this->gold = 0;
    }
    isValid = true;
}

void Item::initItem() {
    isValid = false;
}