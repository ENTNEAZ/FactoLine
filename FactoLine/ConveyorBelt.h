#pragma once
#ifndef ConveyorBelt
#include "Placeable.h"
#include "Item.h"


class ConveyorBelt :public Placeable{
public:
	ConveyorBelt(int, int, char);
	ConveyorBelt(Location, char);
	Location getLocation();
	virtual void tick();
	Item * getItemOnBelt();
	bool itemOnBelt();
	virtual Item * passOutItem() override;
private:
	char facing;
	int tickLeft;
	Item * onBelt = nullptr;
};
#endif // !ConveyorBelt
