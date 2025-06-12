#pragma once

#include "icon.h"

class Unit {

public:
    
    Unit(int startX, int startY);

private:

    Icon icon;

    int x;
    int y;

public:

    void move(int dx, int dy);

    void moveTo(int nx, int ny);

    Icon *getIcon();

    int getX();

    int getY();

};