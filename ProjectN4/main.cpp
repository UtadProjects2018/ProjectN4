//
//  main.cpp
//  ProjectN4
//
//  Created by pc-laptop on 10/23/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#ifdef __APPLE__
#include <unistd.h>
#endif

#include <iostream>
#include "TEntity.h"
#include "Console.h"

using namespace AnimalGame;

const int sleepTime = 1000; //will sleep for 1 ms

int main(int argc, const char * argv[])
{
    AnimalGame::TEntity::funcEntity functions[2] = {&drawAnimal, &moveAnimal};
    
    TEntity *horse    = new TEntity(Horse, functions, 0, 10);
    TEntity *turtle   = new TEntity(Turtle, functions, 0, 20);
    TEntity *elephant = new TEntity(Elephant, functions, 0, 30);
    
    TEntity *animals[] = {horse, horse, turtle, elephant};
    int numberOfAnimals = sizeof(animals)/sizeof(*animals);
    
    while (true)
    {
        ConsoleManager::clear();
        for (int i = 0; i < numberOfAnimals; i++)
        {
            TEntity *animal = animals[i];
            animal->m_funcs[0](animal);
            animal->m_funcs[1](animal);
        }
        
#ifdef _WIN32
        Sleep(sleepTime);
#elif __APPLE__
        usleep(sleepTime);
#endif
    }
    return 0;
}
