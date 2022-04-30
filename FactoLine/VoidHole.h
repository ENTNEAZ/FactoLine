#pragma once
#ifndef VoidHole
#include "Placeable.h"
#include "Location.h"
class VoidHole :public Placeable {
public:
	VoidHole(int, int);
	VoidHole(Location);
	virtual Item* passOutItem();
	virtual void acceptItem(Item*);
	virtual void tick();
	virtual bool canAcceptItem();
};
#endif // !VoidHole
