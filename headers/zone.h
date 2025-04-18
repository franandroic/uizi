#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "map.h"
#include "player.h"

class Zone {

public:

    Zone(Map *m);

    //~Zone();

private:

    Map *map;

    std::vector<Player *> players;
    int activePlayerIdx;

    std::string printLine;
    int printIdx;
    int printLineLength;

public:

    void print();

    void registerPlayer(Player *p);

    void nextTurn();

};