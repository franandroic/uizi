#pragma once

#include <iostream>
#include <string>

#include "cursor.h"
#include "icon.h"

class Player {

public:

    Player(std::string n, Cursor *c);

private:

    std::string name;

    Cursor *cursor;

    Icon avatar;        //For now it's an object until further development (to change into a pointer)
    
    int x, y;

    char input;

    bool signalToQuit;

    int actionsTaken;

public:

    bool handleInput();

    std::string getName();

    Cursor *getCursor();

    Icon *getAvatar();

    int getX();

    int getY();

    bool getSignalToQuit();

};