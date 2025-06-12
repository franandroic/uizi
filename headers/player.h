#pragma once

#include <iostream>
#include <string>
#include <cmath>

#include "cursor.h"
#include "unit.h"
#include "playerObserver.h"
#include "combatObserver.h"

class Player {

public:

    Player(int i, std::string n, Cursor *c);

private:

    int id;

    std::string name;

    Cursor *cursor;

    std::vector<Unit> units;

    int activeUnitIdx;

    char input;

    bool signalToQuit;

    std::vector<PlayerObserver *> listeners;

    CombatObserver *combatListener;

public:

    bool handleInput();

    bool handleUnitAction(int action);

    std::string getName();

    Cursor *getCursor();

    std::vector<Unit> *getUnits();

    Unit *getUnit(int idx);

    int getActiveUnitIdx();

    int getNumberOfUnits();

    bool getSignalToQuit();

    int getId();

    void subscribePlayerListener(PlayerObserver *po);

    void subscribeCombatListener(CombatObserver *co);

    void damageUnit(int unitIdx, int damage);

private:

    void notifyListeners();

    bool notifyCombatListener();

    int manhattanDistance();

};