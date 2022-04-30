#include "RoboticArm.h"

RoboticArm::RoboticArm(int x, int y, char facing) :Placeable(x, y, ' '), tickLeft(-1), onArm(nullptr) {
	this->facing = facing;
	switch (facing)
	{
	case 'a':
		this->setPrintCharacter('<');
		break;
	case 's':
		this->setPrintCharacter('V');
		break;
	case 'd':
		this->setPrintCharacter('>');
		break;
	case 'w':
		this->setPrintCharacter('^');
		break;
	default:
		break;
	}
}

RoboticArm::RoboticArm(Location l, char facing) :Placeable(l, ' '), tickLeft(-1), onArm(nullptr)
{
	this->facing = facing;
	switch (facing)
	{
	case 'a':
		this->setPrintCharacter('<');
		break;
	case 's':
		this->setPrintCharacter('V');
		break;
	case 'd':
		this->setPrintCharacter('>');
		break;
	case 'w':
		this->setPrintCharacter('^');
		break;
	default:
		break;
	}
}


void RoboticArm::tick()
{
	if (tickLeft > 0) {
		tickLeft--;
	}
	if (tickLeft == -1) {

	}
}

bool RoboticArm::canAcceptItem()
{
    return false;
}
