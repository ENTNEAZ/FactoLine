#include <iostream>
#include <chrono>
#include "Location.h"
#include "World.h"
#include "ConveyorBelt.h"
#include "Placeable.h"
#include "MineMachine.h"
#include "VoidHole.h"
#include "RoboticArm.h"
#include "Furnance.h"

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

Location& World::getPlayerLocation(){
	return this->playerLocation;
}



World::World():playerLocation(Location(15,15)) {

}

vector<Placeable*> World::getPlaceableThings() const{
	return this->placeableThings;
}

void World::updateData(char data[48][188]) {
	//tickAll
	// 
	static auto timeTemp = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	static int tickPass = 0;
	static int tickTemp = 0;
	this->tickAll();
	tickPass++;
	//重置整个区域
	// 
	for (int i = 0; i < 48; i++)
	{
		for (int j = 0; j < 188; j++)
		{
			data[i][j] = ' ';
		}
	}

	//统计每秒tick

	if (duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - timeTemp >= 1000) {
		//1s过去了
		timeTemp = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
		tickTemp = tickPass;
		tickPass = 0;
	}

	//显示tick per second
	data[29][0] = 't';
	data[29][1] = 'p';
	data[29][2] = 's';
	data[29][3] = ':';
	data[29][4] = '0' + tickTemp / 100;
	data[29][5] = '0' + (tickTemp - (tickTemp / 100) * 100) / 10;
	data[29][6] = '0' + tickTemp - (tickTemp / 100) * 100 - ((tickTemp - (tickTemp / 100) * 100) / 10) * 10;
	//各种机器摆放
	for (auto i = this->placeableThings.begin(); i != this->placeableThings.end(); i++) {
		Location placeableLocation = (*i)->getLocation();
		char placeableChar = (*i)->getPrintCharacter();
		data[placeableLocation.getLocationX()][placeableLocation.getLocationY()] = placeableChar;
	}

	//更新player的位置 最后更新原因：置于最上层
	data[this->getPlayerLocation().getLocationX()][this->getPlayerLocation().getLocationY()] = 'O';
}
void World::playerInput(char in) {
	static bool placeMachine = false;
	static char pressKey = 0;
	if (placeMachine && (in == 'a' || in == 's' || in == 'd' || in == 'w'))
	{
		Placeable* newPlaceable = nullptr;
		switch (pressKey)
		{
		case 'z':
			//生成一个传送带
			newPlaceable = new ConveyorBelt(this->getPlayerLocation(), in);
			break;
		case 'x':
			//生成一个采矿机
			newPlaceable = new MineMachine(this->getPlayerLocation(), in);
			break;
		case 'c':
			//生成一个虚空洞
			newPlaceable = new VoidHole(this->getPlayerLocation());
			break;
		case 'v':
			//生成一个机械臂
			newPlaceable = new RoboticArm(this->getPlayerLocation(), in);
			break;
		case 'f':
			//生成一个熔炉
			newPlaceable = new Furnance(this->getPlayerLocation());
			break;
		default:
			newPlaceable = nullptr;
			break;
		}
		if (newPlaceable != nullptr) {
			for (auto i = this->placeableThings.begin(); i != this->placeableThings.end(); i++) {
				if ((*i)->getLocation() == newPlaceable->getLocation()) {
					delete (*i);
					this->placeableThings.erase(i);
					break;
				}
			}
			this->addPlaceableThings(newPlaceable);
		}
		placeMachine = false;
	}
	else {
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
			placeMachine = true;
			pressKey = in;
			break;
		}
	}
	
}
bool World::checkLocationLegal(Location c) {
	if (c.getLocationX() < 0 || c.getLocationX() > 29 || c.getLocationY() < 0 || c.getLocationY() > 119)
		return false;
	else
		return true;
}

void World::addPlaceableThings(Placeable * p) {
	this->placeableThings.push_back(p);
}

void World::tickAll() {
	for (auto i = this->placeableThings.begin(); i != this->placeableThings.end(); i++) {
		(*i)->tick();
		if ((*i)->isCallingAction()) {
			char facing = (*i)->getFacing();
			Location loc = (*i)->getLocation();
			Location* cmp = nullptr;
			if (facing == 'w' || facing == 's') {
				cmp = new Location(loc.getLocationX() + ((facing == 'w') ? -1 : 1), loc.getLocationY());
			}
			else {
				cmp = new Location(loc.getLocationX(), loc.getLocationY() + ((facing == 'a') ? -1 : 1));
			}
			for (auto j = this->placeableThings.begin(); j != this->placeableThings.end(); j++) {
				if ((*j)->getLocation() == *cmp) {
					if ((*j)->canAcceptItem()) {
						(*j)->acceptItem((*i)->passOutItem());
					}
					break;
				}
			}
		}
	}
}