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
	this->tickAll();
	static auto timeTemp = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	static int tickPass = 0;
	static int tickTemp = 0;
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
	data[29][4] = '0' + (tickTemp / 100 >= 10)?'X' - '0':(tickTemp / 100);
	data[29][5] = '0' + (tickTemp - (tickTemp / 100) * 100) / 10;
	data[29][6] = '0' + tickTemp - (tickTemp / 100) * 100 - ((tickTemp - (tickTemp / 100) * 100) / 10) * 10;

	//显示目标
	data[0][0] = 't';
	data[0][1] = 'a';
	data[0][2] = 'r';
	data[0][3] = 'g';
	data[0][4] = 'e';
	data[0][5] = 't';
	data[0][6] = ':';

	data[0][7] = '0' + VoidHole::eatedIronPlate / 1000;
	data[0][8] = '0' + (VoidHole::eatedIronPlate - (VoidHole::eatedIronPlate / 1000 * 1000)) / 100;
	data[0][9] = '0' + (VoidHole::eatedIronPlate - (VoidHole::eatedIronPlate / 1000 * 1000) - ((VoidHole::eatedIronPlate - (VoidHole::eatedIronPlate / 1000 * 1000)) / 100) * 100) / 10;
	data[0][10] = '0' + VoidHole::eatedIronPlate % 10;

	data[0][11] = '/';

	data[0][12] = '2';
	data[0][13] = '0';
	data[0][14] = '0';
	data[0][15] = '0';
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
	static bool placedMachine = false;
	static char pressKey = 0;
	char realIn = in;//一定是个小写字母

	if (in <= 90 && in >= 65) {
		//是个大写字母
		realIn = in | 0x20;
	}

	switch (in)
	{
	case 'w':
	case 'a':
	case 's':
	case 'd':
		if (!placedMachine) {
			placedMachine = true;
			this->addPlaceable(pressKey,this->getPlayerLocation(), realIn);
		}
		this->changePlayerPositionByFacing(realIn);
		break;
	case 'W':
	case 'A':
	case 'S':
	case 'D':
		this->addPlaceable(pressKey, this->getPlayerLocation(), realIn);
		this->changePlayerPositionByFacing(realIn);
		break;
	default:
		placedMachine = false;
		pressKey = realIn;
		break;
	}
	
}

void World::changePlayerPositionByFacing(char in) {
	switch (in)
	{
	case 'w':
	case 'W':
		if (checkLocationLegal(Location(getPlayerLocation().getLocationX() - 1, getPlayerLocation().getLocationY()))) {
			getPlayerLocation().setLocation(getPlayerLocation().getLocationX() - 1, getPlayerLocation().getLocationY());
		}
		break;
	case 's':
	case 'S':
		if (checkLocationLegal(Location(getPlayerLocation().getLocationX() + 1, getPlayerLocation().getLocationY()))) {
			getPlayerLocation().setLocation(getPlayerLocation().getLocationX() + 1, getPlayerLocation().getLocationY());
		}
		break;
	case 'a':
	case 'A':
		if (checkLocationLegal(Location(getPlayerLocation().getLocationX(), getPlayerLocation().getLocationY() - 1))) {
			getPlayerLocation().setLocation(getPlayerLocation().getLocationX(), getPlayerLocation().getLocationY() - 1);
		}
		break;
	case 'd':
	case 'D':
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

void World::addPlaceable(char in, Location l, char facing) {

	char realIn = in;
	if (in <= 90 && in >= 65) {
		//是个大写字母
		realIn = in | 0x20;
	}

	Placeable* newPlaceable = nullptr;
	switch (in)
	{
	case 'z':
	case 'Z':
		//生成一个传送带
		newPlaceable = new ConveyorBelt(l, facing);
		break;
	case 'x':
	case 'X':
		//生成一个采矿机
		newPlaceable = new MineMachine(l, facing);
		break;
	case 'c':
	case 'C':
		//生成一个虚空洞
		newPlaceable = new VoidHole(l);
		break;
	case 'v':
	case 'V':
		//生成一个机械臂
		newPlaceable = new RoboticArm(l, facing);
		break;
	case 'f':
	case 'F':
		//生成一个熔炉
		newPlaceable = new Furnance(l);
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
}