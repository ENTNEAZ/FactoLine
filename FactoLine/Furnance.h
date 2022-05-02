#pragma once
#ifndef Furnance
#include "Placeable.h"
#include "Location.h"

class Furnance :public Placeable {
public:
	static const int processTime;
	Furnance(int x, int y);
	Furnance(Location);
	virtual bool hasItem() override;
	virtual Item* passOutItem() override;
	virtual void acceptItem(Item*) override;
	virtual void tick() override;
	virtual bool canAcceptItem() override;
private:
	int tickLeft;

};
#endif // !Furnance
