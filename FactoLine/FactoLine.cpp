﻿#include <iostream>
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
        cerr << "#";
    }
    cerr << endl << setw(screenWidth - 1) << left << "#请将屏幕调整到可以显示全部#,按任意键继续" << "#" << endl;
    for (int i = 0; i < screenHeight - 3; i++) {
        cerr << "#" << setw(screenWidth - 1) << right << "#" << endl;
    }

    for (int i = 0; i < screenWidth; ++i) {
        cerr << "#";
    }

}

char anyKeydown() {
	char input = NULL;
	if (_kbhit()) { //如果有按键按下，则_kbhit()函数返回真
		input = _getch();//使用_getch()函数获取按下的键值
        
	}
    return input;
}

int main()
{
    initialScreenHandler();
    checkScreen();
    system("pause");
    World world;
    for (int i = 0; i < 48; i++)
    {
        for (int j = 0; j < 188; j++)
        {
            screenData[i][j] = ' ';
            if (i == world.getPlayerLocation().getLocationX() && j == world.getPlayerLocation().getLocationY())
                screenData[i][j] = 'O';
        }
    }
    while (true) {
        screenHandler(screenData);
        char a = anyKeydown();
        if (a != NULL) {
            world.playerInput(a);
        }
        //world.updateData(data);
    }
    
}

