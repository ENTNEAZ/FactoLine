#include <iostream>
#include "Location.h"
#include "World.h"


Location& World::getPlayerLocation(){
	return this->playerLocation;
}



World::World():playerLocation(Location(15,15)) {

}

void World::updateData(char data[48][188]) {

}
void World::playerInput(char in) {
	switch (in)
	{
	case 'w':
		if (checkLocationLegal(Location(getPlayerLocation().getLocationX(), getPlayerLocation().getLocationY() - 1))) {
			getPlayerLocation().setLocation(getPlayerLocation().getLocationX(), getPlayerLocation().getLocationY() - 1);
		}
		break;
	default:
		break;
	}
}
bool World::checkLocationLegal(Location c) {
	if (c.getLocationX() < 0 || c.getLocationX() > 183 || c.getLocationY() < 0 || c.getLocationY() > 43)
		return false;
	else
		return true;
}