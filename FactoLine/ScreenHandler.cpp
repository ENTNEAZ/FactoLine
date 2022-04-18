#include <iostream>
#include <conio.h>
#include <windows.h>

static int choice = 0;
static HANDLE hOutput, hOutBuf;
static COORD coord = { 0,0 };
static DWORD bytes = 0;

void initialScreenHandler() {
    hOutBuf = CreateConsoleScreenBuffer(
        GENERIC_WRITE,
        FILE_SHARE_WRITE,
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    hOutput = CreateConsoleScreenBuffer(
        GENERIC_WRITE,
        FILE_SHARE_WRITE,
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hOutput, &cci);
    SetConsoleCursorInfo(hOutBuf, &cci);
}
void screenHandler(char data[48][188]) {
    if (choice == 0) {
        for (int i = 0; i < 43; i++)
        {
            coord.Y = i;
            WriteConsoleOutputCharacterA(hOutBuf, data[i], 183, coord, &bytes);
        }
        SetConsoleActiveScreenBuffer(hOutBuf);
        choice = 1;
    }
    else {
        for (int i = 0; i < 43; i++)
        {
            coord.Y = i;
            WriteConsoleOutputCharacterA(hOutput, data[i], 183, coord, &bytes);
        }
        SetConsoleActiveScreenBuffer(hOutput);
        choice = 0;
    }
}