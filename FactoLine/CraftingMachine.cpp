#include "CraftingMachine.h"

const int CraftingMachine::processTime = 5000;

CraftingMachine::CraftingMachine(int x, int y) :Placeable(x, y, 'C'), tickLeft(-1)
{
}

CraftingMachine::CraftingMachine(Location l) : Placeable(l, 'C'), tickLeft(-1)
{
}

Item* CraftingMachine::passOutItem()
{
    this->tickLeft = -1;
    Item* temp = this->onMachine;
    this->setPrintCharacter('C');
    this->onMachine = nullptr;
    return temp;
}

void CraftingMachine::acceptItem(Item* i)
{
    if (this->canAcceptItem()) {
        this->onMachine = i;
        //this->setPrintCharacter(i->getPrintCharacter());
        switch (i->getPrintCharacter())
        {
        case 'a':
        //case 'x':
            tickLeft = CraftingMachine::processTime;
            break;
        default:
            tickLeft = 0;
            break;
        }
    }
}

void CraftingMachine::tick()
{
    if (tickLeft > 0) {
        tickLeft--;
    }
    if (tickLeft == 0) {
        switch (this->onMachine->getPrintCharacter())
        {
        case 'a':
            //输入铁锭 输出铁板
            this->onMachine->setNameAndPrintCharacter("Iron Plate", '@');
            //this->setPrintCharacter(this->onMachine->getPrintCharacter());
            break;
        default:
            break;
        }
    }
}

bool CraftingMachine::canAcceptItem()
{
    return (!this->hasItem() && this->tickLeft == -1);
}

bool CraftingMachine::hasItem()
{
    if (this->tickLeft == 0)//目的是为了防止机械手乱偷
        return true;
    else
        return false;
}
