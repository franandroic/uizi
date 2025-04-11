#pragma once

#include <iostream>
#include <string>

#include "map.h"
#include "player.h"

class Zone {

public:

    Zone(Map *m, Player *p1, Player *p2);

    //~Zone();

private:

    Map *map;

    Player *player1;
    Player *player2;

    std::string printLine;
    int printIdx;
    int printLineLength;

public:

    void print();

};