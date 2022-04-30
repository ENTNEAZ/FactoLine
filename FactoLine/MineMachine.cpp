#include "MineMachine.h"
#include "Item.h"

const int MineMachine::processTime = 2000;

MineMachine::MineMachine(int x, int y, char facing):Placeable(x,y,'M'), tickLeft(MineMachine::processTime), output(nullptr)
{
    this->facing = facing;
}

MineMachine::MineMachine(Location l, char facing) : Placeable(l, 'M'), tickLeft(MineMachine::processTime), output(nullptr)
{
    this->facing = facing;
}

Item* MineMachine::passOutItem()
{
    Item* temp = this->output;
    this->output = nullptr;
    return temp;
}

void MineMachine::acceptItem(Item* in)
{
    this->output = in;
    this->isOnAction = true;

}

void MineMachine::tick()
{
    if (this->output != nullptr) {
        this->isOnAction = true;
    }
    tickLeft--;
    if (tickLeft == 0) {
        tickLeft = MineMachine::processTime;
        if (this->output == nullptr) {
            Item* temp = new Item("Iron ore", '~');
            //TODO 生成不同的矿物
            this->output = temp;
            this->isOnAction = true;
        }
        
    }
}

bool MineMachine::canAcceptItem()
{
    return false;
}
