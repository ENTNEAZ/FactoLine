#pragma once
#include "Location.h"
#ifndef World
class World {
public:
	World();
	Location& getPlayerLocation();
	void playerInput(char);
	void updateData(char [48][188]);
	bool checkLocationLegal(Location);
private:
	Location playerLocation;

};
#endif // !World
