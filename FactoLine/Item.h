#pragma once
#ifndef Item
#include <iostream>
using namespace std;
class Item {
public:
	Item(string = "", char = 0);
	string getName();
	char getPrintCharacter();
private:
	string name;
	char printCharacter;
};
#endif // !Item
