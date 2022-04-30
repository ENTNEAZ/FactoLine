#pragma once
#ifndef Location
class Location {
public:
	Location(int x, int y);
	void setLocation(int x,int y);
	int getLocationX();
	int getLocationY();
	bool operator==(Location);
private:
	int x;
	int y;
};
#endif // !Location
