//
//  Animal.hpp
//  ProjectN4
//
//  Created by pc-laptop on 10/23/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#ifndef TEntity_hpp
#define TEntity_hpp
#include "Console.h"
#endif

namespace AnimalGame
{
    enum AnimalType
    {
        Horse,
        Elephant,
        Turtle,
    };
    
    struct TEntity
    {
        typedef void (*funcEntity)(TEntity *, ConsoleManager::Console *);
        int m_ix;
        int m_iy;
        funcEntity *m_funcs;
        AnimalType animalType;
        
        
        TEntity(AnimalType animalT, funcEntity *funcs, int x, int y)
        {
            m_ix = x;
            m_iy = y;
            animalType = animalT;
            m_funcs = funcs;
        }
    };
    
    void moveAnimal(TEntity *animal, ConsoleManager::Console *console);
    void drawAnimal(TEntity *animal, ConsoleManager::Console *console);
}

