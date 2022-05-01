#include "ConveyorBelt.h"
#include "Item.h"


const int ConveyorBelt::processTime = 500;
ConveyorBelt::ConveyorBelt(int x, int y,char facing) :Placeable(x, y, 0), tickLeft(-1) {
	this->onMachine = nullptr;
	this->facing = facing;
	if (facing == 's' || facing == 'w') {
		printCharacter = '|';
	}
	else {
		printCharacter = '-';
	}
}
ConveyorBelt::ConveyorBelt(Location l,char facing) : Placeable(l, 0), tickLeft(-1) {
	this->onMachine = nullptr;
	this->facing = facing;
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

Item * ConveyorBelt::getItemOnBelt() {
	return this->onMachine;
}

void ConveyorBelt::acceptItem(Item* i)
{
	this->onMachine = i;
	this->tickLeft = ConveyorBelt::processTime;
}

bool ConveyorBelt::itemOnBelt()
{
	if (tickLeft != -1 && onMachine != nullptr) {
		return true;
	}
	return false;
}

Item * ConveyorBelt::passOutItem()
{
	this->tickLeft = -1;
	this->isOnAction = false;
	Item* temp = this->onMachine;
	this->onMachine = nullptr;
	return temp;
}

bool ConveyorBelt::canAcceptItem()
{
	return(!this->itemOnBelt());
}

void ConveyorBelt::tick() {
	//�Լ���character�仯
	if (itemOnBelt()) {
		this->setPrintCharacter(this->onMachine->getPrintCharacter());
	}
	else {
		if (this->facing == 's' || this->facing == 'w') {
			printCharacter = '|';
		}
		else {
			printCharacter = '-';
		}
	}
	//tickleft�Լ�
	if (tickLeft > 0) {
		tickLeft--;
	}
	//���tick �Ƿ�Ҫcall
	if (tickLeft == 0) {
		this->isOnAction = true;
	}
	else {
		this->isOnAction = false;
	}
}