#pragma once
#ifndef ConveyorBelt
#include "Placeable.h"
#include "Item.h"


class ConveyorBelt :public Placeable{
public:
	ConveyorBelt(int, int, char);
	ConveyorBelt(Location, char);
	Location getLocation();
	virtual void tick() override;
	Item * getItemOnBelt();
	virtual void acceptItem(Item*) override;
	bool itemOnBelt();
	virtual Item * passOutItem() override;
private:
	int tickLeft;
	Item * onBelt = nullptr;
};
#endif // !ConveyorBelt
