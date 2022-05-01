#include "Location.h"
#include "Placeable.h"


Location Placeable::getLocation() {
	return this->selfLocation;
}

void Placeable::setPrintCharacter(char c)
{
	this->printCharacter = c;
}

bool Placeable::isCallingAction()
{
	//当tick结束,这个变成true 等待world tick处理
	return this->isOnAction;
}

char Placeable::getFacing()
{
	return this->facing;
}

char Placeable::getPrintCharacter() {
	return printCharacter;
}

bool Placeable::hasItem()
{
	return onMachine != nullptr;
}


Placeable::Placeable(Location l,char printCharacter) :selfLocation(l.getLocationX(), l.getLocationY()), printCharacter(printCharacter), facing('s'), onMachine(nullptr) {

}
Placeable::Placeable(int x, int y, char printCharacter) : selfLocation(x, y), printCharacter(printCharacter), facing('s'), onMachine(nullptr) {

}