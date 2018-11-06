//
//  WindowsConsole.hpp
//  ProjectN4
//
//  Created by pc-laptop on 10/31/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#ifndef WindowsConsole_hpp
#define WindowsConsole_hpp
#include "Console.h"
#endif

namespace ConsoleManager {
    class WindowsConsole : public ConsoleManager::Console
    {
    public:
        WindowsConsole() {};
        void gotoxy (int x, int y);
        void hidecursor (void);
        void clear ();
        void sleep ();
    };
}
