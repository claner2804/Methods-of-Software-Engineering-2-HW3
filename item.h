
#ifndef ITEM_H_
#define ITEM_H_

#include <string>


class Item {
private:
    std::string name;
    int gold;
    bool isValid;

public:

    Item();
    Item(const std::string& name, int gold);
    virtual ~Item();


    int getGold() const {
        return gold;
    }

    void setGold(int gold) {
        if (gold >= 0) {
            this->gold = gold;
        }
    }

    bool isIsValid() const {
        return isValid;
    }

    void setIsValid(bool isValid) {
        this->isValid = isValid;
    }

    const std::string& getName() const {
        return name;
    }

    void setName(const std::string &name) {
        if (name.size() > 0) {
            this->name = name;
        }
    }
};

#endif /* ITEM_H_ */
