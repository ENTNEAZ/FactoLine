#pragma once
#ifndef RoboticArm
#include "Placeable.h"
#include "Item.h"
#include "Location.h"

class RoboticArm :public Placeable {
public:
	RoboticArm(int, int, char);
	RoboticArm(Location, char);
	virtual Item* passOutItem();
	virtual void acceptItem(Item*);
	virtual void tick();
	virtual bool canAcceptItem();
private:
	int tickLeft;
	Item* onArm;
};
#endif // !RoboticArm
