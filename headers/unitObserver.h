#pragma once

#include <string>

class UnitObserver {

public:

    virtual bool updateUnitListener(int ownerId, int oldX, int oldY, int newX, int newY) = 0;

    virtual ~UnitObserver() = default;
};