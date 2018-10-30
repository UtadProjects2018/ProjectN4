//
//  Console.hpp
//  ProjectN4
//
//  Created by pc-laptop on 10/23/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#ifdef _WIN64
#include <conio.h>
#include <windows.h>
#endif

namespace ConsoleManager
{
    void gotoxy (int x, int y);
    void hidecursor (void);
    void clear ();
}
