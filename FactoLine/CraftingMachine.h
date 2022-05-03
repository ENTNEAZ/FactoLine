#pragma once
#ifndef CraftingMachine
#include "Placeable.h"
#include "Location.h"
class CraftingMachine :public Placeable {
public:
	static const int processTime;
	CraftingMachine(int, int);
	CraftingMachine(Location);
	virtual Item* passOutItem();
	virtual void acceptItem(Item*);
	virtual void tick();
	virtual bool canAcceptItem();
	virtual bool hasItem();
private:
	int tickLeft;
};

#endif // !CraftingMachine
