#pragma once
#ifndef MineMachine
#include "Placeable.h"
#include "Item.h"
#include "Location.h"

class MineMachine :public Placeable {
public:
	static const int processTime;
	MineMachine(int, int, char);
	MineMachine(Location, char);
	virtual Item* passOutItem() override;
	virtual void acceptItem(Item*) override;
	virtual void tick() override;
	virtual bool canAcceptItem() override;
private:
	int tickLeft;
};
#endif // !MineMachine
