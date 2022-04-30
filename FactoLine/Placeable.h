#pragma once
#ifndef Placeable

#include "Location.h"
#include "Item.h"

class Placeable {
public:
	Placeable(Location, char = 0);
	Placeable(int x,int y, char = 0);
	char getPrintCharacter();
	Location getLocation();
	void setPrintCharacter(char);
	bool isCallingAction();
	char getFacing();
	virtual Item * passOutItem() = 0;
	virtual void acceptItem(Item*) = 0;
	virtual void tick() = 0;
	virtual bool canAcceptItem() = 0;
protected:
	char facing;
	char printCharacter;
	Location selfLocation;
	bool isOnAction = false;
};
#endif // !placeable
