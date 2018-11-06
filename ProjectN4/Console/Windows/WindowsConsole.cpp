//
//  WindowsConsole.cpp
//  ProjectN4
//
//  Created by pc-laptop on 10/31/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include "WindowsConsole.hpp"

#ifdef _WIN64
#include <conio.h>
#include <windows.h>

void ConsoleManager::WindowsConsole::gotoxy(int x, int y)
{
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void ConsoleManager::WindowsConsole::hidecursor (void)
{
    HANDLE hdl;
    hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO t;
    t.bVisible = false;
    SetConsoleCursorInfo(hdl, &t);
}

void ConsoleManager::WindowsConsole::clear ()
{
    system("cls");
}

void ConsoleManager::WindowsConsole::sleep ()
{
    Sleep(ConsoleManager::sleepTime);
}

#endif

