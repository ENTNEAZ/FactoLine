#pragma once
#include "Location.h"
#include "Placeable.h"
#include <vector>
using namespace std;
#ifndef World
class World {
public:
	World();
	Location& getPlayerLocation();
	void playerInput(char);
	vector<Placeable*> getPlaceableThings() const;
	void updateData(char [48][188]);
	void changePlayerPositionByFacing(char);
	bool checkLocationLegal(Location);
	void addPlaceableThings(Placeable *);
	void tickAll();
	void addPlaceable(char, Location, char);
private:
	Location playerLocation;
	vector<Placeable *> placeableThings;
};
#endif // !World
