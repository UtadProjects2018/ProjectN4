//
//  Animal.cpp
//  ProjectN4
//
//  Created by pc-laptop on 10/23/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include <iostream>
#include "TEntity.h"
#include "Console.h"


#pragma mark - Constants

const int moveLimitX = 100;

const int moveValueFor(const AnimalGame::AnimalType animalType)
{
    switch (animalType)
    {
        case AnimalGame::Horse:
            return 10;
            
        case AnimalGame::Turtle:
            return 10;
            
        case AnimalGame::Elephant:
            return 10;
    }
}

#pragma mark - Impl

void AnimalGame::moveAnimal(AnimalGame::TEntity *animal)
{
    if(animal->m_ix == moveLimitX)
    {
        // Resetea la posición
        animal->m_ix = 0;
    }
    
    animal->m_ix += moveValueFor(animal->animalType);
    ConsoleManager::gotoxy(animal->m_ix, animal->m_iy);
}

void AnimalGame::drawAnimal(AnimalGame::TEntity *animal)
{
    switch (animal->animalType)
    {
        case Horse:
            printf("CCC");
            break;
            
        case Turtle:
            printf("TTT");
            break;
            
        case Elephant:
            printf("EEE");
            break;
            
        default:
            break;
    }
}
