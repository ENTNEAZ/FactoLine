#include "Item.h"

Item::Item(string name, char printCharacter) :name(name), printCharacter(printCharacter) {

}

Item::~Item()
{
    this->name.clear();
}

string Item::getName()
{
    return this->name;
}

char Item::getPrintCharacter()
{
    return this->printCharacter;
}

void Item::setNameAndPrintCharacter(string n, char p)
{
    this->name = n;
    this->printCharacter = p;
}
