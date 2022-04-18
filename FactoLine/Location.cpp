#include "location.h"

int Location::getLocationX() {
	return this->x;
}

int Location::getLocationY() {
	return this->y;
}

Location::Location(int x = 0,int y = 0) {
	setLocation(x, y);
}

void Location::setLocation(int x, int y) {
	this->x = x;
	this->y = y;
}