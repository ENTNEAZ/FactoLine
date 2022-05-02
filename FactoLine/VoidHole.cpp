#include "VoidHole.h"

int VoidHole::eatedIronPlate = 0;
VoidHole::VoidHole(int x, int y) :Placeable(x,y,'s')
{
    this->setPrintCharacter('X');
}

VoidHole::VoidHole(Location l) : Placeable(l,'s')
{
    this->setPrintCharacter('X');
}

Item* VoidHole::passOutItem()
{
    return nullptr;
}

void VoidHole::acceptItem(Item* i)
{
    VoidHole::eatedIronPlate++;
    delete i;
}

void VoidHole::tick()
{
    return;
}

bool VoidHole::canAcceptItem()
{
    return true;
}