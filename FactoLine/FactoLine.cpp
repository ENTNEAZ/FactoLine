#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>

#include "World.h"
using namespace std;


/*
Window height:43
Window Width:183
*/
const int screenWidth = 183;
const int screenHeight = 43;
char screenData[48][188];


extern void initialScreenHandler();
extern void screenHandler(char data[48][188]);

void checkScreen() {
    for (int i = 0; i < screenWidth; ++i) {
        cout << "#";
    }
    cout << endl;

    cout << setw(screenWidth - 1) << left << "# ____  __    ___  ____  __   __    __  __ _  ____ " << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#(  __)/ _\\  / __)(_  _)/  \\ (  )  (  )(  ( \\(  __)" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "# ) _)/    \\( (__   )( (  O )/ (_/\\ )( /    / ) _)" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#(__) \\_/\\_/ \\___) (__) \\__/ \\____/(__)\\_)__)(____)" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#按键提示：" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#z:传送带" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#x:采矿机" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#c:虚空洞" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#v:机械臂" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#f:熔炉" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#e:合成器" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#当按下CapLock时，将会一直摆放上次摆放的机器（方便放置传送带）" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#游玩提醒：" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#通过采矿机采掘铁矿" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#通过传送带运输铁矿" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#通过熔炉烧炼成铁锭" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#通过合成机合成铁板" << "#" << endl;
    cout << setw(screenWidth - 1) << left << "#通过虚空洞提交铁板，达到2000个铁板时，游戏胜利" << "#" << endl;

    for (int i = 0; i < screenHeight - 2 - 22; i++) {
        cout << "#" << setw(screenWidth - 1) << right << "#" << endl;
    }

    for (int i = 0; i < screenWidth; ++i) {
        cout << "#";
    }
    cout << endl;
}

char anyKeydown() {
	char input = NULL;
	if (_kbhit()) { //如果有按键按下，则_kbhit()函数返回真
		input = _getch();//使用_getch()函数获取按下的键值
        
	}
    return input;
}
static World* world = nullptr;

World* getWorld() {
    return world;
}

int main()
{
    initialScreenHandler();
    checkScreen();
    system("pause");
    
    world = new World();

    world->updateData(screenData);
    while (true) {
        screenHandler(screenData);
        char a = anyKeydown();
        if (a != NULL) {
            world->playerInput(a);
        }
        world->updateData(screenData);
    }
    
}

