#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "map.h"
#include "player.h"
#include "tile.h"
#include "tileX.h"
#include "playerObserver.h"

class Zone : public PlayerObserver {

public:

    Zone(Map *m);

    ~Zone();

private:

    Map *map;

    std::vector<Player *> players;
    int activePlayerIdx;

    std::vector<std::vector<Tile *>> tiles;

    std::string printString;

public:

    void print();

    void registerPlayer(Player *p);

    void nextTurn();

    void updatePlayerListener() override;

};