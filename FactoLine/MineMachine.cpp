#include "MineMachine.h"
#include "Item.h"

const int MineMachine::processTime = 2000;

MineMachine::MineMachine(int x, int y, char facing):Placeable(x,y,'M'), tickLeft(MineMachine::processTime)
{
    this->onMachine = nullptr;
    this->facing = facing;
}

MineMachine::MineMachine(Location l, char facing) : Placeable(l, 'M'), tickLeft(MineMachine::processTime)
{
    this->onMachine = nullptr;
    this->facing = facing;
}

Item* MineMachine::passOutItem()
{
    Item* temp = this->onMachine;
    this->onMachine = nullptr;
    this->isOnAction = false;
    return temp;
}

void MineMachine::acceptItem(Item* in)
{
    this->onMachine = in;
    this->isOnAction = true;

}

void MineMachine::tick()
{
    this->isOnAction = (this->onMachine == nullptr) ? false : true;

    tickLeft--;
    if (tickLeft == 0) {
        tickLeft = MineMachine::processTime;
        if (this->onMachine == nullptr) {
            Item* temp = new Item("Iron ore", '~');
            //TODO 生成不同的矿物
            this->onMachine = temp;
            this->isOnAction = true;
        }
        
    }
}

bool MineMachine::canAcceptItem()
{
    return false;
}
