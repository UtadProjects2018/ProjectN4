//
//  Animal.hpp
//  ProjectN4
//
//  Created by pc-laptop on 10/23/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

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
        typedef void (*funcEntity)(TEntity *);
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
    
    void moveAnimal(TEntity *animal);
    void drawAnimal(TEntity *animal);
}

