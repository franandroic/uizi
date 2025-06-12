#pragma once

#include <vector>

#include "icon.h"
#include "unitObserver.h"

class Unit {

public:
    
    Unit(int startUnitId, int startOwnerId, int startX, int startY);

    ~Unit();

private:

    int unitId;
    int ownerId;

    int health;

    Icon icon;

    int x;
    int y;

    std::vector<UnitObserver *> listeners;

public:

    void move(int dx, int dy);

    bool moveTo(int nx, int ny);

    int getId();

    Icon *getIcon();

    int getX();

    int getY();

    void subscribeUnitListener(UnitObserver *uo);

    bool takeDamage(int damage);

private:

    bool notifyListeners(int oldX, int oldY);

};