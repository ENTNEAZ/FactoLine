#include "ConveyorBelt.h"
#include "Item.h"

ConveyorBelt::ConveyorBelt(int x, int y,char facing) :Placeable(x, y, 0), facing(facing), tickLeft(-1) {
	if (facing == 's' || facing == 'w') {
		printCharacter = '|';
	}
	else {
		printCharacter = '-';
	}
}
ConveyorBelt::ConveyorBelt(Location l,char facing) : Placeable(l, 0), facing(facing), tickLeft(-1) {
	if (facing == 's' || facing == 'w') {
		printCharacter = '|';
	}
	else {
		printCharacter = '-';
	}
}


Location ConveyorBelt::getLocation()
{
	return this->selfLocation;
}

Item ConveyorBelt::getItemOnBelt() {
	return this->onBelt;
}

bool ConveyorBelt::itemOnBelt()
{
	if (tickLeft != -1) {
		return true;
	}
	return false;
}

Item ConveyorBelt::passOutItem()
{
	this->tickLeft = -1;
	this->isOnAction = false;
	return this->onBelt;
}

void ConveyorBelt::tick() {
	//自己的character变化
	if (itemOnBelt()) {
		this->setPrintCharacter('~');
	}
	else {
		if (this->facing == 's' || this->facing == 'w') {
			printCharacter = '|';
		}
		else {
			printCharacter = '-';
		}
	}

	//检查tick 是否要call
	if (tickLeft == 0) {
		this->isOnAction = true;
	}
	else {
		this->isOnAction = false;
	}
}