
#ifndef HERO_H_
#define HERO_H_

#include "item.h"
#include <string>
#include "character.h"



class Hero : public Character {

    // Die friend-Deklaration für den Operator <<
    friend std::ostream& operator<<(std::ostream& os, const Hero& hero);

private:
    Item gear[10];

public:

    //constructor und destructor
    Hero();

    Hero(const std::string& name, int health, int gold, int armor, int magic_resistance);

    virtual ~Hero();

    //vererbte Methode aus der Klasse Character wird überschrieben
    void attack(Character& character) override;

    Item sellItem(int index);

    bool fight(Character& enemy);



// Diese Methode gibt einen Zeiger auf ein Ausrüstungsitem an einer bestimmten Position zurück
    const Item* getGear(int i) const {
        // Überprüfung, ob der angegebene Index gültig ist
        if (i >= 0 && i < 2) {
            // Rückgabe eines Zeigers auf das Ausrüstungsitem an der angegebenen Position
            return &gear[i];
        } else {
            // Wenn der angegebene Index ungültig ist, wird ein Nullzeiger zurückgegeben
            return nullptr;
        }
    }


    const Item* getInventory(int i) const;


    int addInventarItem(const Item& item);
    Item removeInventarItem(int slot);

    int addEquipmentItem(const Item& item);
    Item removeEquipmentItem(int slot);


};



#endif /* HERO_H_ */