//
//  AnimalGameWrapper.cpp
//  ProjectN4
//
//  Created by pc-laptop on 11/1/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include "AnimalGameWrapper.hpp"

#include "TEntity.h"

#ifdef _WIN32
#include "../Console/Windows/WindowsConsole.hpp"
#elif __APPLE__
#include "MacConsole.hpp"
#endif

ConsoleManager::Console* pConsole;

void printConsoleCursor(int x, int y, const char *emoji)
{
    pConsole->gotoxy(x, y);
}

void drawConsoleCursor(int x, int y, const char *emoji)
{
    pConsole->draw(emoji);
}

void AnimalGame::startGame()
{
    AnimalGame::TEntity::funcEntity functions[] = {&AnimalGame::drawAnimal, &AnimalGame::moveAnimal};
    
    AnimalGame::TEntity *horse    = new AnimalGame::TEntity(AnimalGame::Horse, functions, 0, 10);
    AnimalGame::TEntity *turtle   = new AnimalGame::TEntity(AnimalGame::Turtle, functions, 0, 20);
    AnimalGame::TEntity *elephant = new AnimalGame::TEntity(AnimalGame::Elephant, functions, 0, 30);
    
    AnimalGame::TEntity *animals[] = {horse, turtle, elephant};
    
#ifdef _WIN32
    pConsole = new ConsoleManager::WindowsConsole();
#elif __APPLE__
    pConsole = new ConsoleManager::MacConsole();
#endif
    
    void (*consolePrint)(int, int, const char *) = &printConsoleCursor;
    void (*consoleDraw) (int, int, const char *) = &drawConsoleCursor;
    
    while (true)
    {
        pConsole->clear();
        
        for (TEntity *animal : animals)
        {
            animal->m_funcs[0](animal, consoleDraw);
            animal->m_funcs[1](animal, consolePrint);
        }
        
        pConsole->sleep();
    }
}
