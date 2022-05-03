#pragma once
#ifndef Item
#include <iostream>
using namespace std;
class Item {
public:
	Item(string = "", char = 0);
	~Item();
	string getName();
	char getPrintCharacter();
	void setNameAndPrintCharacter(string, char);
private:
	string name;
	char printCharacter;
};
#endif // !Item
