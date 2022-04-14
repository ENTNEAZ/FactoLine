#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

const int screenWidth = 188;
const int screenHeight = 48;

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
        cout << "D";
	}
    return input;
}

int main()
{
    checkScreen();
    while (1) {
        if (anyKeydown()) {
            break;
        }
    }
    system("cls");
    
}

