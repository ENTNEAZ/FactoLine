#include "Furnance.h"


const int Furnance::processTime = 10000;
Furnance::Furnance(int x, int y) :Placeable(x, y, 'F'), tickLeft(-1)
{
}

Furnance::Furnance(Location l) : Placeable(l, 'F'), tickLeft(-1)
{
}

bool Furnance::hasItem()
{
    if (this->tickLeft == 0)
        return true;
    else
        return false;
}

Item* Furnance::passOutItem()
{
    Item* temp = this->onMachine;
    this->onMachine = nullptr;
    this->tickLeft = -1;
    this->setPrintCharacter('F');
    return temp;
}

void Furnance::acceptItem(Item* i)
{
    if (this->canAcceptItem()) {
        this->onMachine = i;
        this->setPrintCharacter(i->getPrintCharacter());
        switch (i->getPrintCharacter())
        {
        case '~':
        //case 'x':
            tickLeft = Furnance::processTime;
            break;
        default:
            tickLeft = 0;
            break;
        }
    }
}

void Furnance::tick()
{
    if (tickLeft > 0) {
        tickLeft--;
    }
    if (tickLeft == 0) {
        switch (this->onMachine->getPrintCharacter())
        {
        case '~':
            //ÊäÈëÌú¿ó Êä³öÌú°å
            this->onMachine->setNameAndPrintCharacter("Iron plate", '@');
            this->setPrintCharacter(this->onMachine->getPrintCharacter());
            break;
        default:
            break;
        }
    }
}

bool Furnance::canAcceptItem()
{
    return (!this->hasItem() && this->tickLeft == -1);
}
