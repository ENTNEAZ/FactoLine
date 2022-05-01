#pragma once
#ifndef ConveyorBelt
#include "Placeable.h"
#include "Item.h"


class ConveyorBelt :public Placeable{
public:
	static const int processTime;
	ConveyorBelt(int, int, char);
	ConveyorBelt(Location, char);
	Location getLocation();
	virtual void tick() override;
	Item * getItemOnBelt();
	virtual void acceptItem(Item*) override;
	bool itemOnBelt();
	virtual Item * passOutItem() override;
	virtual bool canAcceptItem() override;
private:
	int tickLeft;
};
#endif // !ConveyorBelt
