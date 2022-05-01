#pragma once
#ifndef RoboticArm
#include "Placeable.h"
#include "Item.h"
#include "Location.h"

class RoboticArm :public Placeable {
public:
	static const int grabCoolDownTime;
	static const int dropCoolDownTime;
	RoboticArm(int, int, char);
	RoboticArm(Location, char);
	void updateArmBefore();
	void setNormalPrintCharater();
	virtual Item* passOutItem();
	virtual void acceptItem(Item*);
	virtual void tick();
	virtual bool canAcceptItem();
private:
	int tickLeft;
	Placeable* armBefore;
};
#endif // !RoboticArm
