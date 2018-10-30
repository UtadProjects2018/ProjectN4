//
//  Console.cpp
//  ProjectN4
//
//  Created by pc-laptop on 10/23/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include "Console.h"

#ifdef __APPLE__
#include <ncurses.h>
#endif

#pragma mark - Windows

#ifdef _WIN32
void gotToXYWindows(int x, int y)
{
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
void clearOnWindows()
{
    system("cls");
}

void hidecursorOnWindows(void) {
    HANDLE hdl;
    hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO t;
    t.bVisible = false;
    SetConsoleCursorInfo(hdl, &t);
}
#endif


#pragma mark - MacOS

#ifdef __APPLE__
void gotToXYApple(int x, int y)
{
    //TODO:
    /*initscr();
    move(x, y);
    printw("TEST");
    refresh();
    getch();
    endwin();*/
}
void clearOnApple()
{
    //TODO:
}

void hidecursorOnApple(void)
{
    //TODO: 
}
#endif


#pragma mark - Imp

void ConsoleManager::gotoxy(int x, int y)
{
#ifdef _WIN32
    gotToXYWindows(x, y);
#elif __APPLE__
    gotToXYApple(x, y);
#endif
}

void ConsoleManager::hidecursor(void)
{
#ifdef _WIN32
    hidecursorOnWindows();
#elif __APPLE__
    hidecursorOnApple();
#endif
}

void ConsoleManager::clear()
{
#ifdef _WIN32
    clearOnWindows();
#elif __APPLE__
    clearOnApple();
#endif
}
