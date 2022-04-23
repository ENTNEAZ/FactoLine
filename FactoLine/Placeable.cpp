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
	//��tick����,������true �ȴ�world tick����
	return this->isOnAction;
}

char Placeable::getPrintCharacter() {
	return printCharacter;
}


Placeable::Placeable(Location l,char printCharacter) :selfLocation(l.getLocationX(), l.getLocationY()), printCharacter(printCharacter) {

}
Placeable::Placeable(int x, int y, char printCharacter) : selfLocation(x, y), printCharacter(printCharacter) {

}