#include "RoboticArm.h"
#include "Item.h"
#include "World.h"
#include "Placeable.h"

extern World* getWorld();

const int RoboticArm::grabCoolDownTime = 500;
const int RoboticArm::dropCoolDownTime = 3000;
RoboticArm::RoboticArm(int x, int y, char facing) :Placeable(x, y, ' '), tickLeft(-1) {
	this->facing = facing;
	this->onMachine = nullptr;
	this->armBefore = nullptr;
	this->setNormalPrintCharater();
}

RoboticArm::RoboticArm(Location l, char facing) :Placeable(l, ' '), tickLeft(-1)
{
	this->facing = facing;
	this->onMachine = nullptr;
	this->armBefore = nullptr;
	switch (facing)
	{
	case 'a':
		this->setPrintCharacter('<');
		break;
	case 's':
		this->setPrintCharacter('v');
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

void RoboticArm::updateArmBefore()
{
	vector<Placeable*> pv = getWorld()->getPlaceableThings();

	Location* cmp = nullptr;
	bool updated = false;
	if (facing == 'w' || facing == 's') {
		cmp = new Location(this->getLocation().getLocationX() + ((facing == 'w') ? 1 : -1), this->getLocation().getLocationY());
	}
	else {
		cmp = new Location(this->getLocation().getLocationX(), this->getLocation().getLocationY() + ((facing == 'a') ? 1 : -1));
	}
	for (auto i = pv.begin(); i != pv.end(); i++) {
		if ((*i)->getLocation() == *cmp) {
			this->armBefore = *i;
			updated = true;
			break;
		}
	}
	if (!updated) {
		//说明机械臂前面没东西了
		this->armBefore = nullptr;
	}
	
	
}

void RoboticArm::setNormalPrintCharater()
{
	switch (this->facing)
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


Item* RoboticArm::passOutItem()
{
	this->isOnAction = false;
	Item* temp = this->onMachine;
	this->setNormalPrintCharater();
	this->onMachine = nullptr;
	return temp;
}

void RoboticArm::acceptItem(Item* i)
{
	if (this->hasItem()) {
		return;
	}
	this->onMachine = i;
}

void RoboticArm::tick()
{
	if (tickLeft > 0) {
		tickLeft--;
	}
	else {//tickLeft <= 0
		if (tickLeft == -1) {
			//尝试偷东西
			this->updateArmBefore();
			if (armBefore != nullptr && armBefore->hasItem()) {
				Item* temp = armBefore->passOutItem();
				this->onMachine = temp;
				//this->setPrintCharacter(temp->getPrintCharacter());
				tickLeft = RoboticArm::grabCoolDownTime;
			}
		}
		if (tickLeft == 0) {
			if (this->hasItem()) {
				//抓取到东西后的冷却
				this->isOnAction = true;
				tickLeft = RoboticArm::dropCoolDownTime;
			}
			else {
				//将东西扔出去后冷却
				tickLeft = -1;
			}
		}
	}
}

bool RoboticArm::canAcceptItem()
{
    return false;
}
