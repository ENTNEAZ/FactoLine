#include "Item.h"

Item::Item(string name, char printCharacter) :name(name), printCharacter(printCharacter) {

}

string Item::getName()
{
    return this->name;
}

char Item::getPrintCharacter()
{
    return this->printCharacter;
}