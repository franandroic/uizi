#pragma once

#include <iostream>
#include <string>

#include "cursor.h"

class Player {

public:

    Player(std::string n, Cursor *c);

private:

    std::string name;

    Cursor *cursor;

    char input;

    bool signalToQuit;

public:

    bool handleInput();

    std::string getName();

    Cursor *getCursor();

    bool getSignalToQuit();

};