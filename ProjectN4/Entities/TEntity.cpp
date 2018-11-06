//
//  Animal.cpp
//  ProjectN4
//
//  Created by pc-laptop on 10/23/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include <iostream>
#include "TEntity.h"

#pragma mark - Constants

const int moveLimitX = 100;

const int moveValueFor(const AnimalGame::AnimalType animalType)
{
    int animalPositionX = 0;
    switch (animalType)
    {
        case AnimalGame::Horse:
            animalPositionX = 2;
            break;
            
        case AnimalGame::Turtle:
            animalPositionX = 5;
            break;
            
        case AnimalGame::Elephant:
            animalPositionX = 1;
            break;
    }
    
    return animalPositionX;
}

#pragma mark - Implementation

void AnimalGame::moveAnimal(AnimalGame::TEntity *animal, ConsoleManager::Console *console)
{
    if(animal->m_ix == moveLimitX)
    {
        animal->m_ix = 0;
    }
    
    animal->m_ix += moveValueFor(animal->animalType);
    console->gotoxy(animal->m_ix, animal->m_iy);
}

void AnimalGame::drawAnimal(AnimalGame::TEntity *animal, ConsoleManager::Console *console)
{
    const char *animalEmoji;
    switch (animal->animalType)
    {
        case Horse:
            animalEmoji = "CCC";
            break;
            
        case Turtle:
            animalEmoji = "TTT";
            break;
            
        case Elephant:
            animalEmoji = "EEE";
            break;
            
        default:
            break;
    }
    
    console->draw(animalEmoji);
}
