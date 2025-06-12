#pragma once

#include <iostream>
#include <string>

#include "cursor.h"
#include "unit.h"
#include "playerObserver.h"

class Player {

public:

    Player(std::string n, Cursor *c);

private:

    std::string name;

    Cursor *cursor;

    std::vector<Unit> units;

    int activeUnitIdx;

    char input;

    bool signalToQuit;

    std::vector<PlayerObserver *> listeners;

public:

    bool handleInput();

    bool handleUnitMovement();

    std::string getName();

    Cursor *getCursor();

    std::vector<Unit> *getUnits();

    Unit *getUnit(int idx);

    int getActiveUnitIdx();

    int getNumberOfUnits();

    bool getSignalToQuit();

    void subscribePlayerListener(PlayerObserver *po);

    void notifyListeners();

};