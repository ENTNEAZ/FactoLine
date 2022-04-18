#include <iostream>
#include "Location.h"
#include "World.h"


Location& World::getPlayerLocation(){
	return this->playerLocation;
}



World::World():playerLocation(Location(15,15)) {

}

void World::updateData(char data[48][188]) {
	//������������
	// 
	for (int i = 0; i < 48; i++)
	{
		for (int j = 0; j < 188; j++)
		{
			data[i][j] = '��';
		}
	}
	//���ȸ���player��λ��
	data[this->getPlayerLocation().getLocationX()][this->getPlayerLocation().getLocationY()] = 'O';

	//Ȼ���Ǹ��ֻ���
}
void World::playerInput(char in) {
	switch (in)
	{
	case 'w':
		if (checkLocationLegal(Location(getPlayerLocation().getLocationX() - 1, getPlayerLocation().getLocationY()))) {
			getPlayerLocation().setLocation(getPlayerLocation().getLocationX() - 1, getPlayerLocation().getLocationY());
		}
		break;
	case 's':
		if (checkLocationLegal(Location(getPlayerLocation().getLocationX() + 1, getPlayerLocation().getLocationY()))) {
			getPlayerLocation().setLocation(getPlayerLocation().getLocationX() + 1, getPlayerLocation().getLocationY());
		}
		break;
	case 'a':
		if (checkLocationLegal(Location(getPlayerLocation().getLocationX(), getPlayerLocation().getLocationY() - 1))) {
			getPlayerLocation().setLocation(getPlayerLocation().getLocationX(), getPlayerLocation().getLocationY() - 1);
		}
		break;
	case 'd':
		if (checkLocationLegal(Location(getPlayerLocation().getLocationX(), getPlayerLocation().getLocationY() + 1))) {
			getPlayerLocation().setLocation(getPlayerLocation().getLocationX(), getPlayerLocation().getLocationY() + 1);
		}
		break;
	default:
		break;
	}
}
bool World::checkLocationLegal(Location c) {
	if (c.getLocationX() < 0 || c.getLocationX() > 29 || c.getLocationY() < 0 || c.getLocationY() > 119)
		return false;
	else
		return true;
}